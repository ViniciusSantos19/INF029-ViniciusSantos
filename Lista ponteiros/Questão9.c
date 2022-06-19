#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int *ondeEstaLetra(char *palavra, char letra);
int main()
{
  char *palavra, letra;
  int *vetor;
  palavra = "Abacaxi";
  letra = 'x';
  
  vetor = ondeEstaLetra(palavra, letra);
  
  int tam = strlen(palavra);
  
  for(int i = 0; i < tam; i++){
      printf("%d ",vetor[i]);
  }
  
}

int *ondeEstaLetra(char *palavra, char letra){
    
    int *vetor;
    int tam;
    int posicao;
    tam = strlen(palavra);
    
    vetor = (int*) calloc(tam, sizeof(int));
    
    for(int  i = 0; i < tam; i++){
        
        if(letra == palavra[i]){
            posicao = i; 
        }
        
    }
    
    vetor[posicao] = 1;
    
    return vetor;
}