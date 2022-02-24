#include <stdio.h>
#include <stdlib.h>
int main()
{
 int idade;
  printf("Digite a idade:\n");
  scanf("%d",&idade);
  if(idade>=18){
    printf("É de maior");
  }
  else{
    printf("É de menor");
  }
}