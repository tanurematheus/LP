/*11 - 5 - Um quadrado mágico de ordem n ( sendo n um número ímpar) é um arranjo de números de 1 a n em uma matriz quadrada de tal modo que a soma de cada linha, coluna e diagonal é a mesma.

15	8	1	24	17
16	14	7	5	23
22	20	13	6	4
3	21	19	12	10
9	2	25	18	11

A figura mostra um quadrado mágico de ordem 5. A regra para gerá-lo é relativamente fácil de observar: Comece com o 1 no meio da primeira linha, 
então siga para cima e para a esquerda diagonalmente ( quando sair do quadrado suponha que os lados superior e inferior estão unidos ou que os lados da 
direita e da esquerda estão unidos, conforme for o caso) em cada quadrado que passar coloque o valor do quadrado anterior mais 1 (um), quando atingir um
quadrado já ocupado, desça um quadrado e continue seguindo a diagonal até ter preenchido todos os quadrados. Elabore um programa que leia 5 números ímpares, um de cada vez, gere e escreva para um número lido, o seu quadrado mágico.*/


#include <stdio.h>
#include <stdlib.h>

void iniciar_matriz(int x, int m[x][x]){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            m[i][j] = 0;
        }
    }
}

void print_matriz(int x, int m[x][x]){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < x; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int confere(int x, int z){
    if(z == 0){
        return x-1;
    }else{
        return z - 1; 
    }
}

int main() {
    int x;

    for(int i = 0; i < 5; i++){
        printf("Informe a ordem do %d quadrado magico\n", i+1);
        scanf("%d", &x);

        while(x < 0 || !(x%2)){
            printf("numero invalido\n");
            printf("Informe a ordem do %d quadrado magico\n", i+1);
            scanf("%d", &x);            
        }

        if(x == 1){
            printf("1\n");
        }else{

            int m[x][x];
            int linha = 0;
            int coluna = x/2;
            iniciar_matriz(x, m);           
            
            for(int aux = 1; aux <= (x*x); aux++){    
                int prox_linha, prox_coluna;

                m[linha][coluna] = aux;

                prox_coluna = confere(x, coluna);
                prox_linha = confere(x, linha);            
               
                if(m[prox_linha][prox_coluna]){
                    if(linha == x-1){
                       linha = 0; 
                    }else{
                        linha++;
                    }
                }else{
                    linha = prox_linha;
                    coluna = prox_coluna;
                }                
            }
            print_matriz(x, m); 
        }       
    }
    system("pause");  
    return 0;  
}