#include <stdio.h>
#include <stdlib.h>
int subtra(int a1, int b1, int c1){
  int subtra;
  subtra = a1 - b1 - c1;
  return subtra;
}
int main()
{
 int num1, num2,num3;
 int resultado;
 printf("Digite um número: \n");
  scanf("%d",&num1);
   printf("Digite um número: \n");
  scanf("%d",&num2);
  printf("Digite um número: \n");
  scanf("%d",&num3);
  resultado= subtra(num1, num2, num3);
  printf("%d",resultado);
}