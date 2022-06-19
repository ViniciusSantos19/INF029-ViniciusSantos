#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int x = 100, *p, **pp;
  p = &x;
  pp = &p;
  printf("Valor de pp: %d", **pp);
  //o valor será 100
  
}

