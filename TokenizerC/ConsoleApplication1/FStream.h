#pragma once
#include "Result.h"
#include "StringEx.h"

typedef struct
{
  FILE * pFile;
  StringC fileName;
} FStream;


void FStream_Destroy(FStream* pfStream);

Result FStream_Init(FStream* pfStream);

Result FStream_InitOpen(FStream* pfStream,
                        const char* fileName);

Result FStream_Open(FStream* pfStream,
                    const char* fileName);

Result FStream_Get(FStream* pfStream, wchar_t* ch);

Result FStream_Unget(FStream* pfStream, wchar_t ch);
