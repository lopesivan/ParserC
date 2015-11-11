# ParserC

Parser de código C.

A ideia é começar com um tokenizer + pre-processador.

Descrição do algorítmo.

Componentes:
##Stream
Stream é uma classe que puxa um caractere (já faz trabalho do utf8) e o caractere pode ser devolvido e puxado novamente.

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

Scanner é um objeto que digere os tokens do pre-processador e retorna de forma continua os tokens que já fazem o #include #ifdef e processamento dos #defines.


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
O scanner contém uma pilha de streams.  O primeiro a ser empilhado é o arquivo de entrada do parser. Os próximos são os arquivo de include.

Ao puxar o token include ele criar outro stream e empilhar. O stream usado para pegar os tokens raw é sempre o stream do topo da pilha.
Ao terminar o arquivo ele faz o pop e continua no stream anterior.

```
Scanner scanner;
Scanner_GetNext(&scanner, lexeme, token);
```

#define
O Scanner possui um mapa para defines. Este mapa é usado no ifdef ifndef.
Depois vai ser usado para fazer a substituição das macros.

#if
Não implementado.

##ifdef ifndef elseif endif

Para o pré-procesador ifdef o scanner mantém o estado se deve incluir os tokens "puxados" ou ignorar.
Casos os tokens sejam ignorados eles são todos consumidos até achar um #else ou #endif que corresponda a #else ou #ifdef.
Para achar o #else ou #endif correspondente é feita uma contagem ++ para cada #ifdef #ifndef e para cada #else ou #endif  é feito--.
Ao encontrar #endif com contagem zero ele é o que fecha.






