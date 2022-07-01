#include <stdio.h>
void imprimeRecursivo(int num);
int main()
{
    int num;
    
    printf("Algoritmo para imprimir números de pares de 0 a N recursivamente\n");
    do{
        printf("Digite um número: \n");
        scanf("%d",&num);
    }while(num % 2 != 0);
    //coloquei o do while porque a questão falava que a função precisa receber um número par
    
    
    imprimeRecursivo(num);
}

void imprimeRecursivo(int num){
    
    if(num < 0){
        return;
    }
    
    imprimeRecursivo(num - 1);
    
    if(num % 2 == 0){
        printf("%d ",num);
    }
}