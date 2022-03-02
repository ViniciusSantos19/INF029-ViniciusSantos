#include <stdio.h>
#include <stdlib.h>
int fat(int a1){
  int i,aux;
  aux=1;
  for(i = 1; i<=a1; i++){
   aux = aux * i; 
  }
  if(a1<17){
    return aux;
  }
  else{
    printf("O formtato int não comporta um numero desse tamanho");
  }
  
 
}
int main()
{
 int num;
  int resultado;
 printf("Digite um número: \n");
  scanf("%d",&num);
  resultado = fat(num);
  printf("%d",resultado);
}