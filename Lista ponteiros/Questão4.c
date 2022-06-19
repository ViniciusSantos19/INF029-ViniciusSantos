#include <stdio.h>

void maioreMenor(int vet[], int *a, int *b);
int main()
{
   int vetor[9] = {1,2,3,4,5,6,7,8,9};
   
   int a, b;
   
   maioreMenor(vetor, &a, &b);
   
   printf("O maior número é %d e o menor numero é %d",a,b);
}

void maioreMenor(int *vet, int *a, int *b){
    *a = *vet;
    *b = *vet;
    
    for(int i = 1; i < 9; i++){
        
        if(*a < *(vet + i)){
            *a = *(vet + i);
        }
        
        if(*b > *(vet + i)){
            *b = *(vet + i);
        }
    }
    
}