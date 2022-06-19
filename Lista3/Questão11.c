#include <stdio.h>

int multiplicacaoRecursiva(int num1, int num2);

int main()
{
   int num1, num2, aux;
   
  printf("Multiplicação recursiva\n");
  
  printf("Digite um número: \n");
   scanf("%d",&num1);
   
   printf("Digite outro número: \n");
   scanf("%d",&num2);
   
   aux = multiplicacaoRecursiva(num1, num2);
   
   printf("%d ",aux);
   
}

int multiplicacaoRecursiva(int num1, int num2){
    if(num2 == 0){
        return 1;
    }else if(num2 == 1){
        return num1;
    }
    
    return num1 + multiplicacaoRecursiva(num1, num2 - 1);
}