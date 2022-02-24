#include <stdio.h>
#include <stdlib.h>
int main()
{
 int idade;
  do{
  printf("Digite a idade:\n");
  scanf("%d",&idade);
    if(idade>=18){
    printf("É de maior \n");
  }
  else{
    printf("É de menor \n");
  }
    }while(idade>0);
}