#include <stdio.h>
void ler3palaras(char string[10]){
    printf("Digite uma palavra: \n");
    fgets(string, 10, stdin);
}
int main()
{
   char s[10];
   ler3palaras(s);
   printf("%s ",s);
}
