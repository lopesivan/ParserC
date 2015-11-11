# ParserC

Parser de código C.

A ideia é começar com um tokenizer + pre-processador.

O tokenizer deve gerar tokens que incluem pre-processador e depois é passado para um objeto que tem estado e vai consumindo e digerindo o pré-processador.

Exemplo:
```
#include "a.h"
int main()
{
}
```

Tokens

```
#include
"a.h"
int
main
(
)
```

Este tokens são "puxados".
Ao puxar o token #include ele fazer o parser do include e troca o stream para a.h e empilha ao stream anterior.
Ao término do stream de a.h ele faz um pop deste stream e volta para o stream anterior.

```
Scanner scanner;
Scanner_GetNext(&scanner, lexeme, token);
```

##ifdef etc

Para o pré-procesador ifdef o scanner mantém o estado se deve incluir os tokens "puxados" ou ignorar.
Casos os tokens sejam ignorados eles são todos consumidos até achar um #else ou #endif que corresponda a #else ou #ifdef.
Para achar o #else ou #endif correspondente é feita uma contagem ++ para cada #ifdef #ifndef e para cada #else ou #endif  é feito--.
Ao encontrar #endif com contagem zero ele é o que fecha.






