#include <stdio.h>
#include <stdlib.h>
int fibinacciRecursivo(int num);

int main()
{
   
   int num;
   int aux;
   
  printf("Fibonacci recrusivo\n"); 
  
  printf("Digite até onde você gostaria de calcular a sequência fibonacci: \n");
   scanf("%d",&num);
   
   
   for(int i = 0; i < num; i++){
       aux = fibinacciRecursivo(i);
   }
   printf("%d ",aux);
}

int fibinacciRecursivo(int num){
    if(num <= 0){
        return 1;
    }else{
        return fibinacciRecursivo(num - 1) + fibinacciRecursivo(num - 2);
    }
}