#include <stdio.h>
void ler3numeros(int *vet2){
    int i;
    for(i = 0; i < 3; i++){
       printf("Digite um numero: \n");
       scanf("%d",&vet2[i]);
    }
}
int main()
{
   int vet[3]={0};
   int i;
   int *p;
   ler3numeros(vet);
   for(i = 0; i < 3; i++){
    printf("%d ",vet[i]);  
   }
}
