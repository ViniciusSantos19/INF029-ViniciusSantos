#include <stdio.h>
void imprimeRecursivo(int num);
int main()
{
    int num;
    
    printf("Algoritmo para imprimir números de N a O recursivamente\n");
    
    printf("Digite um número: \n");
    scanf("%d",&num);
    
    imprimeRecursivo(num);
}

void imprimeRecursivo(int num){
    
    if(num >= 0){
        printf("%d ",num);
        imprimeRecursivo(num - 1);
    }
}