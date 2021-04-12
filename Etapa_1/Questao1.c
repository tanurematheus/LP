/*1 - Escrever um algoritmo que leia 3 valores a,b,c. Calcule e escreve a média ponderada com pesos = 5 para números acima de 6 e peso = 2,5 para números abaixo ou igual a 6.*/

#include <stdio.h>
#include <stdlib.h>

float peso(float x){
 float p;
 if(x > 6){      
      p = 5;
    }else{
      p = 2.5;
  }
  return p;
}

float mediaPonderada(float a, float b, float c){
  float s, p; 
  p = peso(a) + peso(b) + peso(c);
  s = (a * peso(a)) + (b * peso(b)) + (c * peso(c));  
  return s/p;
}

int main() {
  float a, b, c;
  printf("Digite 3 valores\n");
  scanf("%f %f %f", &a, &b, &c);
  printf("%0.3f\n", mediaPonderada(a,b,c));
  system("pause");  
  return 0;  
}