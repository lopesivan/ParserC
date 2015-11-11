

// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include "FStream.h"
#include "Scanner.h"
#include "MapStrToPtr.h"
#include "StrBuilder.h"

void BuildEnumText(Scanner* scanner,
                   const char* enumName,
                   StrBuilder* strBuilder)
{
  for (;;)
  {
    //Scanner_GetTokenFinal(scanner, &tk, &lexeme);
    //if (result == RESULT_OK)
  }
}

void PrintEnum(Scanner* scanner, const char* enumName)
{
  StrBuilder strBuilder;
  StrBuilder_Init(&strBuilder, 200);

  StrBuilder lexeme;
  StrBuilder_Init(&lexeme, 200);
  enum PlaygroundLang_Tokens tk;

  Result result = Scanner_GetTokenFinal(scanner, &tk, &lexeme);
  if (result == RESULT_OK)
  {
    if (tk == TKLEFT_CURLY_BRACKET) //{ typedef 
    {
      //andar ate char }
    }
    else if (tk == TKIdentifier) //{ typedef 
    {
      if (strcmp(enumName, lexeme.c_str) == 0)
      {

      }
    }
  }

  StrBuilder_Destroy(&lexeme);
  StrBuilder_Destroy(&strBuilder);

}

void FindEnum(Scanner* scanner, const char* enumName)
{
  //  Scanner scanner;

  StrBuilder lexeme;
  Result result = StrBuilder_Init(&lexeme, 200);


  if (result == RESULT_OK)
  {
    enum PlaygroundLang_Tokens tk;

    while (Scanner_GetTokenFinal(scanner, &tk, &lexeme) == RESULT_OK)
    {
      if (tk == TKEnum)
      {
        PrintEnum(scanner, enumName);

      }

      //wprintf(L"%*s ", 15, PlaygroundLang_Tokens_ToString(tk));
      //printf("%s\n", lexeme.c_str);
    }
    // Scanner_Destroy(&scanner);
  }
  else
  {
    //    printf("Failed to open %s\n", argv[1]);
  }

  StrBuilder_Destroy(&lexeme);
}


void PrintAllTokens(Scanner* scanner)
{
  StrBuilder lexeme;
  StrBuilder_Init(&lexeme, 200);

  enum PlaygroundLang_Tokens tk;

  while (Scanner_GetTokenFinal(scanner, &tk, &lexeme) == RESULT_OK)
  {
    wprintf(L"%*s ", 15, PlaygroundLang_Tokens_ToString(tk));
    printf("%s\n", lexeme.c_str);
  }

  StrBuilder_Destroy(&lexeme);
}

/*
 A ideia é a seguinte

*/
int main(int argc, char* argv[])
{
  Scanner scanner;

  Result result = Scanner_InitOpen(&scanner, argv[1]);
  if (result == RESULT_OK)
  {
    //FindEnum(&scanner, argv[2]);
    PrintAllTokens(&scanner);
    Scanner_Destroy(&scanner);
  }
  else
  {
    printf("Failed to open %s\n", argv[1]);
  }
  
  return 0;
}

