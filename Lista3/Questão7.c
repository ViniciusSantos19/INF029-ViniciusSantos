#include <stdio.h>
int inverteVetor(int vetor[], int inicio, int fim);
void mostraVetor(int vetor[], int fim);
int main()
{
   int vetor[100];
   int fim;
   
   for(int i = 0; i < 100; i++){
       vetor[i] = i + 1;
   }
   
   fim = sizeof(vetor) / sizeof(int);
   
   mostraVetor(vetor,fim);
   
   inverteVetor(vetor, 0, fim - 1);
   printf("\n");
   printf("\n");
   mostraVetor(vetor,fim);
}

void mostraVetor(int vetor[], int tam){
    for(int i = 0; i < tam; i++){
        printf("%d ",vetor[i]);
    }
}

int inverteVetor(int vetor[], int inicio, int fim){
    int aux;
    
    if(fim > inicio){
        
        aux = vetor[inicio];
        vetor[inicio] = vetor[fim];
        vetor[fim] = aux;
        inverteVetor(vetor, inicio + 1, fim - 1);
        
    }
    
}