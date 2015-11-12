# ParserC

Parser de código C.

A ideia é começar com um tokenizer + pre-processador.

Descrição do algorítmo.

Componentes:
##Stream
Stream é uma classe que puxa um caractere  por vez (já faz trabalho do utf8) e o caractere pode ser devolvido e puxado novamente.

```
Stream stream;

wchar_t ch;
Stream_GetChar(&stream, &ch)
Stream_PutChar(&stream, ch)
```
##GetRawToken
GetRawToken é uma função aonde se passa o Stream um ponteiro out para token e uma string out lexeme;

```
GetRawToken(stream, token, lexeme);
```
Esta função devolve o token e o lexeme consumindo os caracteres do stream.
Este tokens vão incluir tokens de pre-processador também.

##Scanner

Scanner é um objeto que digere os tokens do pre-processador e retorna de forma continua os tokens somente da linguagem C.

Exemplo:
```
#include "a.h"
int main()
{
}
```

Tokens (raw)

```
#include
"a.h"
int
main
(
)
```

Este tokens são "puxados" pela Scanner através da GetRawToken.

Se o token não for o início do pré-processador ele retorna o token diretamente ao ser puxado.
Se for pré-processador os tokens raw serão processados e digeridos até que um token da linguagem C possa ser retornado.

#include
O scanner contém uma pilha de streams.

O primeiro a ser empilhado é o arquivo de entrada do parser. Os próximos são os arquivo de include.

Ao puxar o token include ele empilha um novo stream para o arquivo a ser incluido. O stream usado pelo scanner é sempre o arquivo do topo da pilha. Ao final do arquivo (token eof) ele faz o pop e continua usando o stream anterior.

Alguns tokens raw podem ser renomeados. Exemplo, se um token "defined" for criado ao virar um token C ele pode virar um identificador.

```
Scanner scanner;
Scanner_GetNext(&scanner, lexeme, token);
```

##define
O Scanner possui um mapa para defines. Este mapa é usado no ifdef ifndef.
Depois vai ser usado para fazer a substituição das macros.

##if
Não implementado.

##ifdef ifndef elseif endif

Para o pré-procesador ifdef o scanner mantém o estado se deve incluir os tokens "puxados" ou ignorar.
Casos os tokens sejam ignorados eles são todos consumidos até achar um #else ou #endif que corresponda a #else ou #ifdef.
Para achar o #else ou #endif correspondente é feita uma contagem ++ para cada #ifdef #ifndef e para cada #else ou #endif  é feito--.
Ao encontrar #endif com contagem zero ele é o que fecha.


##undef

##error


#substituição das macros
O processo de subtituir as macros é semelhante ao include. Porem ao inves de abrir um stream de arquivo é aberto um stream de string que contem o conteudo do define. O stream é empilhado da mesma forma que os includes.

Os parametros da macro sao empilhados como se fossem defines temporarios.

