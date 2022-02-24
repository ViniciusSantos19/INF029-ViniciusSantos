#include <stdio.h>
#include <stdlib.h>
int main()
{
  int idade[2];
  int i;
  int soma;
  soma=0;
  for(i = 0; i < 2; i++){
    printf("Digite a idade: \n");
    scanf("%d",&idade[i]);
    soma=soma+idade[i];
  }
  printf("A soma das idades é: \n %d",soma);
}