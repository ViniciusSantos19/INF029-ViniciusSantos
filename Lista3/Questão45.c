#include <stdio.h>
int somaDigitosRecursivo(int num);
int main()
{
    int num, aux;
    
    printf("Algoritmo recursivo para somar digitos\n");
    
    printf("Digite um número: \n");
    scanf("%d",&num);
    
    aux = somaDigitosRecursivo(num);
    
    printf("%d ",aux);
}

int somaDigitosRecursivo(int num){
    if(num <= 0){
        return 0;
    }
    
    return(num % 10 + somaDigitosRecursivo(num / 10));
}