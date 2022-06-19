#include <stdio.h>
long farotialRecursivo(long num){
    if(num <= 1){
        return 1;
    }else{
        return num * farotialRecursivo(num - 1);
    }
}
int main()
{
  long num, aux;
  
  printf("Algoritmo recursivo para calcular fatorial\n");

  printf("Digite um número: \n");
  scanf("%ld",&num);
  
  aux = farotialRecursivo(num);
  printf("%ld ",aux);
}