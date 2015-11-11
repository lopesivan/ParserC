#pragma once

#pragma once

#include <inttypes.h>
#include "Result.h"
#include "StringEx.h"

typedef struct MapStrToPtrNode
{
  StringC key;
  void *data;
  uint32_t hash;
} MapStrToPtrNode;


typedef struct
{
  MapStrToPtrNode** data;
  size_t size;
  size_t capacity;

} MapStrToPtrNodeArray;


typedef struct
{
  MapStrToPtrNodeArray** data;
  size_t size;
} MapStrToPtrNodeArrayArray;


typedef struct MapStrToPtr
{
  MapStrToPtrNodeArrayArray buckets;
} MapStrToPtr;

Result MapStrToPtr_Init(MapStrToPtr *map);
void MapStrToPtr_Destroy(MapStrToPtr *map, void(*pfDestroyData)(void*));

Result MapStrToPtr_Set(MapStrToPtr *map, const char*key, void *data);
Result MapStrToPtr_Find(MapStrToPtr* map, const char* key, void** pp);
Result MapStrToPtr_Delete(MapStrToPtr *map, const char* key);
Result MapStrToPtr_DeleteEx(MapStrToPtr *map, const char* key, void**pp);

typedef struct MapStrToStr
{
  MapStrToPtr map;
} MapStrToStr;

Result MapStrToStr_Init(MapStrToStr *map);
void MapStrToStr_Destroy(MapStrToStr *map);

Result MapStrToStr_Set(MapStrToStr *map, const char*key, const char *data);
Result MapStrToStr_Find(MapStrToStr* map, const char* key, const char** pp);
Result MapStrToStr_Delete(MapStrToStr *map, const char* key);
