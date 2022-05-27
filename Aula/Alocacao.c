#include <stdio.h>
#include<stdlib.h>
int* Vet(int tamanho){
    int *v;
    v = (int *) malloc(tamanho * sizeof(int));
    return v;
}
void MostraString(int *vet, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        printf("%d ",vet[i]);
    }
}
int main()
{
   int tamanho;
   int *vetor;
   int i;
   printf("Digite o tamanho do vetor: \n");
   scanf("%d",&tamanho);
   vetor = Vet(tamanho);
   for(i = 0; i < tamanho; i++){
       vetor[i] = i  + 1;
   }
   MostraString(vetor, tamanho);
   free(vetor);
}