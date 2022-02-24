#include <stdio.h>
#include <stdlib.h>
int main()
{
  char nome[20];
  char matricula[10];
  int semestre;
  int i;
  printf("Digite o seu nome: \n");
  fgets(nome,20,stdin);
  printf("Digite o seu numero de matricula: \n");
  fgets(matricula,10,stdin);
  printf("Digite o semestre: \n");
  scanf("%d",&semestre);
}