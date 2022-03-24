#include <stdio.h>
void ler3palaras(){
  int num1, num2, num3, num4;  
  printf("Digite um numero: \n");
    scanf("%d",&num1);
  printf("Digite um numero: \n");
    scanf("%d",&num2);
  printf("Digite um numero: \n");
    scanf("%d",&num3);
  printf("Digite uma numero: \n");
    scanf("%d",&num4);
}
int main()
{
  typedef struct leitura{
  int ler;
  }retorno;
  retorno ler; 
  ler = ler3palaras();
   printf("%d",ler);
}