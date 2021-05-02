/*8 - Dado um número natural na base decimal, transformá-lo para a base binária.
Exemplo: Dado 18 a saída deverá ser 10010. */

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, c, k, aux, x, bool = 0;

    printf("Informe o inteiro\n");
    scanf("%d", &n);

    printf("%d em binario: \n", n);

    for(aux=0, x = n; x; aux++, x/=10);    

    for (c = (sizeof(int) * aux)-1; c >= 0; c--){
        k = n >> c;

        if (k & 1){
            printf("1");
            bool = 1;
        }else if(bool){        
            printf("0");
        }
    }
    printf("\n");
    system("pause"); 

    return 0;
}
