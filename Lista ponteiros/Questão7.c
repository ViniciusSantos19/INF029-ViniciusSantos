#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* strcopy(char *palavra, int tam);
int main()
{
  char *palavra;
  char *nova;
  int tam;
  palavra = "abacaxi";
  tam  = strlen(palavra);
  nova = strcopy(palavra, tam);
  printf("%s",nova);
}

char* strcopy(char *palavra, int tam){
    
    char *copia;
    copia = (char*) malloc(sizeof(char));
    
    for(int  i = 0; i < tam; i++){
        
        copia[i] = palavra[i];
        
    }
    
    return copia;
}