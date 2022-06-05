#include <stdio.h>
#include <stdlib.h>
#include "EstruturaVetores.h"




ListaPrinci Principal[TAM];


/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa
*/
void inicializar(){

  for (int i = 0; i < TAM; i++){
    Principal[i].Proximo = NULL;
    Principal[i].Qntd = 0;
    Principal[i].Tam = 0;
  }
}

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*
*/
int criarEstruturaAuxiliar(int Posicao, int Tamanho){
    
    if(Tamanho < 1){
        return TAMANHO_INVALIDO;;
    }

    if(ehPosicaoValida(Posicao)){
        return POSICAO_INVALIDA;
    }
    Posicao -= 1;
    
    if(Principal[Posicao].Proximo != NULL){
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }

    Principal[Posicao].Proximo = (int *) calloc(Tamanho, sizeof(int));
    Principal[Posicao].Tam = Tamanho;

    if(Principal[Posicao].Proximo == NULL){
        return SEM_ESPACO_DE_MEMORIA;
    }

    return SUCESSO;

}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
	  if (posicao < 1 || posicao > TAM)
	        return 1;
	    else
	        return 0;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int Posicao, int Valor){
    int Qauntidade;

    if(ehPosicaoValida(Posicao) == 1){
        return POSICAO_INVALIDA;
    }
    Posicao -= 1;
    Qauntidade = Principal[Posicao].Qntd;
  
  if(Principal[Posicao].Proximo == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }  
  
  if(Qauntidade >= Principal[Posicao].Tam){
        return SEM_ESPACO;
    }

    

    Principal[Posicao].Proximo[Qauntidade] = Valor;
    Principal[Posicao].Qntd += 1;
    
    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int Posicao){

    if(ehPosicaoValida(Posicao) == 1){
        return POSICAO_INVALIDA;
    }
    Posicao -= 1;

    if(Principal[Posicao].Proximo == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    if(Principal[Posicao].Qntd == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    Principal[Posicao].Qntd -= 1;

    return SUCESSO;

}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroEspecificoDeEstrutura(int Posicao, int Valor){
     int Existe = 0;
	    int Aux;

	    if (ehPosicaoValida(Posicao))
	        return POSICAO_INVALIDA;

	    Posicao--;

	    if (Principal[Posicao].Proximo == NULL)
	        return SEM_ESTRUTURA_AUXILIAR;

	    if (Principal[Posicao].Qntd == 0)
	        return ESTRUTURA_AUXILIAR_VAZIA;

	    int qtd = Principal[Posicao].Qntd;

	    if (qtd == 1 && Principal[Posicao].Proximo[0] == Valor)
	      Existe = 1;

	    else
	      for (int i = 0; i < qtd-1; i++)

	        if (Principal[Posicao].Proximo[i] == Valor){
	          Aux = Principal[Posicao].Proximo[i];
	          Principal[Posicao].Proximo[i] = Principal[Posicao].Proximo[i+1];
	          Principal[Posicao].Proximo[i+1] = Aux;

	          Existe = 1;
	        }

	    if (Existe == 0)
	        return NUMERO_INEXISTENTE;
	    else
	      Principal[Posicao].Qntd--;

	    return SUCESSO;
  
}    


/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/

void getDadosAux(int Posicao, int VetorAux[], int Quantidade){
     for(int i = 0; i < Quantidade; i++){
        VetorAux[i] = Principal[Posicao].Proximo[i];
    }
}

int getDadosEstruturaAuxiliar(int Posicao, int VetorAux[]){
    int i;
    int Quantidade, j;
    if(ehPosicaoValida(Posicao) == 1){
        return POSICAO_INVALIDA;
    }

    Posicao -= 1;
    Quantidade = Principal[Posicao].Qntd;
     if(Principal[Posicao].Proximo == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    getDadosAux(Posicao, VetorAux, Quantidade);
    
    return SUCESSO;
}


/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
void InsertionSort(int VetorAux[],  int Quantidade){

    int i, j, aux;
    for(i = 1; i < Quantidade; i++){
    j = i;
        while(j > 0 && VetorAux[j] < VetorAux[j - 1]){
            aux = VetorAux[j];
            VetorAux[j] = VetorAux[j - 1];
            VetorAux[j - 1] = aux;
            j -= 1;
        }

    }
}

int getDadosOrdenadosEstruturaAuxiliar(int Posicao, int VetorAux[]){
    int i;
    int Quantidade, j;
    if(ehPosicaoValida(Posicao) == 1){
        return POSICAO_INVALIDA;
    }

    Posicao -= 1;
    Quantidade = Principal[Posicao].Qntd;
     if(Principal[Posicao].Proximo == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    getDadosAux(Posicao, VetorAux, Quantidade);
    
    InsertionSort(VetorAux, Quantidade);

    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
*/


int TodasAsEstruturasAux0(){
    int Aux = 0;
    
    for(int i = 0; i < TAM; i++){
        if(Principal[i].Qntd == 0){
            Aux++;
        }
    }

    if(Aux == TAM){
        return 1;
    }

    return 0;

}

int getDadosDeTodasEstruturasAuxiliares(int VetorAux[]){
    int Quantidade;
    int j, k;
    k = 0;
    if(TodasAsEstruturasAux0()){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }

    for(int  i = 0; i < TAM; i++){
        if(Principal[i].Proximo != NULL){
            Quantidade = Principal[i].Qntd;
                for(j = 0; j < Quantidade; j++, k++){
                    VetorAux[k] = Principal[i].Proximo[j];
                }
        }
        
    }
    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
*/
int SomaQuantidades(){
    int SomaQntd = 0;
    for(int i = 0; i < TAM; i++){
        if(Principal[i].Proximo != NULL){
            SomaQntd += Principal[i].Qntd;
        }
    }

    return SomaQntd;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int VetorAux[]){
    int N;

    if(TodasAsEstruturasAux0()){
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    }

    getDadosDeTodasEstruturasAuxiliares(VetorAux);

    N = SomaQuantidades();

    InsertionSort(VetorAux, N);

    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int Posicao, int NovoTam){
  int Quantidade ;
  
  if(ehPosicaoValida(Posicao) == 1){
        return POSICAO_INVALIDA;
    }

    Posicao -= 1;

    if(Principal[Posicao].Proximo == NULL){
        return SEM_ESTRUTURA_AUXILIAR;
    }

    NovoTam += Principal[Posicao].Tam;
  
    if(NovoTam < 1){
        return NOVO_TAMANHO_INVALIDO;
    }

    Principal[Posicao].Proximo = (int*) realloc( Principal[Posicao].Proximo, NovoTam * sizeof(int));

    if( Principal[Posicao].Proximo == NULL){
        return SEM_ESPACO_DE_MEMORIA;
    }

     Principal[Posicao].Tam = NovoTam;

     Quantidade =  Principal[Posicao].Qntd;

    if(Quantidade > NovoTam){
       Principal[Posicao].Qntd = NovoTam;
    }
    else{
       Principal[Posicao].Qntd = Quantidade;
    }

    return SUCESSO;
  
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.
Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int Posicao){
    int Quantidade;

    if(ehPosicaoValida(Posicao) == 1){
        return POSICAO_INVALIDA;
    }
    Posicao -= 1;
    
    if(Principal[Posicao].Proximo == NULL){
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }

    if(Principal[Posicao].Qntd == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    Quantidade = Principal[Posicao].Qntd;

    return Quantidade;

}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.
RetorPrincipal (Principal*)
    NULL, caso não tenha nenhum número nas listas
    Principal*, ponteiro para o início da lista com cabeçote
*/
int InserirListaFim(No *Cabecote, int Valor){
    if(Cabecote == NULL){
        return 0;
    }
    No *Novo = (No*) malloc(sizeof(No));
    No *Aux;
    if(Novo){
        Novo->Conteudo = Valor;
        Novo->Prox = NULL;
            if(Cabecote->Prox == NULL){
                Cabecote->Prox = Novo;
                
                return 1;
            }
            else{
                Aux = Cabecote->Prox;
                while(Aux->Prox != NULL){
                    Aux = Aux->Prox;
                }
                Aux->Prox = Novo;
                
                return 1;
            }
    }
    return 0;
}

No *montarListaEncadeadaComCabecote(){
    No *Cabecote = (No *) malloc(sizeof(No));
    int Quantidade;
    Cabecote->Prox = NULL;

    if(TodasAsEstruturasAux0()){
        return NULL;
    }

    for(int i = 0; i < TAM; i++){
        if(Principal[i].Proximo != NULL){
            Quantidade = Principal[i].Qntd;
                for(int j = 0; j < Quantidade; j++){
                    InserirListaFim(Cabecote, Principal[i].Proximo[j]);
                }
        }
    }
    return Cabecote;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
RetorPrincipal void
*/
void getDadosListaEncadeadaComCabecote(No *Cabecote, int VetorAux[]){
    No *Aux = Cabecote->Prox;
    int i = 0;

    while(Aux){
        VetorAux[i] = Aux->Conteudo;
        Aux = Aux->Prox;
        i++;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir do início.
*/
void destruirListaEncadeadaComCabecote(No **Cabecote){

    if(Cabecote == NULL){
        return;
    }

    No *Aux = (*Cabecote)->Prox;

    while(*Cabecote != NULL){
        Aux = (*Cabecote)->Prox;

        free(*Cabecote);

        *Cabecote = Aux;
    }
    Cabecote = NULL;
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/
void finalizar(){
    for(int i = 0; i < TAM; i++){
        free(Principal[i].Proximo);
    }
}