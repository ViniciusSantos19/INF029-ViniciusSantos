#include <stdio.h>
int somaRecursiva(int num);
int main()
{
    int num, aux;
    printf("Digite o número que você gostaria de soma: \n");
    scanf("%d",&num);
    
    aux = somaRecursiva(num);
    
    printf("%d ",aux);
}
int somaRecursiva(int num){
  if(num <= 1){
      return 1;
  } 
   
  if(num > 1){
        return somaRecursiva(num - 1) + num;
    }
    return num;
}