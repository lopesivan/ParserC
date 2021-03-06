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



///////////////////////////////////////////////////////////////////////////////


void SStream_Destroy(SStream* pfStream)
{
  String_Destroy(&pfStream->name);
}

Result SStream_Init(SStream* pfStream,
                    const char* pszName,
                    const char* psz)
{
  String_Init(&pfStream->name, pszName);
  pfStream->pCharacteres = psz;
  pfStream->pCurrentChar = pfStream->pCharacteres;
  pfStream->putBackCharacter = L'\0';
  return RESULT_OK;
}


Result SStream_Get(SStream* pfStream, wchar_t* ch)
{
  Result result;
  if (pfStream->putBackCharacter != L'\0')
  {
    *ch = pfStream->putBackCharacter;
    pfStream->putBackCharacter = L'\0';
    result = RESULT_OK;
  }
  else if (*pfStream->pCurrentChar == L'\0')
  {
      result = RESULT_EOF;
  }
  else
  {
    *ch = *pfStream->pCurrentChar;
    pfStream->pCurrentChar++;
    result = RESULT_OK;
  }
  return result;
}

Result SStream_Unget(SStream* pfStream, wchar_t ch)
{
  pfStream->putBackCharacter = ch;
  return RESULT_OK;
}





void Stream_Destroy(Stream* pfStream)
{
  if (pfStream->type == 1)
    FStream_Destroy(&pfStream->streamObj.fstream);
  else if (pfStream->type == 2)
    SStream_Destroy(&pfStream->streamObj.sstream);
}


Result Stream_InitOpen(Stream* pfStream,
                       const char* fileName)
{
  pfStream->type = 1;
  return FStream_InitOpen(&pfStream->streamObj.fstream, fileName);
}

Result Stream_InitStr(Stream* pfStream,
                      const char* pszName, 
                      const char* psz)
{
  pfStream->type = 2;
  return SStream_Init(&pfStream->streamObj.sstream, pszName, psz);
}

const char* Stream_GetName(Stream* pfStream)
{
  if (pfStream->type == 1)
    return pfStream->streamObj.fstream.fileName;

  return pfStream->streamObj.sstream.name;
}
Result Stream_Get(Stream* pfStream, wchar_t* ch)
{
  if (pfStream->type == 1)
    return FStream_Get(&pfStream->streamObj.fstream, ch);
 
  return SStream_Get(&pfStream->streamObj.sstream, ch);
}

Result Stream_Unget(Stream* pfStream, wchar_t ch)
{
  if (pfStream->type == 1)
    return FStream_Unget(&pfStream->streamObj.fstream, ch);
 
  return SStream_Unget(&pfStream->streamObj.sstream, ch);
}



FStream* Stream_CastFStream(Stream* pfStream)
{
  return pfStream->type == 1 ? &pfStream->streamObj.fstream : NULL;
}