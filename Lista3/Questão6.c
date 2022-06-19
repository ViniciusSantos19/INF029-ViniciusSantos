#include <stdio.h>
int pontenciaRecursiva(int base, int expoente);
int main()
{
   int num, expoente, aux;
   printf("Digite a base: \n");
   scanf("%d",&num);
   
   printf("Digite o expoente: \n");
   scanf("%d",&expoente);
   
   aux = pontenciaRecursiva(num, expoente);
   
   printf("%d ",aux);
}

int pontenciaRecursiva(int base, int expoente){
    if(expoente == 1){
        return base;
    }
    
    if(expoente == 0){
        return 1;
    }
    
    if(expoente > 1){
        return pontenciaRecursiva(base, expoente - 1) * base;
    }
}