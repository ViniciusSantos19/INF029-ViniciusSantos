#include <stdio.h>
#include <stdlib.h>
int soma(int a1, int b1){
  int soma;
  soma = a1 + b1;
  return soma;
}
int subtra( int b1, int c1){
  int subtra;
  subtra =  b1 - c1;
  return subtra;
}
int mult(int a1, int b1){
  int mult;
  mult = a1  * b1;
  return mult;
}
int main()
{
  int num1, num2;
  int resultado,resultado1,resultado2;
  printf("Digite um número: \n");
  scanf("%d",&num1);
  printf("Digite um número: \n");
  scanf("%d",&num2);
  resultado1= soma(num1, num2);
  printf("O resultado da soma é: %d \n",resultado1);
  resultado2= subtra(num1, num2);
  printf("O resultado da subtração é: %d \n",resultado2);
  resultado = mult(resultado1, resultado2);
  printf("O resltado da multiplicação é: %d \n",resultado);
}