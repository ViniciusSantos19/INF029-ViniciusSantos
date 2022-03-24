#include <stdio.h>
#include <stdlib.h>
void area(int b, int a){
  int area;
  area = a * b;
  printf("O valor da area é: \n %d",area);
}
int main(void) {
  int base, alt;
  int resultado;
  printf("BASE = \n");
  scanf("%d",&base);
  printf("ALTURA = \n");
  scanf("%d",&alt);
  area(base,alt);
 
  return 0;
}