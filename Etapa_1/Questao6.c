/*5 - 6 – Desenvolva um programa em C que simule um caixa eletrônico e leia um certo valor em Reais que represente um saque a
 ser realizado pelo usuário. O programa deve calcular o menor número de notas possíveis no qual o valor pode ser decomposto. 
 As notas consideradas são de 100, 50, 20, 10, 5, 2 e 1. A seguir mostre o valor lido e a relação de notas necessárias. */

#include <stdio.h>
#include <stdlib.h>



void decomposicao(int valor){
    int a[] = {100, 50, 20, 10, 5, 2, 1};
    printf("As notas necessarias sao:\n");

    for(int i = 0; i < 7; i++){
        if(valor/a[i] > 0){
            printf("%d notas de %d\n", valor / a[i], a[i]);
            valor = valor - ((valor / a[i]) * a[i]);
        }
        if(valor == 0){
            break;
        }
    } 
}

int main() {
    int a;
    printf("Digite o valor a ser sacado\n");
    scanf("%d", &a);
    printf("%d foi o valor informado\n", a);
    decomposicao(a); 
    system("pause");  
    return 0;  
}
