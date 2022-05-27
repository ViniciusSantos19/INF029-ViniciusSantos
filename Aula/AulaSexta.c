#include <stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct DadosCarro{
    int ano;
    char marca[10];
    char modelo[10];
}Carro;
void InsereCarro(Carro *insere){
    printf("Digite o ano do carro: \n");
    scanf("%d",&insere->ano);
    getchar();
    printf("Digite o modelo do carro: \n");
    fgets(insere->modelo,10,stdin);
    printf("Digite a marca do carro: \n");
    fgets(insere->marca,10,stdin);
}
void MostraStruct(Carro insere){
    printf("O ano do carror é: \n %d",insere.ano);
    printf("\n");
    printf("A marca do carror é: \n %s",insere.marca);
    printf("\n");
    printf("O modelo do carror é: \n %s",insere.modelo);
}
int main()
{
   Carro carro;
   int i;
   InsereCarro(&carro);
   MostraStruct(carro);
    
}
