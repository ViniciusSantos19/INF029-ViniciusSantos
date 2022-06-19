#include <stdio.h>
#include <stdlib.h>
int inverteRecursivo(int num, int reverte);

int main()
{
   
   int num;
   int aux;
   
  printf("Inverte número de forma recursvia\n"); 
  
  printf("Digite até onde você gostaria de inverter: \n");
   scanf("%d",&num);
  // o segundo parâmetro tem que ser 0 sempre
   aux = inverteRecursivo(num,0);
   
   printf("%d ",aux);
}

int inverteRecursivo(int num, int reverte){
    if(num == 0){
        return reverte;
    }else{
        return inverteRecursivo(num/10, reverte * 10 + num % 10);
    }
    
}