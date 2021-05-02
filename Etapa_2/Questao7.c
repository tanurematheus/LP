/*7 - Dado um número natural na base binária, transformá-lo para a base decimal.
Exemplo:
Dado 10010 a saída será 18, pois 1*2^4 + 0*2^3 + 0*2^2 + 1*2^1 + 0*2^0 = 18.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int x, dec = 0;

    printf("Informe o numero\n");
    scanf("%d",&x);
   
    for(int i = 0; x ; i++, x /= 10){
        if (x % 10){
            dec += pow(2, i);
        }
    }   

    printf("%d\n",dec);   
  
    system("pause"); 
    return 0;
}

 


