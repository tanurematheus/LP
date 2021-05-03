/*10 - Gere dois vetores de 10 posições de forma lógica onde o valor a ser armazenado em cada posição seja correspondente aos cálculos abaixo :

Vetor1 - cada posição deve armazenar o fatorial correspondente ao índice desta posição.
Ex : o fatorial de 5! = 120. Assim como o fatorial de 4 = 24.
1	1	2	6	24	120	.....	.....	.....	....
0   1   2   3   4   5   6       7       8       9

Vetor2 - cada posição deve armazenar o valor correspondente ao número na sequência de Fibonacci. O usuário deve informar a quantidade de termos da série.

Ex : o sexto elemento da sequencia de Fibonacci é igual a 13. Assim com o quarto elemento é igual a 5
1	1	2	3	5	8	13	.....	.....	....
0	1   2   3   4   5   6   7       8        9*/

#include <stdio.h>
#include <stdlib.h>

void preencher_fat(unsigned long int *a){
    for(int i=0; i<10; i++){
        if ( i <= 1 ){
            a[i] = 1;
        }else{
            a[i] = a[i-1] * i; 
        }
    }
}

void preencher_fibo(unsigned long int *a, int x){
    for(int i=0; i<x; i++){
        if ( i <= 1 ){
            a[i] = 1;
        }else{
            a[i] = a[i-1] + a[i-2]; 
        }
    }
}

void print_fat(unsigned long int *a){
    for(int i=0; i<10; i++){
        printf("fatorial de %d = %d\n", i, a[i]);
    } 
    printf("\n"); 
}

void print_fibo(unsigned long int *a, int x){
    for(int i=0; i < x; i++){
        printf("%d termo = %d\n", i+1, a[i]);
    } 
    printf("\n"); 
}

int main() {
    int x;
    unsigned long int a[10];
    
    preencher_fat(a);   

    print_fat(a);

    printf("Informe o numero de termos que deseja\n");
    scanf("%d", &x);

    unsigned long int b[x];

    preencher_fibo(b,x);

    print_fibo(b, x);   

    system("pause");  
    return 0;  
}