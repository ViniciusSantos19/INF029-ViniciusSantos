#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int somaRecursiva(int vetor[], int n);
int main()
{
    int vetor[8] = {1,2,3,4,5,6,7,8}; //36
    int tam;
    int aux;
    tam = sizeof(vetor) / sizeof(int);
    
    aux = somaRecursiva(vetor, tam);
    printf("%d ",aux);
}

int somaRecursiva(int vetor[], int n){
    if(n == 1){
        return vetor[n - 1];
    }else{
        return vetor[n - 1] + somaRecursiva(vetor, n - 1);
    }
}