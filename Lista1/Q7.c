#include <string.h>
#include <stdio.h>
void ler3letras(){
  char letra1[5];
  char letra2[5];
  char letra3[5];
  printf("Digite uma palavra: \n");
  fgets(letra1,5,stdin);
  size_t ln = strlen(letra1) - 1;
  printf("Digite uma palavra: \n");
  fgets(letra2,5,stdin);
    ln = strlen(letra2) - 1;
  printf("Digite uma palavra: \n");
  fgets(letra3,5,stdin);
     ln = strlen(letra3) - 1;
  printf("As letras foram: %s \n",letra1);
  printf("As letras foram: %s \n",letra2);
  printf("As letras foram: %s \n",letra3);
}
int main()
{
  ler3letras();

}