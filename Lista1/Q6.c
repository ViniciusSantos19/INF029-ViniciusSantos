#include <stdio.h>
void ler3letras(){
  char letra1,letra2,letra3;
  printf("Digite 1 letra: \n");
  scanf("%c",&letra1);
  getchar();
  printf("Digite 1 letra: \n");
  scanf("%c",&letra2);
  getchar();
  printf("Digite 1 letra: \n");
  scanf("%c",&letra3) ;
  printf("As letras foram %c %c %c",letra1,letra2,letra3);
}
int main()
{
  ler3letras();

}