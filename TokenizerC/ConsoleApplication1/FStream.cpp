#include "stdafx.h"
#include "FStream.h"



void FStream_Destroy(FStream* pfStream)
{
  if (pfStream->pFile != NULL)
  {
    fclose(pfStream->pFile);
  }
  String_Destroy(&pfStream->fileName);
}

Result FStream_Init(FStream* pfStream)
{
  String_Init(&pfStream->fileName, NULL);
  pfStream->pFile = NULL;
  return RESULT_OK;
}

Result FStream_Open(FStream* pfStream,
                    const char* fileName)
{
  Result result = RESULT_FAIL;

  FILE * pFile = fopen(fileName, "r,ccs=UTF-8");
  if (pFile != NULL)
  {
    pfStream->pFile = pFile;
    result = String_Change(&pfStream->fileName,
                           fileName);
  }
  return result;
}


Result FStream_InitOpen(FStream* pfStream, const char* fileName)
{
  Result result = FStream_Init(pfStream);
  if (result == RESULT_OK)
  {
    result = FStream_Open(pfStream, fileName);
    if (result != RESULT_OK)
    {
      pfStream->pFile = NULL;
    }
  }
  return result;
}



Result FStream_Get(FStream* pfStream, wchar_t* ch)
{
  int c = fgetwc(pfStream->pFile);

  if (ferror(pfStream->pFile) != 0)
  {
    return RESULT_FAIL;
  }

  if (c == WEOF)
  {
    return RESULT_EOF;
  }
  *ch = (wchar_t)c;
  return RESULT_OK;
}

Result FStream_Unget(FStream* pfStream, wchar_t ch)
{
  int r = ungetwc(ch, pfStream->pFile);
  if (r == WEOF)
  {
  }
  return RESULT_OK;
}
