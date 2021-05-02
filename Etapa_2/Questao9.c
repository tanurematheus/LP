/*9 - Dizemos que um número natural n é palíndromo se 
    o 1º algarismo de n é igual ao seu último algarismo, 
    o 2º algarismo de n é igual ao penúltimo algarismo, 
    e assim sucessivamente.

O mesmo pode acontecer com algumas palavras, quando a ordem dos caracteres seguem a mesma regra acima 
Exemplos:
o	567765 e 32423 são palíndromos.
o	567675 não é palíndromo.
o	567675 não é palíndromo.
o	REVIVER, OSSO e RADAR são palíndromo.
o	REVIVE não é palíndromo.
o	RODAR não é palíndromo.

A partir de uma entrada de dados verificar se é palíndromo.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {       
    char dados[50], dadosInvertidos[50];

    printf("\nInforme os dados: ");
    gets(dados);
 
    strcpy(dadosInvertidos, dados);

    strrev(dadosInvertidos); 

    if (!strcmp(dados, dadosInvertidos)){
        printf("%s e palindromo\n", dados);
    }else{
        printf("%s nao e palindromo\n", dados);
    }
    system("pause"); 
    return 0;
}
