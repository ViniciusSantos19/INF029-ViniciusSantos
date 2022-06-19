#include <stdio.h>
void imprimeRecursivo(int num);
int main()
{
    int num;
    
    printf("Algoritmo para imprimir números de 0 a N recursivamente\n");
    
    printf("Digite um número: \n");
    scanf("%d",&num);
    
    imprimeRecursivo(num);
}

void imprimeRecursivo(int num){
    
    if(num >= 0){
        imprimeRecursivo(num - 1);
        printf("%d ",num);
    }
}