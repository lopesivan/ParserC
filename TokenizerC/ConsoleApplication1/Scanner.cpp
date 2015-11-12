
#include "stdafx.h"
#include "Scanner.h"
#include "StringEx.h"
#include "StrBuilder.h"
#include  "assert.h"
#include  "dmalloc.h"

Result StreamFileItem_InitOpen(StreamFileItem* p, const char* filename)
{
  Result result = Stream_InitOpen(&p->fstream, filename);
  p->pNext = NULL;
  return result;
}

Result StreamFileItem_InitStr(StreamFileItem* p,
                              const char* pszName,
                              const char* psz)
{
  Result result = Stream_InitStr(&p->fstream, pszName, psz);
  p->pNext = NULL;
  return result;
}


Result StreamFileItem_CreateOpen(StreamFileItem** pp,
                                 const char* fileName)
{
  Result result = RESULT_OUT_OF_MEM;
  StreamFileItem* p = (StreamFileItem*)Malloc(sizeof(StreamFileItem) * 1);
  if (p)
  {
    result = StreamFileItem_InitOpen(p, fileName);
    if (result == RESULT_OK)
    {
      *pp = p;
      p = NULL;
    }
    Free(p);
  }
  return result;
}


Result StreamFileItem_CreateStr(StreamFileItem** pp,
                                const char* name,
                                const char* psz)
{
  Result result = RESULT_OUT_OF_MEM;
  StreamFileItem* p = (StreamFileItem*)Malloc(sizeof(StreamFileItem) * 1);
  if (p)
  {
    result = StreamFileItem_InitStr(p, name, psz);
    if (result == RESULT_OK)
    {
      *pp = p;
      p = NULL;
    }
    Free(p);
  }
  return result;
}

void StreamFileItem_Destroy(StreamFileItem* p)
{
  Stream_Destroy(&p->fstream);
}

void StreamFileItem_Delete(StreamFileItem* p)
{
  if (p)
  {
    StreamFileItem_Destroy(p);
    Free(p);
  }
}

Result Scanner_InitOpen(Scanner* scanner,
                        const char* filename)
{
  scanner->ifdefCount = 0;
  scanner->bIgnoreBreakLine = true;

  scanner->pHead = NULL;
  Result result;
  do
  {

    result = MapStrToPtr_Init(&scanner->mapOnce);
    if (result == RESULT_OK)
    {
      result = MapStrToStr_Init(&scanner->mapDefines);
      if (result == RESULT_OK)
      {
        result = Scanner_Open(scanner, filename);
        if (result == RESULT_OK)
        {
          break;
        }
        MapStrToStr_Destroy(&scanner->mapDefines);
      }
      MapStrToPtr_Destroy(&scanner->mapOnce, NULL);
    }
  } while (0);


  return result;
}

Result Scanner_Close(Scanner* scanner)
{
  if (scanner->pHead)
  {
    printf("\n ------ close %s -------- \n",
           Stream_GetName(&scanner->pHead->fstream));
  }

  StreamFileItem* p = scanner->pHead;
  scanner->pHead = scanner->pHead->pNext;
  StreamFileItem_Delete(p);


  if (scanner->pHead != NULL)
  {
    printf("\n ------ continue %s -------- \n",
           Stream_GetName(&scanner->pHead->fstream));
  }
  return scanner->pHead != NULL ? RESULT_OK : RESULT_EOF;
}


Result Scanner_OpenMacro(Scanner* scanner,
                         const char* name,
                         const char* psz)
{
  printf("\n ------ macro %s -------- \n", name);

  StreamFileItem* p;
  Result result = StreamFileItem_CreateStr(&p, name, psz);

  if (result == RESULT_OK)
  {
    p->pNext = scanner->pHead;
    scanner->pHead = p;
  }

  return result;
}
Result Scanner_Open(Scanner* scanner,
                    const char* filename)
{
  void* pv;
  if (MapStrToPtr_Find(&scanner->mapOnce, filename, &pv) == RESULT_OK)
  {
    //Já foi incluido
    return RESULT_FAIL;
  }

  printf("\n ------ include %s -------- \n", filename);

  StreamFileItem* p;
  Result result = StreamFileItem_CreateOpen(&p, filename);

  if (result == RESULT_OK)
  {
    p->pNext = scanner->pHead;
    scanner->pHead = p;
  }

  return result;
}

void Scanner_Destroy(Scanner* scanner)
{
  StreamFileItem* pCurrent = scanner->pHead;
  while (pCurrent)
  {
    Stream_Destroy(&pCurrent->fstream);
    pCurrent = pCurrent->pNext;
  }

  MapStrToPtr_Destroy(&scanner->mapOnce, NULL);
  MapStrToStr_Destroy(&scanner->mapDefines);
}


static Result Scanner_NextTokenCore(Scanner* scanner,
                                    StrBuilder* lexeme,
enum PlaygroundLang_Tokens* tk)
{


  int lastGoodState = -2;
  int currentState = 0;
  wchar_t ch;
  int index = 0;

  Result r = Stream_Get(&scanner->pHead->fstream, &ch);

  while (r == RESULT_OK)
  {
    currentState = PlaygroundLang_GetNext(currentState, ch);

    if (lastGoodState == -2 &&
    currentState == -1)
    {
      ASSERT(0);
      return RESULT_FAIL;
    }

    if (currentState == -1)
    {
      Stream_Unget(&scanner->pHead->fstream, ch);
      break;
    }

    enum PlaygroundLang_Tokens tk2;

    if (PlaygroundLang_GetTokenFromState(currentState, &tk2))
    {
      *tk = tk2;
      lastGoodState = currentState;
    }

    StrBuilder_AppendWChar(lexeme, ch);
    r = Stream_Get(&scanner->pHead->fstream, &ch);
    if (r == RESULT_EOF)
    {
      r = RESULT_OK;
      break;
    }
  }


  return r;
}

static Result Scanner_NextTokentoEndOfLine(Scanner* scanner,
    StrBuilder* lexeme,
enum PlaygroundLang_Tokens* token)
{
  bool old = scanner->bIgnoreBreakLine;
  scanner->bIgnoreBreakLine = false;

  Result result;
  for (;;)
  {
    result = Scanner_NextTokenCore(scanner,
    lexeme,
    token);
    if (result != RESULT_OK)
      break;

    if (*token == TKBreakLine || *token == TKEndMark)
    {
      break;
    }

  }

  scanner->bIgnoreBreakLine = old;

  return result;
}

static Result Scanner_NextToken(Scanner* scanner,
                                StrBuilder* lexeme,
enum PlaygroundLang_Tokens* token)
{

  Result result;
  for (;;)
  {
    StrBuilder_Clear(lexeme);
    result = Scanner_NextTokenCore(scanner,
    lexeme,
    token);
    if (result != RESULT_OK)
      break;

    if (scanner->bIgnoreBreakLine)
    {
      if (*token == TKBreakLine)
      {
        continue;
      }
    }

    if (*token == TKBlanks ||
        *token == TKLINECOMMENT ||
        *token == TKCOMMENT)
    {
      continue;
    }
    else
    {
      break;
    }
  }
  return result;
}

Result Match(Scanner* scanner,
enum PlaygroundLang_Tokens expected,
enum PlaygroundLang_Tokens* token,
  StrBuilder* lexeme)
{
  if (*token != expected)
    return RESULT_FAIL;
  Result result = Scanner_NextToken(scanner,
  lexeme,
  token);
  return result;
}

static void PopChar(StrBuilder* strBuilder)
{
  ASSERT(strBuilder);
  ASSERT(strBuilder->size > 1);
  strBuilder->c_str[strBuilder->size - 1] = '\0';
  strBuilder->size--;
}

static Result Scanner_NextTokentoEndOfLine(Scanner* scanner,
    StrBuilder* lexeme,
enum PlaygroundLang_Tokens* token);


Result Parse_FileName(Scanner* scanner,
enum PlaygroundLang_Tokens* token,
  StrBuilder* lexeme)
{
  Result result = RESULT_FAIL;
  if (*token == TKSTRING)
  {
    //ignorar tudo ate o fim da linha
    PopChar(lexeme);
    result = Scanner_Open(scanner, lexeme->c_str + 1);
    //result = Match(scanner,
    //             TKSTRING,
    //           token,
    //         lexeme);
    if (result == RESULT_OK)
    {
    }
  }
  else if (*token == TKLESS_THAN_SIGN)
  {
    //ignorar tudo ate o fim da linha
    Scanner_NextTokentoEndOfLine(scanner,
                                 lexeme,
                                 token);

    //result = Match(scanner,
    //      TKLESS_THAN_SIGN,
    //     token,
    //    lexeme);


    //IFER(Parse_Path(ctx));

    //result = Match(scanner,
    //   TKGREATER_THAN_SIGN,
    //   token,
    //  lexeme);
  }
  else
  {

  }

  return result;
}


Result Parse_IfDef(Scanner* scanner,
enum PlaygroundLang_Tokens* token,
  StrBuilder* lexeme,
bool* evalResult)
{
  Result result = Match(scanner,
  TKPreIfDef,
  token,
  lexeme);

  if (result != RESULT_OK)
    return result;

  const char* pchar;
  result = MapStrToStr_Find(&scanner->mapDefines,
  lexeme->c_str,
  &pchar);

  *evalResult = result == RESULT_OK;

  return RESULT_OK;
}


Result Parse_IfNDef(Scanner* scanner,
enum PlaygroundLang_Tokens* token,
  StrBuilder* lexeme,
bool* evalResult)
{
  Result result = Match(scanner,
  TKPreIfNDef,
  token,
  lexeme);

  if (result != RESULT_OK)
    return result;

  const char* pchar;
  result = MapStrToStr_Find(&scanner->mapDefines,
  lexeme->c_str,
  &pchar);

  *evalResult = result != RESULT_OK;

  return RESULT_OK;
}

Result Parse_DefineIdentifer(Scanner* scanner,
enum PlaygroundLang_Tokens* token,
  StrBuilder* lexeme,
const char* psz)
{
  StrBuilder lexemeTemp;
  StrBuilder_Init(&lexemeTemp, 0);
  StrBuilder_Swap(&lexemeTemp, lexeme);

  
  //Result result = Match(scanner,
  //TKIdentifier,
  //token,
  //lexeme);

  Result result = Scanner_OpenMacro(scanner, lexemeTemp.c_str, psz);

  StrBuilder_Destroy(&lexemeTemp);

  if (result != RESULT_OK &&
      result != RESULT_EOF)
  {
    return result;
  }

  return result;
}

Result Parse_Include(Scanner* scanner,
enum PlaygroundLang_Tokens* token,
  StrBuilder* lexeme)
{
  Result result = Match(scanner,
  TKPreInclude,
  token,
  lexeme);

  if (result != RESULT_OK)
    return result;

  result = Parse_FileName(scanner, token, lexeme);

  return result;
}


Result Parse_Pragma(Scanner* scanner,
enum PlaygroundLang_Tokens* token,
  StrBuilder* lexeme)
{

  Result result = Match(scanner,
  TKPrePragma,
  token,
  lexeme);

  if (result != RESULT_OK)
    return result;

  if (strcmp(lexeme->c_str, "once") == 0)
  {
    FStream* pf = Stream_CastFStream(&scanner->pHead->fstream);

    if (pf)
    {
      MapStrToPtr_Set(&scanner->mapOnce,
      pf->fileName,
      0);
    }
  }

  //ignorar tudo ate o fim da linha
  result = Scanner_NextTokentoEndOfLine(scanner,
                                        lexeme,
                                        token);

  //result = Match(scanner,
  //TKIdentifier,
  //token,
  //lexeme);

  //if (result != RESULT_OK)
  // return result;



  return result;
}


Result Parse_Define(Scanner* scanner,
enum PlaygroundLang_Tokens* token,
  StrBuilder* lexeme)
{

  Result result = Match(scanner,
  TKPreDefine,
  token,
  lexeme);

  if (result != RESULT_OK)
    return result;

  StrBuilder temp;
  StrBuilder_Init(&temp, 0);
  StrBuilder_Swap(&temp, lexeme);


  //ignorar tudo ate o fim da linha
  result = Scanner_NextTokentoEndOfLine(scanner,
  lexeme,
  token);

  MapStrToStr_Set(&scanner->mapDefines,
  temp.c_str,
  lexeme->c_str);

  StrBuilder_Destroy(&temp);

  //result = Match(scanner,
  //TKIdentifier,
  //token,
  //lexeme);

  //if (result != RESULT_OK)
  // return result;



  return result;
}

Result PreIgnore(Scanner* scanner,
enum PlaygroundLang_Tokens* token,
  StrBuilder* lexeme,
bool* bElse)
{

  int count = 0;
  Result result;
  for (;;)
  {
    result = Scanner_NextTokenCore(scanner,
    lexeme,
    token);
    if (result != RESULT_OK)
      break;

    if (*token == TKPreIfDef ||
    *token == TKPreIfNDef)
    {
      count++;
    }

    if (count == 0 &&
        (*token == TKPreElse ||
         *token == TKPreEndif))
    {
      *bElse = (*token == TKPreElse);
      break;
    }
  }
  return result;
}

Result Scanner_GetTokenFinal(Scanner* scanner,
enum PlaygroundLang_Tokens* token,
  StrBuilder* lexeme)
{


  if (scanner->pHead == NULL)
    return RESULT_EOF;

  Result result;
  for (;;)
  {
    result = Scanner_NextToken(scanner,
    lexeme,
    token);


    if (result == RESULT_EOF)
    {
      result = Scanner_Close(scanner);

      //fechou todos os arquivos abertos por include
      if (result == RESULT_EOF)
      {
        //tem mais um?
        //result = RESULT_EOF;
        break;
      }
    }

    if (result != RESULT_OK)
      break;

    if (*token == TKIdentifier)
    {
      const char* psz;
      result = MapStrToStr_Find(&scanner->mapDefines,
                                    lexeme->c_str, &psz);
      if (result == RESULT_OK)
      {
        //é uma macro
        Parse_DefineIdentifer(scanner, token, lexeme, psz);
      }
      else
      {
        //não é uma macro
        result = RESULT_OK;
        break;
      }
      continue;
    }
    else if (*token == TKPrePragma)
    {
      Parse_Pragma(scanner, token, lexeme);
      continue;
    }
    if (*token == TKPreDefine)
    {
      Parse_Define(scanner, token, lexeme);
      continue;
    }
    else if (*token == TKBreakLine)
    {
      continue;
    }
    else if (*token == TKPreInclude)
    {
      Parse_Include(scanner, token, lexeme);
      continue;
    }
    else if (*token == TKPreIfNDef)
    {
      bool evalResult;
      Parse_IfNDef(scanner, token, lexeme, &evalResult);

      if (evalResult)
      {
        //é para incluir?
        scanner->ifdefCount++;
      }
      else
      {
        bool bElse;
        result = PreIgnore(scanner, token, lexeme, &bElse);
        if (result == RESULT_OK && bElse)
        {
          scanner->ifdefCount++;
        }
      }
      continue;
    }
    else if (*token == TKPreIfDef)
    {
      bool evalResult;
      Parse_IfDef(scanner, token, lexeme, &evalResult);
      if (evalResult)
      {
        //é para incluir?
        scanner->ifdefCount++;
      }
      else
      {
        bool bElse;
        result = PreIgnore(scanner, token, lexeme, &bElse);
        if (result == RESULT_OK && bElse)
        {
          scanner->ifdefCount++;
        }
      }
      continue;
    }
    else if (*token == TKPreEndif)
    {
      scanner->ifdefCount--;
      continue;
    }
    else if (*token == TKPreElse)
    {
      if (scanner->ifdefCount > 0)
      {
        //ignorar ate achar endif
        bool bElse;
        PreIgnore(scanner, token, lexeme, &bElse);
      }
      continue;
    }
    else
    {
      break;
    }
  }
  return result;
}