/*4 - Um comerciante deseja fazer o levantamento do lucro das mercadorias que ele comercializa. Para isto mandou criar uma ficha para cada mercadoria com o nome, preço de compra, preço de venda. Fazer um algoritmo que :
Determine e escreva quantas mercadorias proporcionam :
a)	Lucro < 20 %			b) 20% <= Lucro <= 30%		c) Lucro > 30% */


#include <stdio.h>
#include <stdlib.h>

float lucro(float a, float b){
 float l;
 l = b-a;
 return (100*l)/a;  
}

int main() {

    float a, b;
    int maiorLucro = 0, menorLucro = 0, medioLucro =0;

    do{
        printf("Digite o valor de compra e o valor de venda ( 0 em ambos para sair)\n");
        scanf("%f %f", &a, &b);
        if(a > b){
            printf("Valor de compra maior ou igual ao valor de venda\n");
        }else if(a < 0 || b < 0){
            printf("Valores invalidos\n");
        }else if(a == 0 && b == 0){
            printf("%d itens tiveram lucro acima de 30\n", maiorLucro);
            printf("%d itens tiveram lucro entre 20 e 30\n", medioLucro);
            printf("%d itens tiveram lucro abaixo e 20\n", menorLucro);
        }else{
            if(lucro(a,b) > 30){
                maiorLucro++;
            }else if(lucro(a,b) > 20){
                medioLucro++;
            }else{
                menorLucro++;
            }
        }
    }while( (a + b) != 0);
    system("pause");  
    return 0;  
}
