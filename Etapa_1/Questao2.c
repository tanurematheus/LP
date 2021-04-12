/*2 - Faça um programa que calcule o fatorial de um número informado pelo usuário. Obs: O fatorial de 0 é 1.*/

#include <stdio.h>
#include <stdlib.h>

double fatorial(int x){
  double fat;
  if ( x <= 1 ){
      return (1);
  }else{
    fat = x * fatorial(x - 1);
    return (fat);
  }
}

int main() {
  int a;
  printf("Digite o valor\n");
  scanf("%d", &a);
  printf("%.0lf\n", fatorial(a));
  system("pause");  
  return 0;  
}