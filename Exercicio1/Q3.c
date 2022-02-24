#include <stdio.h>
#include <stdlib.h>
int main()
{
  int a, b;
  printf("Digite o valor de A: \n");
  scanf("%d",&a);
  printf("Digite o valor de B: \n");
  scanf("%d",&b);
  a=a+b;
  b=a-b;
  a=a-b;
  printf("O novo valor de A é: %d \n",a);
  printf("O novo valor de B é: %d ",b);
}