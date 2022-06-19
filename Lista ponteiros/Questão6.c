#include <stdio.h>

void troca(int *a, int *b);
int main()
{
   int a = 5, b = 9;
   troca(&a, &b);
   printf("%d %d",a, b);
}

void troca(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
    
}