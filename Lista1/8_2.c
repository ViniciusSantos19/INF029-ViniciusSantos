#include <stdio.h>
#include <stdlib.h>
#define TAM 5
int primo(int a){
  int i, aux=0;
  for(i = 1; i <= a; i++){
    if(a % i == 0){
    aux++;    
    }
  }
   if(aux==2){
        return 1;
    }
    else{
        return 0;
    }
    printf("%d",a);
  
}
int main()
{
  int i, cont=0;
  int vet1[5];
  int j,n;
  for(i = 0; i < 5; i++){
    printf("Digite um numero: \n");
    scanf("%d",&vet1[i]);
  }
  for(i = 0; i < 5; i++){
  n = vet1[i];
  if(primo(n) == 1)
  printf("%d ",n);
  }
  
 }

 

