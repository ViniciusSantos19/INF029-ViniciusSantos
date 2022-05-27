#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Funcoes.h"
int main(){
    Lista *Compra;
    Lista *Venda;
    int Opcao;
    int Sair = 0;
    int QuantidadeTep;
    float PrecoTemp;
    char NomeTemp[10];
    Compra = CriaLista();
    Venda = CriaLista();
    while(!Sair){
    
    MenuPrincipal(&Opcao);
    LimpaTela();

        switch(Opcao){
            case 0:
                printf("O prograa foi fechado");
                Sair = 1;
                break;
            case 1:
                printf("\n**************************************\n");
                printf("Adicionar oferta de compra: \n");
                
                printf("Digite o preço da ação: \n");
                scanf("%f",&PrecoTemp);
                printf("Digite a quantidade de ações: \n");
                scanf("%d",&QuantidadeTep);
                getchar();
                 printf("Digite o nome do papel de ações: \n");
                fgets(NomeTemp,10,stdin);

                printf("\n**************************************\n");
                    InserirListaFim(&Compra, QuantidadeTep, PrecoTemp, NomeTemp);
                break;
            case 2:
                 printf("\n**************************************\n");
                printf("Adicionar oferta de venda: \n");
               
                printf("Digite o preço da ação: \n");
                scanf("%f",&PrecoTemp);
                printf("Digite a quantidade de ações: \n");
                scanf("%d",&QuantidadeTep);
                getchar();
                 printf("Digite o nome do papel de ações: \n");
                fgets(NomeTemp,10,stdin);

                printf("\n**************************************\n");
                    InserirListaFim(&Venda, QuantidadeTep, PrecoTemp, NomeTemp);
                break;
            case 3:
                MostraLista(Compra);
                break;
            case 4:
                MostraLista(Venda);
                break;
            case 5:
                printf("Digite o título que você gostaria de pesquisar: \n");
                fgets(NomeTemp,10,stdin);
                    BuscaTitulo(Compra,Venda,NomeTemp);
                break;
            default:
                printf("Número inválido\n");
                break;
        }
    }
}
