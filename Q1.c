#include <stdio.h>
#include <stdlib.h>
int soma(int a1, int b1){
  int soma;
  soma = a1 + b1;
  return soma;
}
int main()
{
 int num1, num2;
 int resultado;
 printf("Digite um número: \n");
  scanf("%d",&num1);
   printf("Digite um número: \n");
  scanf("%d",&num2);
  resultado= soma(num1, num2);
  printf("%d",resultado);
}