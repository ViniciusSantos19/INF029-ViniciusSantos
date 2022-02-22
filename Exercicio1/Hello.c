#include <stdio.h>
#include <stdlib.h>
int main()
{
        struct pessoa{
        int idade;
        char nome[100];
        char cidade[25];
        char sexo;
        };
        struct pessoa pessoa1;
        printf("Digite o nome: \n");
        fgets(pessoa1.nome, 100, stdin);
        printf("Digite a cidade: \n");
        fgets(pessoa1.cidade, 25, stdin);
        printf("Digite a idade: \n");
        scanf("%d",&pessoa1.idade);
        while(pessoa1.sexo!='f'|| pessoa1.sexo!='m'){
        printf("Digite o sexo: \n");
        scanf("%c",&pessoa1.sexo);
        if(pessoa1.sexo =='m' || pessoa1.sexo == 'f'){
        break;    
        }
        }
        printf("Seu nome é: %s \n ",pessoa1.nome);
        printf("Sua cidade é: %s \n",pessoa1.cidade);
        printf("Sua idade é: %d \n",pessoa1.idade);
        printf("Seu sexo é: %c \n",pessoa1.sexo);
}