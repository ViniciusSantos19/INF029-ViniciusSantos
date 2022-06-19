#include <stdio.h>
int ocorrenciaRecursiva(int num, int ocorrencia);
int main()
{
    int num, ocorrencia, aux;

    printf("Algoritmo recursivo para saber a ocorrência de um número em outro\n");
  
    printf("Digite qual número você deseja saber a ocorrência: \n");
    scanf("%d",&ocorrencia);
    
    printf("Digire um número: \n");
    scanf("%d",&num);
    
    aux = ocorrenciaRecursiva(num, ocorrencia);
    
    printf("%d",aux);
}

int ocorrenciaRecursiva(int num, int ocorrencia){
    int divide;
   
   if(num == 0){
        return 0;
    }
    
    divide = num % 10;
    
    if(divide == ocorrencia){
        return 1 + ocorrenciaRecursiva(num/10, ocorrencia);
    }
    
    return ocorrenciaRecursiva(num/10, ocorrencia);
}