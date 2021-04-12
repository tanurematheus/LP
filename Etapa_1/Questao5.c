/*5 - Um determinado material radioativo perde metade de sua massa a cada 50 segundos. Dada a massa inicial em gramas, fazer um algoritmo 
que determine o tempo necessário para que essa massa se torne menor do que 0,5 grama. Escreva a massa inicial, a massa final e o tempo calculado em horas, minutos e segundos.*/

#include <stdio.h>
#include <stdlib.h>

int perda(float a){
 int i = 0; 
 while(a > 0.5){
     a=a/2;
     i++;
 } 
 return i;  
}

void tempo(int t){
    int horas, minutos, segundos;
    segundos = t*50;
    horas = segundos/3600;
    segundos = segundos -(horas*3600);
    minutos = segundos/60;
    segundos = segundos - (minutos*60);
    printf("%d:%d:%d\n",horas,minutos,segundos);
}

int main() {
    int t;
    float a;
    printf("Digite a massa\n");
    scanf("%f", &a);
    t = perda(a);
    tempo(t);  
    system("pause");  
    return 0;  
}


