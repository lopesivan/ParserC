```c
 token PreInclude = "#include";
    token PreDefine = "#define";
    token PreLine = "#line";
    token PreUndef = "#undef";
    token PreError= "#error";
    token PrePragma= "#pragma";
    token PreIf = "#if";
    token PreIfDef = "#ifdef";
    token PreIfNDef = "#ifndef";
    token PreElse = "#else";
    token PreEndif = "#endif";
    token PreElif = "#elif";

    token Ellipsis = "...";
    token RightAssign = ">>=";
    token LeftAssign = "<<=";
    token AddAssign = "+=";
    token SubAssign = "-=";
    token MultAssign = "*=";
    token DivAssign = "/=";
    token ModAssign = "%=";
    token AndAssign = "&=";
    token XorAssign = "^=";
    token OrAssign = "|=";
    token RightOp = ">>";
    token LeftOp = "<<";
    token IncOp = "++";
    token DecOp = "--";
    token PtrOp = "->";
    token AndOp = "&&";
    token OrOp = "||";
    token LeOp = "<=";
    token GeOp = ">=";
    token EqOp = "==";
    token NeOp = "!=";

    token EXCLAMATION_MARK = '!';
    token QUOTATION_MARK = '"';

    token DOLLAR_SIGN = '$';
    token PERCENT_SIGN = '%';
    token AMPERSAND = '&';
    token APOSTROPHE = '\'';
    token LEFT_PARENTHESIS = '(';
    token RIGHT_PARENTHESIS = ')';
    token ASTERISK = '*';
    token PLUS_SIGN = '+';
    token COMMA = ',';
    token HYPHEN_MINUS = '-';
    token FULL_STOP = '.';
    token SOLIDUS = '/';
    token COLON = ':';
    token SEMICOLON = ';';
    token LESS_THAN_SIGN = '<';
    token EQUALS_SIGN = '=';
    token GREATER_THAN_SIGN = '>';
    token QUESTION_MARK = '?';
    token COMMERCIAL_AT = '@';
    token LEFT_SQUARE_BRACKET = '[';
    token REVERSE_SOLIDUS = '\\';
    token RIGHT_SQUARE_BRACKET = ']';
    token CIRCUMFLEX_ACCENT = '^';
    token LOW_LINE = '_';
    token GRAVE_ACCENT = '`';
    token LEFT_CURLY_BRACKET = '{';
    token VERTICAL_LINE = '|';
    token RIGHT_CURLY_BRACKET = '}';


    token LINECOMMENT = ("//" (' '..'-' | '/'..'\u00FF') (' '..'\u00FF')* ('\n' | "\r\n" | "\0"))
    | ("//" ("\n" | "\r\n" | "\0"));



    token COMMENT =  ( "/*" (((' '..')' | '+'..'\u00FF' | "\n" | "\r" | "\t")) | ("*" (' '..'.' | '0'..'\u00FF' | "\n" | "\r" | "\t")))* "*/");

    token CHAR                  = "'"((' '..'&' | '('..'[' | ']'..'\u00FF') |
    ('\\'('\'' | '\\' | '/' | '0' | 'b' | 'f' | 'n' | 'r' | 't' | ('u'('0'..'9' | 'A'..'F' | 'a'..'f')('0'..'9' | 'A'..'F' | 'a'..'f')('0'..'9' | 'A'..'F' | 'a'..'f')('0'..'9' | 'A'..'F' | 'a'..'f'))))
                                     )* "'";




    token STRING                = '"'(

      (' '..'!' | '#'..'[' | ']'..'\u00FF') |

      ('\\'('"' | '\\' | '/' | 'b' | 'f' | 'n' | 'r' | 't' | ('u'('0'..'9' | 'A'..'F' | 'a'..'f')('0'..'9' | 'A'..'F' | 'a'..'f')('0'..'9' | 'A'..'F' | 'a'..'f')('0'..'9' | 'A'..'F' | 'a'..'f'))))

    ) *

    '"';

    token NUMBER = '0'..'9'+ ('.' '0'..'9'+)?;

    token Blanks  = (" " | "\t")+ ;

    token BreakLine = ("\r\n" | '\n');
    token NotBreakLine = '\\' ("\r\n" | '\n');


    token EndMark = '\0';

    //Keywords do C

    token Auto = "auto";
    token Break = "break";
    token Case = "case";
    token Char = "char";
    token Const = "const";
    token Continue = "continue";
    token Default = "default";
    token Do = "do";
    token Double = "double";
    token Else = "else";
    token Enum = "enum";
    token Extern = "extern";
    token Float = "float";
    token For = "for";
    token Goto = "goto";
    token If = "if";
    token Inline = "inline";
    token Int = "int";
    token Long = "long";
    token Register = "register";
    token Restrict = "restrict";
    token Return = "return";
    token Short = "short";
    token Signed = "signed";
    token SizeOf = "sizeof";
    token Static = "static";
    token Struct = "struct";
    token Switch = "switch";
    token Typedef = "typedef";
    token Union = "union";
    token Unsigned = "unsigned";
    token Void = "void";
    token Volatile = "volatile";
    token While = "while";
    token AlignAs = "_Alignas";
    token AlignOf = "_Alignof";
    token Atomic = "_Atomic";
    token Bool = "_Bool";
    token Complex = "_Complex";
    token Generic = "_Generic";
    token Imaginary = "_Imaginary";
    token NoReturn = "_Noreturn";
    token StaticAssert = "_Static_assert";
    token ThreadLocal = "_Thread_local";
    token Func = "__func__";

    token Number = ('+' | '-') ? ('0'..'9') + ('.' '0'..'9') ? (('E' | 'e')('+' | '-') ? '0'..'9') ?;

    token Identifier   = ('a'..'z' | 'A'..'Z' | '_' | '$') +
    ('0'..'9' + ('a'..'z' | 'A'..'Z' | '_' | '$') +) ?;


```
