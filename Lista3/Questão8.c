#include <stdio.h>
int maximoDivisiorComumRecursivo(int num1, int num2);
int main()
{
   int num1, num2, aux;
   printf("Digite um número: \n");
   scanf("%d",&num1);
   
   printf("Digite outro número: \n");
   scanf("%d",&num2);
   
   aux =  maximoDivisiorComumRecursivo(num1, num2);
   
   printf("%d ",aux);
}

int maximoDivisiorComumRecursivo(int num1, int num2){
    if(num2 != 0){
        return maximoDivisiorComumRecursivo(num2, num1 % num2);
    }else{
        return num1;
    }
}