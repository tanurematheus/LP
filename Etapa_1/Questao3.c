/*3 - Dizemos que um inteiro positivo n é perfeito se for igual à soma de seus divisores positivos diferentes de n.
Exemplo: 6 é perfeito, pois 1+2+3 = 6.
Dado um inteiro positivo n, verificar se n é perfeito.*/

#include <stdio.h>
#include <stdlib.h>

void perfeito(int a){
    int x =0;
    for (int i = a/2; i>0; i--){
        if(a % i == 0){
            x += i;
        }
    }
    if(x == a){
      printf("%d e perfeito\n", a);  
    }else{
      printf("%d nao e perfeito\n", a); 
    }   
}

int main() {
  int a;
  printf("Digite o valor\n");
  scanf("%d", &a);
  if(a == 1){
      printf("1 e perfeito\n");
  }else if(a<1){
      printf("Numero Invalido\n");
  }else{
      perfeito(a);
  }  
  system("pause");  
  return 0;  
}
