#include <stdio.h>
#include <stdlib.h>
int main()
{
 int aux;
 int num;
 int i;
  aux=0;
  printf("Digite um número: \n");
  scanf("%d",&num);
  for(i = 1; i <= num; i++){
      if(num % i == 0){
        aux++;
      }
  }
  if(aux==2){
    printf("O número %d é primo",num);
  }
  else
    printf("O número %d não é primo",num);
}