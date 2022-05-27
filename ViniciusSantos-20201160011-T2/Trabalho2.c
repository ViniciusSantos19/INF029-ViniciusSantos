#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Funcoes.h"
int main(){
    ListaPrinci *Vetor;
    Vetor = IniciaLista();
    int Posicao;
    int Sair = 0;
    int Opcao;
    int Tamanho;
    int Aumenta;
    ZeraTamanhosCheca(Vetor);
    while(!Sair){
        
        MenuPrincipal(&Opcao);
        LimpaTela();

            switch(Opcao){
                case 0:
                    printf("Fim do pro ");
                    free(Vetor);
                    Sair++;
                    break;
                case 1:
                    do{
                        LimpaTela();
                        printf("Digite o a posição que você gostaria de iniciar um vetor auxiliar: \n");
                        scanf("%d",&Posicao);
                    }while((Posicao < 1) ||  (Posicao > 10));
                    Posicao--;
                    if(Vetor[Posicao].proximo == NULL){
                    do{
                        LimpaTela();
                        printf("Digite o tamanho do vetor: \n");
                        scanf("%d",&Tamanho);
                    }while((Tamanho < 1) || (Tamanho > 50));
                        Vetor[Posicao].Tamanho = Tamanho;
                        IniciaListaAux(Posicao, Vetor, Tamanho);
                    }
                    else{
                        printf("Já foi iniciado: \n");
                    }
                    break;
                case 2:
                     do{
                        LimpaTela();
                        printf("Digite o a posição que você gostaria de adicionar um número: \n");
                        scanf("%d",&Posicao);
                    }while((Posicao < 1) ||  (Posicao > 10));
                    Posicao -= 1;
                    if(Vetor[Posicao].proximo != NULL && Vetor[Posicao].Qntd < Vetor[Posicao].Tamanho){
                    InserirNumeroEmEstruturaAuxiliar(Vetor, Posicao, Vetor[Posicao].Qntd);
                    Vetor[Posicao].Qntd += 1;
                    }
                    else{
                        printf("O vetor secundário não foi inicializado");
                    }
                    break;
                case 3:
                    MostraVetor(Vetor, Vetor->Qntd);
                case 4:
                    do{
                         LimpaTela();
                        printf("Digite  a posição que você gostaria de aumentar o vetor auxiliar: \n");
                        scanf("%d",&Posicao);
                    }while((Posicao < 1) ||  (Posicao > 10));
                    Posicao -= 1;

                    RealocaVetAux(Vetor, &Vetor[Posicao].Tamanho, Posicao);
                    break;

    }
    }
}

ListaPrinci  *IniciaLista(){
    ListaPrinci *V;
    V = (ListaPrinci *) calloc(TAM, sizeof(ListaPrinci));
    return V;
}
void ZeraTamanhosCheca(ListaPrinci *Vetor){
    int i;
    for(i = 0; i < TAM; i++){
        Vetor[i].Tamanho = 0;
        Vetor[i].Qntd = 0;
        Vetor[i].proximo = NULL;
    }
}
void MostraVetor(ListaPrinci *Vetor, int Qntd){
    int i, j;
    for(i = 0; i < TAM ; i++){
        for(j = 0; j <  Vetor[i].Qntd; j++){
        printf("%d ",Vetor[i].proximo[j]);
        } 
        printf("\n");
    }
}
void MenuPrincipal(int *Opcao){
    printf("\n * * * * * * * * * * * * * * * * * * * \n");
    printf("Digite |0| para fechar o programa: \n");
    printf("\n");
    printf("Digite |1| para iniciar um vetor auxiliar: \n");
    printf("\n");
    printf("Digite |2| para posicionar um número em uma posicão de um vetor secundário: \n");
    printf("\n");
    printf("Digite |3| para imprimir os elementos de forma ordenada: \n");
    printf("\n");
    printf("Digite |4| para aumentar o tamanho do vetor auxiliar: \n");
    printf("\n * * * * * * * * * * * * * * * * * * * \n");
    scanf("%d",Opcao);
    
}
void LimpaTela(){
    system("clear");
}
void IniciaListaAux(int Posicao, ListaPrinci *Lista, int Tamanho){
    Lista[Posicao].proximo = (int *) calloc(Tamanho,  sizeof(int));
} 
void InserirNumeroEmEstruturaAuxiliar(ListaPrinci *Vetor, int Posicao, int Qnt){
    int i;

        printf("Digite um número: \n");
        scanf("%d",&Vetor[Posicao].proximo[Qnt]);
        
    
}
void RealocaVetAux(ListaPrinci *Vetor,  ListaPrinci *VetorTam, int Posicao){
    int Aumenta;
    do{
        printf("Digite o quanto você gostaria  de auentar o vetor auxiliar");
                        scanf("%d",&Aumenta);
        }while(Aumenta <= 0);
    Vetor[Posicao].proximo = (int *) realloc(Vetor[Posicao].proximo, (*VetorTam[Posicao].Tamanho + Aumenta)*sizeof(int));
}
