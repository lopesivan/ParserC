#include "stdafx.h"
#include "dfa.h"
#include <assert.h>

//#include "errors.h"
#include <stdlib.h>

const wchar_t* PlaygroundLang_Tokens_ToString(enum PlaygroundLang_Tokens e)
{
  switch (e)
  {
    case TKPreInclude: return L"PreInclude";
    case TKPreDefine: return L"PreDefine";
    case TKPreLine: return L"PreLine";
    case TKPreUndef: return L"PreUndef";
    case TKPreError: return L"PreError";
    case TKPrePragma: return L"PrePragma";
    case TKPreIf: return L"PreIf";
    case TKPreIfDef: return L"PreIfDef";
    case TKPreIfNDef: return L"PreIfNDef";
    case TKPreElse: return L"PreElse";
    case TKPreEndif: return L"PreEndif";
    case TKPreElif: return L"PreElif";
    case TKEllipsis: return L"Ellipsis";
    case TKRightAssign: return L"RightAssign";
    case TKLeftAssign: return L"LeftAssign";
    case TKAddAssign: return L"AddAssign";
    case TKSubAssign: return L"SubAssign";
    case TKMultAssign: return L"MultAssign";
    case TKDivAssign: return L"DivAssign";
    case TKModAssign: return L"ModAssign";
    case TKAndAssign: return L"AndAssign";
    case TKXorAssign: return L"XorAssign";
    case TKOrAssign: return L"OrAssign";
    case TKRightOp: return L"RightOp";
    case TKLeftOp: return L"LeftOp";
    case TKIncOp: return L"IncOp";
    case TKDecOp: return L"DecOp";
    case TKPtrOp: return L"PtrOp";
    case TKAndOp: return L"AndOp";
    case TKOrOp: return L"OrOp";
    case TKLeOp: return L"LeOp";
    case TKGeOp: return L"GeOp";
    case TKEqOp: return L"EqOp";
    case TKNeOp: return L"NeOp";
    case TKEXCLAMATION_MARK: return L"EXCLAMATION_MARK";
    case TKQUOTATION_MARK: return L"QUOTATION_MARK";
    case TKDOLLAR_SIGN: return L"DOLLAR_SIGN";
    case TKPERCENT_SIGN: return L"PERCENT_SIGN";
    case TKAMPERSAND: return L"AMPERSAND";
    case TKAPOSTROPHE: return L"APOSTROPHE";
    case TKLEFT_PARENTHESIS: return L"LEFT_PARENTHESIS";
    case TKRIGHT_PARENTHESIS: return L"RIGHT_PARENTHESIS";
    case TKASTERISK: return L"ASTERISK";
    case TKPLUS_SIGN: return L"PLUS_SIGN";
    case TKCOMMA: return L"COMMA";
    case TKHYPHEN_MINUS: return L"HYPHEN_MINUS";
    case TKFULL_STOP: return L"FULL_STOP";
    case TKSOLIDUS: return L"SOLIDUS";
    case TKCOLON: return L"COLON";
    case TKSEMICOLON: return L"SEMICOLON";
    case TKLESS_THAN_SIGN: return L"LESS_THAN_SIGN";
    case TKEQUALS_SIGN: return L"EQUALS_SIGN";
    case TKGREATER_THAN_SIGN: return L"GREATER_THAN_SIGN";
    case TKQUESTION_MARK: return L"QUESTION_MARK";
    case TKCOMMERCIAL_AT: return L"COMMERCIAL_AT";
    case TKLEFT_SQUARE_BRACKET: return L"LEFT_SQUARE_BRACKET";
    case TKREVERSE_SOLIDUS: return L"REVERSE_SOLIDUS";
    case TKRIGHT_SQUARE_BRACKET: return L"RIGHT_SQUARE_BRACKET";
    case TKCIRCUMFLEX_ACCENT: return L"CIRCUMFLEX_ACCENT";
    case TKLOW_LINE: return L"LOW_LINE";
    case TKGRAVE_ACCENT: return L"GRAVE_ACCENT";
    case TKLEFT_CURLY_BRACKET: return L"LEFT_CURLY_BRACKET";
    case TKVERTICAL_LINE: return L"VERTICAL_LINE";
    case TKRIGHT_CURLY_BRACKET: return L"RIGHT_CURLY_BRACKET";
    case TKLINECOMMENT: return L"LINECOMMENT";
    case TKCOMMENT: return L"COMMENT";
    case TKCHAR: return L"CHAR";
    case TKSTRING: return L"STRING";
    case TKNUMBER: return L"NUMBER";
    case TKBlanks: return L"Blanks";
    case TKBreakLine: return L"BreakLine";
    case TKNotBreakLine: return L"NotBreakLine";
    case TKEndMark: return L"EndMark";
    case TKAuto: return L"Auto";
    case TKBreak: return L"Break";
    case TKCase: return L"Case";
    case TKChar: return L"Char";
    case TKConst: return L"Const";
    case TKContinue: return L"Continue";
    case TKDefault: return L"Default";
    case TKDo: return L"Do";
    case TKDouble: return L"Double";
    case TKElse: return L"Else";
    case TKEnum: return L"Enum";
    case TKExtern: return L"Extern";
    case TKFloat: return L"Float";
    case TKFor: return L"For";
    case TKGoto: return L"Goto";
    case TKIf: return L"If";
    case TKInline: return L"Inline";
    case TKInt: return L"Int";
    case TKLong: return L"Long";
    case TKRegister: return L"Register";
    case TKRestrict: return L"Restrict";
    case TKReturn: return L"Return";
    case TKShort: return L"Short";
    case TKSigned: return L"Signed";
    case TKSizeOf: return L"SizeOf";
    case TKStatic: return L"Static";
    case TKStruct: return L"Struct";
    case TKSwitch: return L"Switch";
    case TKTypedef: return L"Typedef";
    case TKUnion: return L"Union";
    case TKUnsigned: return L"Unsigned";
    case TKVoid: return L"Void";
    case TKVolatile: return L"Volatile";
    case TKWhile: return L"While";
    case TKAlignAs: return L"AlignAs";
    case TKAlignOf: return L"AlignOf";
    case TKAtomic: return L"Atomic";
    case TKBool: return L"Bool";
    case TKComplex: return L"Complex";
    case TKGeneric: return L"Generic";
    case TKImaginary: return L"Imaginary";
    case TKNoReturn: return L"NoReturn";
    case TKStaticAssert: return L"StaticAssert";
    case TKThreadLocal: return L"ThreadLocal";
    case TKFunc: return L"Func";
    case TKNumber: return L"Number";
    case TKIdentifier: return L"Identifier";
    default:break;
  }
  return L"";
}

int PlaygroundLang_GetNext(int state, wchar_t ch)
{
  switch (state)
  {
    case 0:
    if (ch == L'\0')
      return 1;
    else if (ch == L'\t')
      return 2;
    else if (ch == L'\n')
      return 3;
    else if (ch == L'\r')
      return 4;
    else if (ch == L' ')
      return 2;
    else if (ch == L'!')
      return 5;
    else if (ch == L'"')
      return 6;
    else if (ch == L'#')
      return 7;
    else if (ch == L'$')
      return 8;
    else if (ch == L'%')
      return 9;
    else if (ch == L'&')
      return 10;
    else if (ch == L'\'')
      return 11;
    else if (ch == L'(')
      return 12;
    else if (ch == L')')
      return 13;
    else if (ch == L'*')
      return 14;
    else if (ch == L'+')
      return 15;
    else if (ch == L',')
      return 16;
    else if (ch == L'-')
      return 17;
    else if (ch == L'.')
      return 18;
    else if (ch == L'/')
      return 19;
    else if (ch >= L'0' && ch <= L'9')
      return 20;
    else if (ch == L':')
      return 21;
    else if (ch == L';')
      return 22;
    else if (ch == L'<')
      return 23;
    else if (ch == L'=')
      return 24;
    else if (ch == L'>')
      return 25;
    else if (ch == L'?')
      return 26;
    else if (ch == L'@')
      return 27;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'[')
      return 29;
    else if (ch == L'\\')
      return 30;
    else if (ch == L']')
      return 31;
    else if (ch == L'^')
      return 32;
    else if (ch == L'_')
      return 33;
    else if (ch == L'`')
      return 34;
    else if (ch == L'a')
      return 35;
    else if (ch == L'b')
      return 36;
    else if (ch == L'c')
      return 37;
    else if (ch == L'd')
      return 38;
    else if (ch == L'e')
      return 39;
    else if (ch == L'f')
      return 40;
    else if (ch == L'g')
      return 41;
    else if (ch == L'h')
      return 28;
    else if (ch == L'i')
      return 42;
    else if (ch >= L'j' && ch <= L'k')
      return 28;
    else if (ch == L'l')
      return 43;
    else if (ch >= L'm' && ch <= L'q')
      return 28;
    else if (ch == L'r')
      return 44;
    else if (ch == L's')
      return 45;
    else if (ch == L't')
      return 46;
    else if (ch == L'u')
      return 47;
    else if (ch == L'v')
      return 48;
    else if (ch == L'w')
      return 49;
    else if (ch >= L'x' && ch <= L'z')
      return 28;
    else if (ch == L'{')
      return 50;
    else if (ch == L'|')
      return 51;
    if (ch == L'}')
      return 52;
    break;
    case 1:
    /* end state for TKEndMark*/
    break;
    case 2:
    if (ch == L'\t')
      return 2;
    else if (ch == L' ')
      return 2;
    /* end state for TKBlanks*/
    break;
    case 3:
    /* end state for TKBreakLine*/
    break;
    case 4:
    if (ch == L'\n')
      return 3;
    break;
    case 5:
    if (ch == L'=')
      return 54;
    /* end state for TKEXCLAMATION_MARK*/
    break;
    case 6:
    if (ch >= L' ' && ch <= L'!')
      return 55;
    else if (ch == L'"')
      return 56;
    else if (ch >= L'#' && ch <= L'[')
      return 55;
    else if (ch == L'\\')
      return 57;
    else if (ch >= L']' /*&& ch <= L'\u00ff'*/)
      return 55;
    /* end state for TKQUOTATION_MARK*/
    break;
    case 7:
    if (ch == L'd')
      return 58;
    else if (ch == L'e')
      return 59;
    else if (ch == L'i')
      return 60;
    else if (ch == L'l')
      return 61;
    else if (ch == L'p')
      return 62;
    if (ch == L'u')
      return 63;
    break;
    case 8:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKDOLLAR_SIGN*/
    /* end state for TKDOLLAR_SIGN*/
    break;
    case 9:
    if (ch == L'=')
      return 65;
    /* end state for TKPERCENT_SIGN*/
    break;
    case 10:
    if (ch == L'&')
      return 66;
    else if (ch == L'=')
      return 67;
    /* end state for TKAMPERSAND*/
    break;
    case 11:
    if (ch >= L' ' && ch <= L'&')
      return 68;
    else if (ch == L'\'')
      return 69;
    else if (ch >= L'(' && ch <= L'[')
      return 68;
    else if (ch == L'\\')
      return 70;
    else if (ch >= L']' /*&& ch <= L'\u00ff'*/)
      return 68;
    /* end state for TKAPOSTROPHE*/
    break;
    case 12:
    /* end state for TKLEFT_PARENTHESIS*/
    break;
    case 13:
    /* end state for TKRIGHT_PARENTHESIS*/
    break;
    case 14:
    if (ch == L'=')
      return 71;
    /* end state for TKASTERISK*/
    break;
    case 15:
    if (ch == L'+')
      return 72;
    else if (ch >= L'0' && ch <= L'9')
      return 73;
    else if (ch == L'=')
      return 74;
    /* end state for TKPLUS_SIGN*/
    break;
    case 16:
    /* end state for TKCOMMA*/
    break;
    case 17:
    if (ch == L'-')
      return 75;
    else if (ch >= L'0' && ch <= L'9')
      return 73;
    else if (ch == L'=')
      return 76;
    else if (ch == L'>')
      return 77;
    /* end state for TKHYPHEN_MINUS*/
    break;
    case 18:
    if (ch == L'.')
      return 78;
    /* end state for TKFULL_STOP*/
    break;
    case 19:
    if (ch == L'*')
      return 79;
    else if (ch == L'/')
      return 80;
    else if (ch == L'=')
      return 81;
    /* end state for TKSOLIDUS*/
    break;
    case 20:
    if (ch == L'.')
      return 82;
    else if (ch >= L'0' && ch <= L'9')
      return 20;
    else if (ch == L'E')
      return 83;
    else if (ch == L'e')
      return 83;
    /*TKNUMBER*/
    /* end state for TKNUMBER*/
    break;
    case 21:
    /* end state for TKCOLON*/
    break;
    case 22:
    /* end state for TKSEMICOLON*/
    break;
    case 23:
    if (ch == L'<')
      return 84;
    else if (ch == L'=')
      return 85;
    /* end state for TKLESS_THAN_SIGN*/
    break;
    case 24:
    if (ch == L'=')
      return 86;
    /* end state for TKEQUALS_SIGN*/
    break;
    case 25:
    if (ch == L'=')
      return 87;
    else if (ch == L'>')
      return 88;
    /* end state for TKGREATER_THAN_SIGN*/
    break;
    case 26:
    /* end state for TKQUESTION_MARK*/
    break;
    case 27:
    /* end state for TKCOMMERCIAL_AT*/
    break;
    case 28:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 29:
    /* end state for TKLEFT_SQUARE_BRACKET*/
    break;
    case 30:
    if (ch == L'\n')
      return 89;
    else if (ch == L'\r')
      return 90;
    /* end state for TKREVERSE_SOLIDUS*/
    break;
    case 31:
    /* end state for TKRIGHT_SQUARE_BRACKET*/
    break;
    case 32:
    if (ch == L'=')
      return 91;
    /* end state for TKCIRCUMFLEX_ACCENT*/
    break;
    case 33:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch == L'A')
      return 92;
    else if (ch == L'B')
      return 93;
    else if (ch == L'C')
      return 94;
    else if (ch >= L'D' && ch <= L'F')
      return 28;
    else if (ch == L'G')
      return 95;
    else if (ch == L'H')
      return 28;
    else if (ch == L'I')
      return 96;
    else if (ch >= L'J' && ch <= L'M')
      return 28;
    else if (ch == L'N')
      return 97;
    else if (ch >= L'O' && ch <= L'R')
      return 28;
    else if (ch == L'S')
      return 98;
    else if (ch == L'T')
      return 99;
    else if (ch >= L'U' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 100;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKLOW_LINE*/
    /* end state for TKLOW_LINE*/
    break;
    case 34:
    /* end state for TKGRAVE_ACCENT*/
    break;
    case 35:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L't')
      return 28;
    else if (ch == L'u')
      return 101;
    else if (ch >= L'v' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 36:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'q')
      return 28;
    else if (ch == L'r')
      return 102;
    else if (ch >= L's' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 37:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch == L'a')
      return 103;
    else if (ch >= L'b' && ch <= L'g')
      return 28;
    else if (ch == L'h')
      return 104;
    else if (ch >= L'i' && ch <= L'n')
      return 28;
    else if (ch == L'o')
      return 105;
    else if (ch >= L'p' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 38:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 106;
    else if (ch >= L'f' && ch <= L'n')
      return 28;
    else if (ch == L'o')
      return 107;
    else if (ch >= L'p' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 39:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'k')
      return 28;
    else if (ch == L'l')
      return 108;
    else if (ch == L'm')
      return 28;
    else if (ch == L'n')
      return 109;
    else if (ch >= L'o' && ch <= L'w')
      return 28;
    else if (ch == L'x')
      return 110;
    else if (ch >= L'y' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 40:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'k')
      return 28;
    else if (ch == L'l')
      return 111;
    else if (ch >= L'm' && ch <= L'n')
      return 28;
    else if (ch == L'o')
      return 112;
    else if (ch >= L'p' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 41:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'n')
      return 28;
    else if (ch == L'o')
      return 113;
    else if (ch >= L'p' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 42:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'e')
      return 28;
    else if (ch == L'f')
      return 114;
    else if (ch >= L'g' && ch <= L'm')
      return 28;
    else if (ch == L'n')
      return 115;
    else if (ch >= L'o' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 43:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'n')
      return 28;
    else if (ch == L'o')
      return 116;
    else if (ch >= L'p' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 44:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 117;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 45:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'g')
      return 28;
    else if (ch == L'h')
      return 118;
    else if (ch == L'i')
      return 119;
    else if (ch >= L'j' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 120;
    else if (ch >= L'u' && ch <= L'v')
      return 28;
    else if (ch == L'w')
      return 121;
    else if (ch >= L'x' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 46:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'x')
      return 28;
    else if (ch == L'y')
      return 122;
    else if (ch == L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 47:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'm')
      return 28;
    else if (ch == L'n')
      return 123;
    else if (ch >= L'o' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 48:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'n')
      return 28;
    else if (ch == L'o')
      return 124;
    else if (ch >= L'p' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 49:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'g')
      return 28;
    else if (ch == L'h')
      return 125;
    else if (ch >= L'i' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 50:
    /* end state for TKLEFT_CURLY_BRACKET*/
    break;
    case 51:
    if (ch == L'=')
      return 126;
    else if (ch == L'|')
      return 127;
    /* end state for TKVERTICAL_LINE*/
    break;
    case 52:
    /* end state for TKRIGHT_CURLY_BRACKET*/
    break;
    case 53:
    return -1;
    break;
    case 54:
    /* end state for TKNeOp*/
    break;
    case 55:
    if (ch >= L' ' && ch <= L'!')
      return 55;
    else if (ch == L'"')
      return 56;
    else if (ch >= L'#' && ch <= L'[')
      return 55;
    else if (ch == L'\\')
      return 57;
    else if (ch >= L']' /*&& ch <= L'\u00ff'*/)
      return 55;
    break;
    case 56:
    /* end state for TKSTRING*/
    break;
    case 57:
    if (ch == L'"')
      return 55;
    else if (ch == L'/')
      return 55;
    else if (ch == L'\\')
      return 55;
    else if (ch == L'b')
      return 55;
    else if (ch == L'f')
      return 55;
    else if (ch == L'n')
      return 55;
    else if (ch == L'r')
      return 55;
    else if (ch == L't')
      return 55;
    if (ch == L'u')
      return 128;
    break;
    case 58:
    if (ch == L'e')
      return 129;
    break;
    case 59:
    if (ch == L'l')
      return 130;
    else if (ch == L'n')
      return 131;
    if (ch == L'r')
      return 132;
    break;
    case 60:
    if (ch == L'f')
      return 133;
    if (ch == L'n')
      return 134;
    break;
    case 61:
    if (ch == L'i')
      return 135;
    break;
    case 62:
    if (ch == L'r')
      return 136;
    break;
    case 63:
    if (ch == L'n')
      return 137;
    break;
    case 64:
    if (ch == L'$')
      return 138;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 138;
    else if (ch == L'_')
      return 138;
    else if (ch >= L'a' && ch <= L'z')
      return 138;
    break;
    case 65:
    /* end state for TKModAssign*/
    break;
    case 66:
    /* end state for TKAndOp*/
    break;
    case 67:
    /* end state for TKAndAssign*/
    break;
    case 68:
    if (ch >= L' ' && ch <= L'&')
      return 68;
    else if (ch == L'\'')
      return 69;
    else if (ch >= L'(' && ch <= L'[')
      return 68;
    else if (ch == L'\\')
      return 70;
    else if (ch >= L']' /*&& ch <= L'\u00ff'*/)
      return 68;
    break;
    case 69:
    /* end state for TKCHAR*/
    break;
    case 70:
    if (ch == L'\'')
      return 68;
    else if (ch >= L'/' && ch <= L'0')
      return 68;
    else if (ch == L'\\')
      return 68;
    else if (ch == L'b')
      return 68;
    else if (ch == L'f')
      return 68;
    else if (ch == L'n')
      return 68;
    else if (ch == L'r')
      return 68;
    else if (ch == L't')
      return 68;
    if (ch == L'u')
      return 139;
    break;
    case 71:
    /* end state for TKMultAssign*/
    break;
    case 72:
    /* end state for TKIncOp*/
    break;
    case 73:
    if (ch == L'.')
      return 140;
    else if (ch >= L'0' && ch <= L'9')
      return 73;
    else if (ch == L'E')
      return 83;
    else if (ch == L'e')
      return 83;
    /* end state for TKNumber*/
    break;
    case 74:
    /* end state for TKAddAssign*/
    break;
    case 75:
    /* end state for TKDecOp*/
    break;
    case 76:
    /* end state for TKSubAssign*/
    break;
    case 77:
    /* end state for TKPtrOp*/
    break;
    case 78:
    if (ch == L'.')
      return 141;
    break;
    case 79:
    if (ch >= L'\t' && ch <= L'\n')
      return 79;
    else if (ch == L'\r')
      return 79;
    else if (ch >= L' ' && ch <= L')')
      return 79;
    else if (ch == L'*')
      return 142;
    else if (ch >= L'+' /*&& ch <= L'\u00ff'*/)
      return 79;
    break;
    case 80:
    if (ch == L'\0')
      return 143;
    else if (ch == L'\n')
      return 143;
    else if (ch == L'\r')
      return 144;
    else if (ch >= L' ' && ch <= L'-')
      return 145;
    else if (ch >= L'/' /*&& ch <= L'\u00ff'*/)
      return 145;
    break;
    case 81:
    /* end state for TKDivAssign*/
    break;
    case 82:
    if (ch >= L'0' && ch <= L'9')
      return 146;
    break;
    case 83:
    if (ch == L'+')
      return 147;
    else if (ch == L'-')
      return 147;
    else if (ch >= L'0' && ch <= L'9')
      return 148;
    break;
    case 84:
    if (ch == L'=')
      return 149;
    /* end state for TKLeftOp*/
    break;
    case 85:
    /* end state for TKLeOp*/
    break;
    case 86:
    /* end state for TKEqOp*/
    break;
    case 87:
    /* end state for TKGeOp*/
    break;
    case 88:
    if (ch == L'=')
      return 150;
    /* end state for TKRightOp*/
    break;
    case 89:
    /* end state for TKNotBreakLine*/
    break;
    case 90:
    if (ch == L'\n')
      return 89;
    break;
    case 91:
    /* end state for TKXorAssign*/
    break;
    case 92:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'k')
      return 28;
    else if (ch == L'l')
      return 151;
    else if (ch >= L'm' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 152;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 93:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'n')
      return 28;
    else if (ch == L'o')
      return 153;
    else if (ch >= L'p' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 94:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'n')
      return 28;
    else if (ch == L'o')
      return 154;
    else if (ch >= L'p' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 95:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 155;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 96:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'l')
      return 28;
    else if (ch == L'm')
      return 156;
    else if (ch >= L'n' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 97:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'n')
      return 28;
    else if (ch == L'o')
      return 157;
    else if (ch >= L'p' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 98:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 158;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 99:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'g')
      return 28;
    else if (ch == L'h')
      return 159;
    else if (ch >= L'i' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 100:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'e')
      return 28;
    else if (ch == L'f')
      return 160;
    else if (ch >= L'g' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 101:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 161;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 102:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 162;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 103:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'r')
      return 28;
    else if (ch == L's')
      return 163;
    else if (ch >= L't' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 104:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch == L'a')
      return 164;
    else if (ch >= L'b' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 105:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'm')
      return 28;
    else if (ch == L'n')
      return 165;
    else if (ch >= L'o' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 106:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'e')
      return 28;
    else if (ch == L'f')
      return 166;
    else if (ch >= L'g' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 107:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L't')
      return 28;
    else if (ch == L'u')
      return 167;
    else if (ch >= L'v' && ch <= L'z')
      return 28;
    /*TKDo*/
    /* end state for TKDo*/
    break;
    case 108:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'r')
      return 28;
    else if (ch == L's')
      return 168;
    else if (ch >= L't' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 109:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L't')
      return 28;
    else if (ch == L'u')
      return 169;
    else if (ch >= L'v' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 110:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 170;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 111:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'n')
      return 28;
    else if (ch == L'o')
      return 171;
    else if (ch >= L'p' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 112:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'q')
      return 28;
    else if (ch == L'r')
      return 172;
    else if (ch >= L's' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 113:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 173;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 114:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKIf*/
    /* end state for TKIf*/
    break;
    case 115:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'k')
      return 28;
    else if (ch == L'l')
      return 174;
    else if (ch >= L'm' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 175;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 116:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'm')
      return 28;
    else if (ch == L'n')
      return 176;
    else if (ch >= L'o' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 117:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'f')
      return 28;
    else if (ch == L'g')
      return 177;
    else if (ch >= L'h' && ch <= L'r')
      return 28;
    else if (ch == L's')
      return 178;
    else if (ch == L't')
      return 179;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 118:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'n')
      return 28;
    else if (ch == L'o')
      return 180;
    else if (ch >= L'p' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 119:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'f')
      return 28;
    else if (ch == L'g')
      return 181;
    else if (ch >= L'h' && ch <= L'y')
      return 28;
    else if (ch == L'z')
      return 182;
    /* end state for TKIdentifier*/
    break;
    case 120:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch == L'a')
      return 183;
    else if (ch >= L'b' && ch <= L'q')
      return 28;
    else if (ch == L'r')
      return 184;
    else if (ch >= L's' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 121:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'h')
      return 28;
    else if (ch == L'i')
      return 185;
    else if (ch >= L'j' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 122:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'o')
      return 28;
    else if (ch == L'p')
      return 186;
    else if (ch >= L'q' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 123:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'h')
      return 28;
    else if (ch == L'i')
      return 187;
    else if (ch >= L'j' && ch <= L'r')
      return 28;
    else if (ch == L's')
      return 188;
    else if (ch >= L't' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 124:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'h')
      return 28;
    else if (ch == L'i')
      return 189;
    else if (ch >= L'j' && ch <= L'k')
      return 28;
    else if (ch == L'l')
      return 190;
    else if (ch >= L'm' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 125:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'h')
      return 28;
    else if (ch == L'i')
      return 191;
    else if (ch >= L'j' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 126:
    /* end state for TKOrAssign*/
    break;
    case 127:
    /* end state for TKOrOp*/
    break;
    case 128:
    if (ch >= L'0' && ch <= L'9')
      return 192;
    else if (ch >= L'A' && ch <= L'F')
      return 192;
    else if (ch >= L'a' && ch <= L'f')
      return 192;
    break;
    case 129:
    if (ch == L'f')
      return 193;
    break;
    case 130:
    if (ch == L'i')
      return 194;
    if (ch == L's')
      return 195;
    break;
    case 131:
    if (ch == L'd')
      return 196;
    break;
    case 132:
    if (ch == L'r')
      return 197;
    break;
    case 133:
    if (ch == L'd')
      return 198;
    else if (ch == L'n')
      return 199;
    /* end state for TKPreIf*/
    break;
    case 134:
    if (ch == L'c')
      return 200;
    break;
    case 135:
    if (ch == L'n')
      return 201;
    break;
    case 136:
    if (ch == L'a')
      return 202;
    break;
    case 137:
    if (ch == L'd')
      return 203;
    break;
    case 138:
    if (ch == L'$')
      return 138;
    else if (ch >= L'A' && ch <= L'Z')
      return 138;
    else if (ch == L'_')
      return 138;
    else if (ch >= L'a' && ch <= L'z')
      return 138;
    /* end state for TKIdentifier*/
    break;
    case 139:
    if (ch >= L'0' && ch <= L'9')
      return 204;
    else if (ch >= L'A' && ch <= L'F')
      return 204;
    else if (ch >= L'a' && ch <= L'f')
      return 204;
    break;
    case 140:
    if (ch >= L'0' && ch <= L'9')
      return 205;
    break;
    case 141:
    /* end state for TKEllipsis*/
    break;
    case 142:
    if (ch >= L'\t' && ch <= L'\n')
      return 79;
    else if (ch == L'\r')
      return 79;
    else if (ch >= L' ' && ch <= L'.')
      return 79;
    else if (ch == L'/')
      return 206;
    else if (ch >= L'0' /*&& ch <= L'\u00ff'*/)
      return 79;
    break;
    case 143:
    /* end state for TKLINECOMMENT*/
    break;
    case 144:
    if (ch == L'\n')
      return 143;
    break;
    case 145:
    if (ch == L'\0')
      return 143;
    else if (ch == L'\n')
      return 143;
    else if (ch == L'\r')
      return 144;
    else if (ch >= L' ' /*&& ch <= L'\u00ff'*/)
      return 145;
    break;
    case 146:
    if (ch >= L'0' && ch <= L'9')
      return 207;
    else if (ch == L'E')
      return 83;
    else if (ch == L'e')
      return 83;
    /*TKNUMBER*/
    /* end state for TKNUMBER*/
    break;
    case 147:
    if (ch >= L'0' && ch <= L'9')
      return 148;
    break;
    case 148:
    /* end state for TKNumber*/
    break;
    case 149:
    /* end state for TKLeftAssign*/
    break;
    case 150:
    /* end state for TKRightAssign*/
    break;
    case 151:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'h')
      return 28;
    else if (ch == L'i')
      return 208;
    else if (ch >= L'j' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 152:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'n')
      return 28;
    else if (ch == L'o')
      return 209;
    else if (ch >= L'p' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 153:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'n')
      return 28;
    else if (ch == L'o')
      return 210;
    else if (ch >= L'p' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 154:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'l')
      return 28;
    else if (ch == L'm')
      return 211;
    else if (ch >= L'n' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 155:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'm')
      return 28;
    else if (ch == L'n')
      return 212;
    else if (ch >= L'o' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 156:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch == L'a')
      return 213;
    else if (ch >= L'b' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 157:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'q')
      return 28;
    else if (ch == L'r')
      return 214;
    else if (ch >= L's' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 158:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch == L'a')
      return 215;
    else if (ch >= L'b' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 159:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'q')
      return 28;
    else if (ch == L'r')
      return 216;
    else if (ch >= L's' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 160:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L't')
      return 28;
    else if (ch == L'u')
      return 217;
    else if (ch >= L'v' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 161:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'n')
      return 28;
    else if (ch == L'o')
      return 218;
    else if (ch >= L'p' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 162:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch == L'a')
      return 219;
    else if (ch >= L'b' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 163:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 220;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 164:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'q')
      return 28;
    else if (ch == L'r')
      return 221;
    else if (ch >= L's' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 165:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'r')
      return 28;
    else if (ch == L's')
      return 222;
    else if (ch == L't')
      return 223;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 166:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch == L'a')
      return 224;
    else if (ch >= L'b' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 167:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch == L'a')
      return 28;
    else if (ch == L'b')
      return 225;
    else if (ch >= L'c' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 168:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 226;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 169:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'l')
      return 28;
    else if (ch == L'm')
      return 227;
    else if (ch >= L'n' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 170:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 228;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 171:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch == L'a')
      return 229;
    else if (ch >= L'b' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 172:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKFor*/
    /* end state for TKFor*/
    break;
    case 173:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'n')
      return 28;
    else if (ch == L'o')
      return 230;
    else if (ch >= L'p' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 174:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'h')
      return 28;
    else if (ch == L'i')
      return 231;
    else if (ch >= L'j' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 175:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKInt*/
    /* end state for TKInt*/
    break;
    case 176:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'f')
      return 28;
    else if (ch == L'g')
      return 232;
    else if (ch >= L'h' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 177:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'h')
      return 28;
    else if (ch == L'i')
      return 233;
    else if (ch >= L'j' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 178:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 234;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 179:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L't')
      return 28;
    else if (ch == L'u')
      return 235;
    else if (ch >= L'v' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 180:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'q')
      return 28;
    else if (ch == L'r')
      return 236;
    else if (ch >= L's' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 181:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'm')
      return 28;
    else if (ch == L'n')
      return 237;
    else if (ch >= L'o' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 182:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 238;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 183:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 239;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 184:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L't')
      return 28;
    else if (ch == L'u')
      return 240;
    else if (ch >= L'v' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 185:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 241;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 186:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 242;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 187:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'n')
      return 28;
    else if (ch == L'o')
      return 243;
    else if (ch >= L'p' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 188:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'h')
      return 28;
    else if (ch == L'i')
      return 244;
    else if (ch >= L'j' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 189:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'c')
      return 28;
    else if (ch == L'd')
      return 245;
    else if (ch >= L'e' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 190:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch == L'a')
      return 246;
    else if (ch >= L'b' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 191:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'k')
      return 28;
    else if (ch == L'l')
      return 247;
    else if (ch >= L'm' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 192:
    if (ch >= L'0' && ch <= L'9')
      return 248;
    else if (ch >= L'A' && ch <= L'F')
      return 248;
    else if (ch >= L'a' && ch <= L'f')
      return 248;
    break;
    case 193:
    if (ch == L'i')
      return 249;
    break;
    case 194:
    if (ch == L'f')
      return 250;
    break;
    case 195:
    if (ch == L'e')
      return 251;
    break;
    case 196:
    if (ch == L'i')
      return 252;
    break;
    case 197:
    if (ch == L'o')
      return 253;
    break;
    case 198:
    if (ch == L'e')
      return 254;
    break;
    case 199:
    if (ch == L'd')
      return 255;
    break;
    case 200:
    if (ch == L'l')
      return 256;
    break;
    case 201:
    if (ch == L'e')
      return 257;
    break;
    case 202:
    if (ch == L'g')
      return 258;
    break;
    case 203:
    if (ch == L'e')
      return 259;
    break;
    case 204:
    if (ch >= L'0' && ch <= L'9')
      return 260;
    else if (ch >= L'A' && ch <= L'F')
      return 260;
    else if (ch >= L'a' && ch <= L'f')
      return 260;
    break;
    case 205:
    if (ch == L'E')
      return 83;
    else if (ch == L'e')
      return 83;
    /* end state for TKNumber*/
    break;
    case 206:
    /* end state for TKCOMMENT*/
    break;
    case 207:
    if (ch >= L'0' && ch <= L'9')
      return 207;
    /* end state for TKNUMBER*/
    break;
    case 208:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'f')
      return 28;
    else if (ch == L'g')
      return 261;
    else if (ch >= L'h' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 209:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'l')
      return 28;
    else if (ch == L'm')
      return 262;
    else if (ch >= L'n' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 210:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'k')
      return 28;
    else if (ch == L'l')
      return 263;
    else if (ch >= L'm' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 211:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'o')
      return 28;
    else if (ch == L'p')
      return 264;
    else if (ch >= L'q' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 212:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 265;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 213:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'f')
      return 28;
    else if (ch == L'g')
      return 266;
    else if (ch >= L'h' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 214:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 267;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 215:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 268;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 216:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 269;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 217:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'm')
      return 28;
    else if (ch == L'n')
      return 270;
    else if (ch >= L'o' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 218:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKAuto*/
    /* end state for TKAuto*/
    break;
    case 219:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'j')
      return 28;
    else if (ch == L'k')
      return 271;
    else if (ch >= L'l' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 220:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKCase*/
    /* end state for TKCase*/
    break;
    case 221:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKChar*/
    /* end state for TKChar*/
    break;
    case 222:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 272;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 223:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'h')
      return 28;
    else if (ch == L'i')
      return 273;
    else if (ch >= L'j' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 224:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L't')
      return 28;
    else if (ch == L'u')
      return 274;
    else if (ch >= L'v' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 225:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'k')
      return 28;
    else if (ch == L'l')
      return 275;
    else if (ch >= L'm' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 226:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKElse*/
    /* end state for TKElse*/
    break;
    case 227:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKEnum*/
    /* end state for TKEnum*/
    break;
    case 228:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'q')
      return 28;
    else if (ch == L'r')
      return 276;
    else if (ch >= L's' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 229:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 277;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 230:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKGoto*/
    /* end state for TKGoto*/
    break;
    case 231:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'm')
      return 28;
    else if (ch == L'n')
      return 278;
    else if (ch >= L'o' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 232:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKLong*/
    /* end state for TKLong*/
    break;
    case 233:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'r')
      return 28;
    else if (ch == L's')
      return 279;
    else if (ch >= L't' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 234:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'q')
      return 28;
    else if (ch == L'r')
      return 280;
    else if (ch >= L's' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 235:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'q')
      return 28;
    else if (ch == L'r')
      return 281;
    else if (ch >= L's' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 236:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 282;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 237:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 283;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 238:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'n')
      return 28;
    else if (ch == L'o')
      return 284;
    else if (ch >= L'p' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 239:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'h')
      return 28;
    else if (ch == L'i')
      return 285;
    else if (ch >= L'j' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 240:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'b')
      return 28;
    else if (ch == L'c')
      return 286;
    else if (ch >= L'd' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 241:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'b')
      return 28;
    else if (ch == L'c')
      return 287;
    else if (ch >= L'd' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 242:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'c')
      return 28;
    else if (ch == L'd')
      return 288;
    else if (ch >= L'e' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 243:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'm')
      return 28;
    else if (ch == L'n')
      return 289;
    else if (ch >= L'o' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 244:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'f')
      return 28;
    else if (ch == L'g')
      return 290;
    else if (ch >= L'h' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 245:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKVoid*/
    /* end state for TKVoid*/
    break;
    case 246:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 291;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 247:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 292;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 248:
    if (ch >= L'0' && ch <= L'9')
      return 293;
    else if (ch >= L'A' && ch <= L'F')
      return 293;
    else if (ch >= L'a' && ch <= L'f')
      return 293;
    break;
    case 249:
    if (ch == L'n')
      return 294;
    break;
    case 250:
    /* end state for TKPreElif*/
    break;
    case 251:
    /* end state for TKPreElse*/
    break;
    case 252:
    if (ch == L'f')
      return 295;
    break;
    case 253:
    if (ch == L'r')
      return 296;
    break;
    case 254:
    if (ch == L'f')
      return 297;
    break;
    case 255:
    if (ch == L'e')
      return 298;
    break;
    case 256:
    if (ch == L'u')
      return 299;
    break;
    case 257:
    /* end state for TKPreLine*/
    break;
    case 258:
    if (ch == L'm')
      return 300;
    break;
    case 259:
    if (ch == L'f')
      return 301;
    break;
    case 260:
    if (ch >= L'0' && ch <= L'9')
      return 302;
    else if (ch >= L'A' && ch <= L'F')
      return 302;
    else if (ch >= L'a' && ch <= L'f')
      return 302;
    break;
    case 261:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'm')
      return 28;
    else if (ch == L'n')
      return 303;
    else if (ch >= L'o' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 262:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'h')
      return 28;
    else if (ch == L'i')
      return 304;
    else if (ch >= L'j' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 263:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKBool*/
    /* end state for TKBool*/
    break;
    case 264:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'k')
      return 28;
    else if (ch == L'l')
      return 305;
    else if (ch >= L'm' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 265:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'q')
      return 28;
    else if (ch == L'r')
      return 306;
    else if (ch >= L's' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 266:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'h')
      return 28;
    else if (ch == L'i')
      return 307;
    else if (ch >= L'j' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 267:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 308;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 268:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'h')
      return 28;
    else if (ch == L'i')
      return 309;
    else if (ch >= L'j' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 269:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch == L'a')
      return 310;
    else if (ch >= L'b' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 270:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'b')
      return 28;
    else if (ch == L'c')
      return 311;
    else if (ch >= L'd' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 271:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKBreak*/
    /* end state for TKBreak*/
    break;
    case 272:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKConst*/
    /* end state for TKConst*/
    break;
    case 273:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'm')
      return 28;
    else if (ch == L'n')
      return 312;
    else if (ch >= L'o' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 274:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'k')
      return 28;
    else if (ch == L'l')
      return 313;
    else if (ch >= L'm' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 275:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 314;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 276:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'm')
      return 28;
    else if (ch == L'n')
      return 315;
    else if (ch >= L'o' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 277:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKFloat*/
    /* end state for TKFloat*/
    break;
    case 278:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 316;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 279:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 317;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 280:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'h')
      return 28;
    else if (ch == L'i')
      return 318;
    else if (ch >= L'j' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 281:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'm')
      return 28;
    else if (ch == L'n')
      return 319;
    else if (ch >= L'o' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 282:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKShort*/
    /* end state for TKShort*/
    break;
    case 283:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'c')
      return 28;
    else if (ch == L'd')
      return 320;
    else if (ch >= L'e' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 284:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'e')
      return 28;
    else if (ch == L'f')
      return 321;
    else if (ch >= L'g' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 285:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'b')
      return 28;
    else if (ch == L'c')
      return 322;
    else if (ch >= L'd' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 286:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 323;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 287:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'g')
      return 28;
    else if (ch == L'h')
      return 324;
    else if (ch >= L'i' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 288:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 325;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 289:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKUnion*/
    /* end state for TKUnion*/
    break;
    case 290:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'm')
      return 28;
    else if (ch == L'n')
      return 326;
    else if (ch >= L'o' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 291:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'h')
      return 28;
    else if (ch == L'i')
      return 327;
    else if (ch >= L'j' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 292:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKWhile*/
    /* end state for TKWhile*/
    break;
    case 293:
    if (ch >= L'0' && ch <= L'9')
      return 55;
    else if (ch >= L'A' && ch <= L'F')
      return 55;
    else if (ch >= L'a' && ch <= L'f')
      return 55;
    break;
    case 294:
    if (ch == L'e')
      return 328;
    break;
    case 295:
    /* end state for TKPreEndif*/
    break;
    case 296:
    /* end state for TKPreError*/
    break;
    case 297:
    /* end state for TKPreIfDef*/
    break;
    case 298:
    if (ch == L'f')
      return 329;
    break;
    case 299:
    if (ch == L'd')
      return 330;
    break;
    case 300:
    if (ch == L'a')
      return 331;
    break;
    case 301:
    /* end state for TKPreUndef*/
    break;
    case 302:
    if (ch >= L'0' && ch <= L'9')
      return 68;
    else if (ch >= L'A' && ch <= L'F')
      return 68;
    else if (ch >= L'a' && ch <= L'f')
      return 68;
    break;
    case 303:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch == L'a')
      return 332;
    else if (ch >= L'b' && ch <= L'n')
      return 28;
    else if (ch == L'o')
      return 333;
    else if (ch >= L'p' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 304:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'b')
      return 28;
    else if (ch == L'c')
      return 334;
    else if (ch >= L'd' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 305:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 335;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 306:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'h')
      return 28;
    else if (ch == L'i')
      return 336;
    else if (ch >= L'j' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 307:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'm')
      return 28;
    else if (ch == L'n')
      return 337;
    else if (ch >= L'o' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 308:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L't')
      return 28;
    else if (ch == L'u')
      return 338;
    else if (ch >= L'v' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 309:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'b')
      return 28;
    else if (ch == L'c')
      return 339;
    else if (ch >= L'd' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 310:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'c')
      return 28;
    else if (ch == L'd')
      return 340;
    else if (ch >= L'e' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 311:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 341;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 312:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L't')
      return 28;
    else if (ch == L'u')
      return 342;
    else if (ch >= L'v' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 313:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 343;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 314:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKDouble*/
    /* end state for TKDouble*/
    break;
    case 315:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKExtern*/
    /* end state for TKExtern*/
    break;
    case 316:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKInline*/
    /* end state for TKInline*/
    break;
    case 317:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 344;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 318:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'b')
      return 28;
    else if (ch == L'c')
      return 345;
    else if (ch >= L'd' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 319:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKReturn*/
    /* end state for TKReturn*/
    break;
    case 320:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKSigned*/
    /* end state for TKSigned*/
    break;
    case 321:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKSizeOf*/
    /* end state for TKSizeOf*/
    break;
    case 322:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKStatic*/
    /* end state for TKStatic*/
    break;
    case 323:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKStruct*/
    /* end state for TKStruct*/
    break;
    case 324:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKSwitch*/
    /* end state for TKSwitch*/
    break;
    case 325:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'e')
      return 28;
    else if (ch == L'f')
      return 346;
    else if (ch >= L'g' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 326:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 347;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 327:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'k')
      return 28;
    else if (ch == L'l')
      return 348;
    else if (ch >= L'm' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 328:
    /* end state for TKPreDefine*/
    break;
    case 329:
    /* end state for TKPreIfNDef*/
    break;
    case 330:
    if (ch == L'e')
      return 349;
    break;
    case 331:
    /* end state for TKPrePragma*/
    break;
    case 332:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'r')
      return 28;
    else if (ch == L's')
      return 350;
    else if (ch >= L't' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 333:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'e')
      return 28;
    else if (ch == L'f')
      return 351;
    else if (ch >= L'g' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 334:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKAtomic*/
    /* end state for TKAtomic*/
    break;
    case 335:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'w')
      return 28;
    else if (ch == L'x')
      return 352;
    else if (ch >= L'y' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 336:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'b')
      return 28;
    else if (ch == L'c')
      return 353;
    else if (ch >= L'd' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 337:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch == L'a')
      return 354;
    else if (ch >= L'b' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 338:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'q')
      return 28;
    else if (ch == L'r')
      return 355;
    else if (ch >= L's' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 339:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 356;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 340:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 357;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 341:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 358;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 342:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 359;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 343:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKDefault*/
    /* end state for TKDefault*/
    break;
    case 344:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'q')
      return 28;
    else if (ch == L'r')
      return 360;
    else if (ch >= L's' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 345:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 361;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 346:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKTypedef*/
    /* end state for TKTypedef*/
    break;
    case 347:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'c')
      return 28;
    else if (ch == L'd')
      return 362;
    else if (ch >= L'e' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 348:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 363;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 349:
    /* end state for TKPreInclude*/
    break;
    case 350:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKAlignAs*/
    /* end state for TKAlignAs*/
    break;
    case 351:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKAlignOf*/
    /* end state for TKAlignOf*/
    break;
    case 352:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKComplex*/
    /* end state for TKComplex*/
    break;
    case 353:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKGeneric*/
    /* end state for TKGeneric*/
    break;
    case 354:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'q')
      return 28;
    else if (ch == L'r')
      return 364;
    else if (ch >= L's' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 355:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'm')
      return 28;
    else if (ch == L'n')
      return 365;
    else if (ch >= L'o' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 356:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch == L'a')
      return 366;
    else if (ch >= L'b' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 357:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'k')
      return 28;
    else if (ch == L'l')
      return 367;
    else if (ch >= L'm' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 358:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKFunc*/
    /* end state for TKFunc*/
    break;
    case 359:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKContinue*/
    /* end state for TKContinue*/
    break;
    case 360:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKRegister*/
    /* end state for TKRegister*/
    break;
    case 361:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKRestrict*/
    /* end state for TKRestrict*/
    break;
    case 362:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKUnsigned*/
    /* end state for TKUnsigned*/
    break;
    case 363:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKVolatile*/
    /* end state for TKVolatile*/
    break;
    case 364:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'x')
      return 28;
    else if (ch == L'y')
      return 368;
    else if (ch == L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 365:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKNoReturn*/
    /* end state for TKNoReturn*/
    break;
    case 366:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'r')
      return 28;
    else if (ch == L's')
      return 369;
    else if (ch >= L't' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 367:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'n')
      return 28;
    else if (ch == L'o')
      return 370;
    else if (ch >= L'p' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 368:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKImaginary*/
    /* end state for TKImaginary*/
    break;
    case 369:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'r')
      return 28;
    else if (ch == L's')
      return 371;
    else if (ch >= L't' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 370:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'b')
      return 28;
    else if (ch == L'c')
      return 372;
    else if (ch >= L'd' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 371:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'd')
      return 28;
    else if (ch == L'e')
      return 373;
    else if (ch >= L'f' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 372:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch == L'a')
      return 374;
    else if (ch >= L'b' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 373:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'q')
      return 28;
    else if (ch == L'r')
      return 375;
    else if (ch >= L's' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 374:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'k')
      return 28;
    else if (ch == L'l')
      return 376;
    else if (ch >= L'm' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 375:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L's')
      return 28;
    else if (ch == L't')
      return 377;
    else if (ch >= L'u' && ch <= L'z')
      return 28;
    /* end state for TKIdentifier*/
    break;
    case 376:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKThreadLocal*/
    /* end state for TKThreadLocal*/
    break;
    case 377:
    if (ch == L'$')
      return 28;
    else if (ch >= L'0' && ch <= L'9')
      return 64;
    else if (ch >= L'A' && ch <= L'Z')
      return 28;
    else if (ch == L'_')
      return 28;
    else if (ch >= L'a' && ch <= L'z')
      return 28;
    /*TKStaticAssert*/
    /* end state for TKStaticAssert*/
    break;
  } /*switch*/
  return -1;
}

int PlaygroundLang_IsInterleave(enum PlaygroundLang_Tokens tk)
{
  return false; /*todo add you blanks token here*/
}

int PlaygroundLang_GetTokenFromState(int state, enum PlaygroundLang_Tokens* tk)
{
  switch (state)
  {
    case 1: *tk = TKEndMark; break;
    case 2: *tk = TKBlanks; break;
    case 3: *tk = TKBreakLine; break;
    case 5: *tk = TKEXCLAMATION_MARK; break;
    case 6: *tk = TKQUOTATION_MARK; break;
    case 8: *tk = TKDOLLAR_SIGN; break;
    case 9: *tk = TKPERCENT_SIGN; break;
    case 10: *tk = TKAMPERSAND; break;
    case 11: *tk = TKAPOSTROPHE; break;
    case 12: *tk = TKLEFT_PARENTHESIS; break;
    case 13: *tk = TKRIGHT_PARENTHESIS; break;
    case 14: *tk = TKASTERISK; break;
    case 15: *tk = TKPLUS_SIGN; break;
    case 16: *tk = TKCOMMA; break;
    case 17: *tk = TKHYPHEN_MINUS; break;
    case 18: *tk = TKFULL_STOP; break;
    case 19: *tk = TKSOLIDUS; break;
    case 20: *tk = TKNUMBER; break;
    case 21: *tk = TKCOLON; break;
    case 22: *tk = TKSEMICOLON; break;
    case 23: *tk = TKLESS_THAN_SIGN; break;
    case 24: *tk = TKEQUALS_SIGN; break;
    case 25: *tk = TKGREATER_THAN_SIGN; break;
    case 26: *tk = TKQUESTION_MARK; break;
    case 27: *tk = TKCOMMERCIAL_AT; break;
    case 28: *tk = TKIdentifier; break;
    case 29: *tk = TKLEFT_SQUARE_BRACKET; break;
    case 30: *tk = TKREVERSE_SOLIDUS; break;
    case 31: *tk = TKRIGHT_SQUARE_BRACKET; break;
    case 32: *tk = TKCIRCUMFLEX_ACCENT; break;
    case 33: *tk = TKLOW_LINE; break;
    case 34: *tk = TKGRAVE_ACCENT; break;
    case 35: *tk = TKIdentifier; break;
    case 36: *tk = TKIdentifier; break;
    case 37: *tk = TKIdentifier; break;
    case 38: *tk = TKIdentifier; break;
    case 39: *tk = TKIdentifier; break;
    case 40: *tk = TKIdentifier; break;
    case 41: *tk = TKIdentifier; break;
    case 42: *tk = TKIdentifier; break;
    case 43: *tk = TKIdentifier; break;
    case 44: *tk = TKIdentifier; break;
    case 45: *tk = TKIdentifier; break;
    case 46: *tk = TKIdentifier; break;
    case 47: *tk = TKIdentifier; break;
    case 48: *tk = TKIdentifier; break;
    case 49: *tk = TKIdentifier; break;
    case 50: *tk = TKLEFT_CURLY_BRACKET; break;
    case 51: *tk = TKVERTICAL_LINE; break;
    case 52: *tk = TKRIGHT_CURLY_BRACKET; break;
    case 54: *tk = TKNeOp; break;
    case 56: *tk = TKSTRING; break;
    case 65: *tk = TKModAssign; break;
    case 66: *tk = TKAndOp; break;
    case 67: *tk = TKAndAssign; break;
    case 69: *tk = TKCHAR; break;
    case 71: *tk = TKMultAssign; break;
    case 72: *tk = TKIncOp; break;
    case 73: *tk = TKNumber; break;
    case 74: *tk = TKAddAssign; break;
    case 75: *tk = TKDecOp; break;
    case 76: *tk = TKSubAssign; break;
    case 77: *tk = TKPtrOp; break;
    case 81: *tk = TKDivAssign; break;
    case 84: *tk = TKLeftOp; break;
    case 85: *tk = TKLeOp; break;
    case 86: *tk = TKEqOp; break;
    case 87: *tk = TKGeOp; break;
    case 88: *tk = TKRightOp; break;
    case 89: *tk = TKNotBreakLine; break;
    case 91: *tk = TKXorAssign; break;
    case 92: *tk = TKIdentifier; break;
    case 93: *tk = TKIdentifier; break;
    case 94: *tk = TKIdentifier; break;
    case 95: *tk = TKIdentifier; break;
    case 96: *tk = TKIdentifier; break;
    case 97: *tk = TKIdentifier; break;
    case 98: *tk = TKIdentifier; break;
    case 99: *tk = TKIdentifier; break;
    case 100: *tk = TKIdentifier; break;
    case 101: *tk = TKIdentifier; break;
    case 102: *tk = TKIdentifier; break;
    case 103: *tk = TKIdentifier; break;
    case 104: *tk = TKIdentifier; break;
    case 105: *tk = TKIdentifier; break;
    case 106: *tk = TKIdentifier; break;
    case 107: *tk = TKDo; break;
    case 108: *tk = TKIdentifier; break;
    case 109: *tk = TKIdentifier; break;
    case 110: *tk = TKIdentifier; break;
    case 111: *tk = TKIdentifier; break;
    case 112: *tk = TKIdentifier; break;
    case 113: *tk = TKIdentifier; break;
    case 114: *tk = TKIf; break;
    case 115: *tk = TKIdentifier; break;
    case 116: *tk = TKIdentifier; break;
    case 117: *tk = TKIdentifier; break;
    case 118: *tk = TKIdentifier; break;
    case 119: *tk = TKIdentifier; break;
    case 120: *tk = TKIdentifier; break;
    case 121: *tk = TKIdentifier; break;
    case 122: *tk = TKIdentifier; break;
    case 123: *tk = TKIdentifier; break;
    case 124: *tk = TKIdentifier; break;
    case 125: *tk = TKIdentifier; break;
    case 126: *tk = TKOrAssign; break;
    case 127: *tk = TKOrOp; break;
    case 133: *tk = TKPreIf; break;
    case 138: *tk = TKIdentifier; break;
    case 141: *tk = TKEllipsis; break;
    case 143: *tk = TKLINECOMMENT; break;
    case 146: *tk = TKNUMBER; break;
    case 148: *tk = TKNumber; break;
    case 149: *tk = TKLeftAssign; break;
    case 150: *tk = TKRightAssign; break;
    case 151: *tk = TKIdentifier; break;
    case 152: *tk = TKIdentifier; break;
    case 153: *tk = TKIdentifier; break;
    case 154: *tk = TKIdentifier; break;
    case 155: *tk = TKIdentifier; break;
    case 156: *tk = TKIdentifier; break;
    case 157: *tk = TKIdentifier; break;
    case 158: *tk = TKIdentifier; break;
    case 159: *tk = TKIdentifier; break;
    case 160: *tk = TKIdentifier; break;
    case 161: *tk = TKIdentifier; break;
    case 162: *tk = TKIdentifier; break;
    case 163: *tk = TKIdentifier; break;
    case 164: *tk = TKIdentifier; break;
    case 165: *tk = TKIdentifier; break;
    case 166: *tk = TKIdentifier; break;
    case 167: *tk = TKIdentifier; break;
    case 168: *tk = TKIdentifier; break;
    case 169: *tk = TKIdentifier; break;
    case 170: *tk = TKIdentifier; break;
    case 171: *tk = TKIdentifier; break;
    case 172: *tk = TKFor; break;
    case 173: *tk = TKIdentifier; break;
    case 174: *tk = TKIdentifier; break;
    case 175: *tk = TKInt; break;
    case 176: *tk = TKIdentifier; break;
    case 177: *tk = TKIdentifier; break;
    case 178: *tk = TKIdentifier; break;
    case 179: *tk = TKIdentifier; break;
    case 180: *tk = TKIdentifier; break;
    case 181: *tk = TKIdentifier; break;
    case 182: *tk = TKIdentifier; break;
    case 183: *tk = TKIdentifier; break;
    case 184: *tk = TKIdentifier; break;
    case 185: *tk = TKIdentifier; break;
    case 186: *tk = TKIdentifier; break;
    case 187: *tk = TKIdentifier; break;
    case 188: *tk = TKIdentifier; break;
    case 189: *tk = TKIdentifier; break;
    case 190: *tk = TKIdentifier; break;
    case 191: *tk = TKIdentifier; break;
    case 205: *tk = TKNumber; break;
    case 206: *tk = TKCOMMENT; break;
    case 207: *tk = TKNUMBER; break;
    case 208: *tk = TKIdentifier; break;
    case 209: *tk = TKIdentifier; break;
    case 210: *tk = TKIdentifier; break;
    case 211: *tk = TKIdentifier; break;
    case 212: *tk = TKIdentifier; break;
    case 213: *tk = TKIdentifier; break;
    case 214: *tk = TKIdentifier; break;
    case 215: *tk = TKIdentifier; break;
    case 216: *tk = TKIdentifier; break;
    case 217: *tk = TKIdentifier; break;
    case 218: *tk = TKAuto; break;
    case 219: *tk = TKIdentifier; break;
    case 220: *tk = TKCase; break;
    case 221: *tk = TKChar; break;
    case 222: *tk = TKIdentifier; break;
    case 223: *tk = TKIdentifier; break;
    case 224: *tk = TKIdentifier; break;
    case 225: *tk = TKIdentifier; break;
    case 226: *tk = TKElse; break;
    case 227: *tk = TKEnum; break;
    case 228: *tk = TKIdentifier; break;
    case 229: *tk = TKIdentifier; break;
    case 230: *tk = TKGoto; break;
    case 231: *tk = TKIdentifier; break;
    case 232: *tk = TKLong; break;
    case 233: *tk = TKIdentifier; break;
    case 234: *tk = TKIdentifier; break;
    case 235: *tk = TKIdentifier; break;
    case 236: *tk = TKIdentifier; break;
    case 237: *tk = TKIdentifier; break;
    case 238: *tk = TKIdentifier; break;
    case 239: *tk = TKIdentifier; break;
    case 240: *tk = TKIdentifier; break;
    case 241: *tk = TKIdentifier; break;
    case 242: *tk = TKIdentifier; break;
    case 243: *tk = TKIdentifier; break;
    case 244: *tk = TKIdentifier; break;
    case 245: *tk = TKVoid; break;
    case 246: *tk = TKIdentifier; break;
    case 247: *tk = TKIdentifier; break;
    case 250: *tk = TKPreElif; break;
    case 251: *tk = TKPreElse; break;
    case 257: *tk = TKPreLine; break;
    case 261: *tk = TKIdentifier; break;
    case 262: *tk = TKIdentifier; break;
    case 263: *tk = TKBool; break;
    case 264: *tk = TKIdentifier; break;
    case 265: *tk = TKIdentifier; break;
    case 266: *tk = TKIdentifier; break;
    case 267: *tk = TKIdentifier; break;
    case 268: *tk = TKIdentifier; break;
    case 269: *tk = TKIdentifier; break;
    case 270: *tk = TKIdentifier; break;
    case 271: *tk = TKBreak; break;
    case 272: *tk = TKConst; break;
    case 273: *tk = TKIdentifier; break;
    case 274: *tk = TKIdentifier; break;
    case 275: *tk = TKIdentifier; break;
    case 276: *tk = TKIdentifier; break;
    case 277: *tk = TKFloat; break;
    case 278: *tk = TKIdentifier; break;
    case 279: *tk = TKIdentifier; break;
    case 280: *tk = TKIdentifier; break;
    case 281: *tk = TKIdentifier; break;
    case 282: *tk = TKShort; break;
    case 283: *tk = TKIdentifier; break;
    case 284: *tk = TKIdentifier; break;
    case 285: *tk = TKIdentifier; break;
    case 286: *tk = TKIdentifier; break;
    case 287: *tk = TKIdentifier; break;
    case 288: *tk = TKIdentifier; break;
    case 289: *tk = TKUnion; break;
    case 290: *tk = TKIdentifier; break;
    case 291: *tk = TKIdentifier; break;
    case 292: *tk = TKWhile; break;
    case 295: *tk = TKPreEndif; break;
    case 296: *tk = TKPreError; break;
    case 297: *tk = TKPreIfDef; break;
    case 301: *tk = TKPreUndef; break;
    case 303: *tk = TKIdentifier; break;
    case 304: *tk = TKIdentifier; break;
    case 305: *tk = TKIdentifier; break;
    case 306: *tk = TKIdentifier; break;
    case 307: *tk = TKIdentifier; break;
    case 308: *tk = TKIdentifier; break;
    case 309: *tk = TKIdentifier; break;
    case 310: *tk = TKIdentifier; break;
    case 311: *tk = TKIdentifier; break;
    case 312: *tk = TKIdentifier; break;
    case 313: *tk = TKIdentifier; break;
    case 314: *tk = TKDouble; break;
    case 315: *tk = TKExtern; break;
    case 316: *tk = TKInline; break;
    case 317: *tk = TKIdentifier; break;
    case 318: *tk = TKIdentifier; break;
    case 319: *tk = TKReturn; break;
    case 320: *tk = TKSigned; break;
    case 321: *tk = TKSizeOf; break;
    case 322: *tk = TKStatic; break;
    case 323: *tk = TKStruct; break;
    case 324: *tk = TKSwitch; break;
    case 325: *tk = TKIdentifier; break;
    case 326: *tk = TKIdentifier; break;
    case 327: *tk = TKIdentifier; break;
    case 328: *tk = TKPreDefine; break;
    case 329: *tk = TKPreIfNDef; break;
    case 331: *tk = TKPrePragma; break;
    case 332: *tk = TKIdentifier; break;
    case 333: *tk = TKIdentifier; break;
    case 334: *tk = TKAtomic; break;
    case 335: *tk = TKIdentifier; break;
    case 336: *tk = TKIdentifier; break;
    case 337: *tk = TKIdentifier; break;
    case 338: *tk = TKIdentifier; break;
    case 339: *tk = TKIdentifier; break;
    case 340: *tk = TKIdentifier; break;
    case 341: *tk = TKIdentifier; break;
    case 342: *tk = TKIdentifier; break;
    case 343: *tk = TKDefault; break;
    case 344: *tk = TKIdentifier; break;
    case 345: *tk = TKIdentifier; break;
    case 346: *tk = TKTypedef; break;
    case 347: *tk = TKIdentifier; break;
    case 348: *tk = TKIdentifier; break;
    case 349: *tk = TKPreInclude; break;
    case 350: *tk = TKAlignAs; break;
    case 351: *tk = TKAlignOf; break;
    case 352: *tk = TKComplex; break;
    case 353: *tk = TKGeneric; break;
    case 354: *tk = TKIdentifier; break;
    case 355: *tk = TKIdentifier; break;
    case 356: *tk = TKIdentifier; break;
    case 357: *tk = TKIdentifier; break;
    case 358: *tk = TKFunc; break;
    case 359: *tk = TKContinue; break;
    case 360: *tk = TKRegister; break;
    case 361: *tk = TKRestrict; break;
    case 362: *tk = TKUnsigned; break;
    case 363: *tk = TKVolatile; break;
    case 364: *tk = TKIdentifier; break;
    case 365: *tk = TKNoReturn; break;
    case 366: *tk = TKIdentifier; break;
    case 367: *tk = TKIdentifier; break;
    case 368: *tk = TKImaginary; break;
    case 369: *tk = TKIdentifier; break;
    case 370: *tk = TKIdentifier; break;
    case 371: *tk = TKIdentifier; break;
    case 372: *tk = TKIdentifier; break;
    case 373: *tk = TKIdentifier; break;
    case 374: *tk = TKIdentifier; break;
    case 375: *tk = TKIdentifier; break;
    case 376: *tk = TKThreadLocal; break;
    case 377: *tk = TKStaticAssert; break;
    default:
    return 0;
  }
  return 1;
}