#include "stdafx.h"
#include "MapStrToPtr.h"
#include <string.h>
#include "dmalloc.h"


/**
* Simple Bob Jenkins's hash algorithm taken from the
* wikipedia description.
*/
static uint32_t default_hash(const char* a)
{
  size_t len = strlen(a);
  const char* key = a;
  uint32_t hash = 0;
  uint32_t i = 0;

  for (hash = i = 0; i < len; ++i)
  {
    hash += key[i];
    hash += (hash << 10);
    hash ^= (hash >> 6);
  }

  hash += (hash << 3);
  hash ^= (hash >> 11);
  hash += (hash << 15);

  return hash;
}

Result MapStrToPtrNodeArray_Reserve(MapStrToPtrNodeArray* p,
                                    size_t nelements);


Result MapStrToPtrNode_Init(MapStrToPtrNode* node,
                            int hash,
                            const char* key,
                            void* data)
{
  Result result = String_Init(&node->key, key);
  node->data = data;
  node->hash = hash;
  return result;
}

Result MapStrToPtrNode_Create(MapStrToPtrNode** pp,
                              int hash,
                              const char* key,
                              void* data)
{
  Result result = RESULT_OUT_OF_MEM;
  MapStrToPtrNode* node = (MapStrToPtrNode*)Malloc(sizeof(MapStrToPtrNode) * 1);
  if (node)
  {
    MapStrToPtrNode_Init(node, hash, key, data);
    *pp = node;
    result = RESULT_OK;
  }
  return result;
}

Result MapStrToPtrNode_Change(MapStrToPtrNode* p,
                              void* data)
{
  p->data = data;
  return RESULT_OK;
}

void MapStrToPtrNode_Destroy(MapStrToPtrNode* node, 
                             void (*pfDestroyData)(void*))
{
  String_Destroy(&node->key);
  if (pfDestroyData)
  {
    pfDestroyData(node->data);
  }
}

void MapStrToPtrNode_Delete(MapStrToPtrNode* p,
                            void(*pfDestroyData)(void*))
{
  if (p)
  {
    MapStrToPtrNode_Destroy(p, pfDestroyData);
    Free(p);
  }
}

Result MapStrToPtrNodeArray_Init(MapStrToPtrNodeArray* p,
                                 size_t capacity)
{
  Result result = RESULT_OK;
  p->data = NULL;
  p->size = 0;
  p->capacity = 0;

  if (capacity > 0)
  {
    result = MapStrToPtrNodeArray_Reserve(p, capacity);
  }

  return result;
}

Result MapStrToPtrNodeArray_Create(MapStrToPtrNodeArray** pp,
                                   size_t capacity)
{
  Result result = RESULT_OUT_OF_MEM;
  MapStrToPtrNodeArray* p = (MapStrToPtrNodeArray*)Malloc(sizeof(MapStrToPtrNodeArray) * 1);
  if (p)
  {
    result = MapStrToPtrNodeArray_Init(p, 0);
    if (result == RESULT_OK)
    {
      *pp = p;
      p = NULL;
    }
    Free(p);
  }
  return result;
}


void MapStrToPtrNodeArray_Destroy(MapStrToPtrNodeArray* p,
                                  void(*pfDestroyData)(void*))
{
  for (size_t i = 0; i < p->size; i++)
  {
    MapStrToPtrNode_Delete(p->data[i], pfDestroyData);
  }
  Free(p->data);
}


void MapStrToPtrNodeArray_Delete(MapStrToPtrNodeArray* p,
                                 void(*pfDestroyData)(void*))
{
  if (p)
  {
    MapStrToPtrNodeArray_Destroy(p, pfDestroyData);
    Free(p);
  }
}


Result MapStrToPtrNodeArray_Reserve(MapStrToPtrNodeArray* p,
                                    size_t nelements)
{
  Result r = RESULT_OK;

  if (nelements > p->capacity)
  {
    MapStrToPtrNode** pnew = (MapStrToPtrNode**)Realloc(p->data,
                             (nelements + 1) * sizeof(p->data[0]));

    if (pnew)
    {
      if (p->data == NULL)
      {
        pnew[0] = '\0';
      }

      p->data = pnew;
      p->capacity = nelements;
    }
    else
    {
      r = RESULT_OUT_OF_MEM;
    }
  }

  return r;
}
static Result Grow(MapStrToPtrNodeArray* p, size_t nelements)
{
  Result r = RESULT_OK;

  if (nelements > p->capacity)
  {
    size_t new_nelements = p->capacity + p->capacity / 2;

    if (new_nelements < nelements)
    {
      new_nelements = nelements;
    }

    r = MapStrToPtrNodeArray_Reserve(p, new_nelements);
  }

  return r;
}

Result MapStrToPtrNodeArray_Append(MapStrToPtrNodeArray* p,
                                   MapStrToPtrNode* pItem)
{
  Result result = Grow(p, p->size + 1);

  if (result == RESULT_OK)
  {
    p->data[p->size] = pItem;
//    pItem = NULL;

    p->size++;    
  }

  //MapStrToPtrNode_Delete(pItem);

  return result;
}

int MapStrToPtr_FindNodeIndex(MapStrToPtrNodeArray* bucket,
                              uint32_t hash,
                              const char* key)
{
  for (size_t i = 0; i < bucket->size; i++)
  {
    MapStrToPtrNode* node = bucket->data[i];
    if (node->hash == hash &&
        strcmp(node->key, key) == 0)
    {
      return i;
    }
  }

  return -1;
}

Result MapStrToPtr_RemoveNode(MapStrToPtrNodeArray* bucket,
                              uint32_t hash,
                              const char* key,
                              void** ppData)
{
  *ppData = NULL; //out

  int index = MapStrToPtr_FindNodeIndex(bucket, hash, key);
  Result result = index != -1 ? RESULT_OK : RESULT_FAIL;
  
  if (result == RESULT_OK)
  {
    *ppData = bucket->data[bucket->size - 1]->data;

    MapStrToPtrNode* pLast = bucket->data[bucket->size - 1];
    if (index != bucket->size - 1)
    {
      bucket->data[bucket->size - 1] = bucket->data[index];
      bucket->data[index] = pLast;
    }

    MapStrToPtrNode_Delete(pLast, NULL);

    bucket->size--;
  }


  return result;
}


Result MapStrToPtrNodeArrayArray_Init(MapStrToPtrNodeArrayArray* p,
                                      size_t size)
{
  Result result = RESULT_OUT_OF_MEM;
  p->data = NULL;
  p->size = size;

  p->data = (MapStrToPtrNodeArray**)Malloc(sizeof(MapStrToPtrNodeArray*) * size);
  if (p->data)
  {
    for (size_t i = 0; i < size; i++)
    {
      p->data[i] = NULL;
    }
    result = RESULT_OK;
  }

  return result;
}

void MapStrToPtrNodeArrayArray_Destroy(MapStrToPtrNodeArrayArray* p,
                                       void(*pfDestroyData)(void*))
{
  for (size_t i = 0; i < p->size; i++)
  {
    MapStrToPtrNodeArray_Delete(p->data[i],
                                pfDestroyData);
  }
  Free(p->data);
}


Result MapStrToPtr_Init(MapStrToPtr* map)
{
  Result result = MapStrToPtrNodeArrayArray_Init(&map->buckets, 100);
  if (result == RESULT_OK)
  {
  }
  return result;
}

void MapStrToPtr_Destroy(MapStrToPtr* map,
                         void(*pfDestroyData)(void*))
{
  MapStrToPtrNodeArrayArray_Destroy(&map->buckets, pfDestroyData);
}

MapStrToPtrNode* MapStrToPtr_FindNode(MapStrToPtr* map, const char* key)
{
  uint32_t hash = default_hash(key);
  int bucket_n = hash % map->buckets.size;

  MapStrToPtrNodeArray* bucket = map->buckets.data[bucket_n];

  if (bucket == NULL)
  {
    return NULL;
  }

  int i = MapStrToPtr_FindNodeIndex(bucket, hash, key);
  if (i == -1)
  {
    return NULL;
  }


  return bucket->data[i];
}

Result MapStrToPtr_Set(MapStrToPtr* map, const char* key, void* data)
{ 
  Result result;

  MapStrToPtrNode* pNode = MapStrToPtr_FindNode(map, key);
  if (pNode)
  {
    return MapStrToPtrNode_Change(pNode, data);
  }


  uint32_t hash = default_hash(key);
  int bucket_n = hash % map->buckets.size;
  MapStrToPtrNodeArray* bucket = map->buckets.data[bucket_n];

  if (bucket == NULL)
  {
    result = MapStrToPtrNodeArray_Create(&bucket, 0);
    if (result == RESULT_OK)
    {
      map->buckets.data[bucket_n] = bucket;
    }
  }
  else
  {
    result = RESULT_OK;
  }

  if (result == RESULT_OK)
  {
    MapStrToPtrNode* node;
    Result result = MapStrToPtrNode_Create(&node, hash, key, data);
    if (result == RESULT_OK)
    {
      result = MapStrToPtrNodeArray_Append(bucket,
                                           node //moved
                                           );      
    }
  }

  return result;
}


Result MapStrToPtr_Find(MapStrToPtr* map, const char* key, void** pp)
{
  MapStrToPtrNode* pNode = MapStrToPtr_FindNode(map, key);
  Result result = pNode ? RESULT_OK: RESULT_FAIL;

  if (result == RESULT_OK)
  {
    *pp = pNode->data;
  }
  
  return result; 
}

Result MapStrToPtr_DeleteEx(MapStrToPtr *map, const char* key, void**pp)
{
  uint32_t hash = default_hash(key);
  int bucket_n = hash % map->buckets.size;

  MapStrToPtrNodeArray* bucket = map->buckets.data[bucket_n];

  if (bucket == NULL)
  {
    return RESULT_FAIL;
  }
  
  return MapStrToPtr_RemoveNode(bucket, hash, key, pp);
}

Result MapStrToPtr_Delete(MapStrToPtr* map, const char* key)
{
  void *p;
  return MapStrToPtr_DeleteEx(map, key, &p);
}


Result MapStrToStr_Init(MapStrToStr *map)
{
  return MapStrToPtr_Init(&map->map);
}

static void DeleteStringC(void*p)
{
  StringC pStr = (StringC)p;
  String_Destroy(&pStr);
}

void MapStrToStr_Destroy(MapStrToStr *map)
{
  MapStrToPtr_Destroy(&map->map, &DeleteStringC);
}

Result MapStrToStr_Set(MapStrToStr *map, const char*key, const char *data)
{
  StringC s;
  Result result = String_Init(&s, data);
  if (result == RESULT_OK)
  {
    MapStrToPtr_Set(&map->map, key, (void*)s /*moved*/);
  }
  return result;
}

Result MapStrToStr_Find(MapStrToStr* map, const char* key, const char** pp)
{
  void* p;
  Result result = MapStrToPtr_Find(&map->map, key, &p);
  if (result == RESULT_OK)
  {
    *pp = (const char*) p;
  }
  return result;
}

Result MapStrToStr_Delete(MapStrToStr *map, const char* key)
{
  void *p;
  Result result = MapStrToPtr_DeleteEx(&map->map,
                                     key,
                                     &p);
  if (result == RESULT_OK)
  {
    DeleteStringC(p);
  }
  return result;
}

