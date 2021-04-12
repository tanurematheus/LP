/*3 - Dizemos que um inteiro positivo n é perfeito se for igual à soma de seus divisores positivos diferentes de n.
Exemplo: 6 é perfeito, pois 1+2+3 = 6.
Dado um inteiro positivo n, verificar se n é perfeito.*/

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
