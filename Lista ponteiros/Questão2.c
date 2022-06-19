#include <stdio.h>

int main()

void troca(int *num1, int *num2);

{
  int x, *p;

  x = 100;
  p = x;

  printf("O valor de p é: %d \n",*p);

  //O erro está na linha 7.
  //O ponteiro p está recebendo a variável x e não o endereço de x

   char *a, *b;
   
   a = "abacate";
   b = "uva";
   
   if(a < b){
       printf("%s vem antes de %s no dicionário",a,b);
   }else{
       printf("%s vem antes de %s no dicionário",b,a);
   }
    //essa função está correta
  
}

void troca(int *num1, int *num2){

  int *swap;

  *num1 =  swap;
  *num1 = *num2;
  *num2 = swap;
  // o erro dessa função esta na linha 23
  // A variável swap foi delcarada com um ponteiro
  
}