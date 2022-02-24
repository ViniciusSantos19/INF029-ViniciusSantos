#include <stdio.h>
#include <stdlib.h>
int main()
{
 int i,aux,num;
  aux=1;
  printf("Digite o valor do número que será fatorado: \n");
  scanf("%d",&num);
  for(i = 1; i<=num; i++){
   aux = aux * i; 
  }
  printf("O fatorial de %d é: %d",num,aux);
}