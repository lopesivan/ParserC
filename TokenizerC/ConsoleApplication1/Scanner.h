#pragma once
#include "FStream.h"
#include "StringEx.h"
#include "MapStrToPtr.h"
#include "StrBuilder.h"
#include "dfa.h"

typedef struct StreamFileItemTag
{
  FStream fstream;
  struct StreamFileItemTag* pNext;
} StreamFileItem;

Result StreamFileItem_Create(StreamFileItem** pp, const char* fileName);
void StreamFileItem_Delete(StreamFileItem* p);

typedef struct
{
  StreamFileItem* pHead;
  MapStrToPtr     mapOnce;
  MapStrToStr     mapDefines;
  bool            bIgnoreBreakLine;

  int ifdefCount;
} Scanner;


Result Scanner_Open(Scanner* scanner,
                    const char* filename);

Result Scanner_Close(Scanner* scanner);


Result Scanner_InitOpen(Scanner* scanner,
                        const char* filename);

void Scanner_Destroy(Scanner* scanner);


Result Scanner_GetTokenFinal(Scanner* scanner,
                             enum PlaygroundLang_Tokens* token,
                             StrBuilder* lexeme);