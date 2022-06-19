#include <stdio.h>
long farotialRecursivo(long num){
    if(num <= 1){
        return 1;
    }else{
        return num * farotialRecursivo(num - 2);
    }
}
int main()
{
  long num, aux;
  printf("Algoritmo recursivo para calcular fatorial duplo\n");
  
  do{
      
        printf("Digite um número: \n");
        scanf("%ld",&num);
      
  }while(num % 2 == 0);
  
  aux = farotialRecursivo(num);
  printf("%ld ",aux);
}