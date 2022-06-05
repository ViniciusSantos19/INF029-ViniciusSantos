#ifndef TRABALHO2_ESTRUTURAVETORES_H
#define TRABALHO2_ESTRUTURAVETORES_H
#define TAM 10

// enumeracoes (enum) ajudam a deixar o codigo mais legivel, possibilitando que voce de significado
// as suas constantes, para mais informacoes https://en.cppreference.com/w/c/language/enum
// as constantes do enum em sua inicialização vao representar o numero resultante da soma do valor da
// constante anterior mais 1, caso nao haja valor algum na primeira constante ela vai ser inicializada com 0
enum { TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -11, NOVO_TAMANHO_INVALIDO, NUMERO_INEXISTENTE,
       ESTRUTURA_AUXILIAR_VAZIA, TAMANHO_INVALIDO, SEM_ESPACO_DE_MEMORIA, POSICAO_INVALIDA,
       JA_TEM_ESTRUTURA_AUXILIAR, SEM_ESTRUTURA_AUXILIAR, SEM_ESPACO, SUCESSO };

// Estrutura Principal
typedef struct ListaPrinci{
	int *Proximo;
	int Tam;
	int Qntd;
}ListaPrinci;

// Estrutura Auxiliar
typedef struct no{
	int Conteudo;
	struct no *Prox;
}No;

int criarEstruturaAuxiliar(int Posicao, int Tamanho);
int inserirNumeroEmEstrutura(int Posicao, int Valor);
int excluirNumeroDoFinaldaEstrutura(int Posicao);
int excluirNumeroEspecificoDeEstrutura(int Posicao, int Valor);
int getDadosEstruturaAuxiliar(int Posicao, int VetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(int Posicao, int VetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int VetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int VetorAux[]);
int modificarTamanhoEstruturaAuxiliar(int Posicao, int NovoTam);
int getQuantidadeElementosEstruturaAuxiliar(int Posicao);
int TodasAsEstruturasAux0();
No *montarListaEncadeadaComCabecote();
void getDadosListaEncadeadaComCabecote(No *Cabecote, int VetorAux[]);
void destruirListaEncadeadaComCabecote(No **Cabecote);
int ehPosicaoValida(int Posicao);
int todasEstruturasAuxiliaresVazias();

void inicializar();
void finalizar();
void Dobrar(int *x);
void InsertionSort(int VetorAux[],  int Quantidade);






#endif  // TRABALHO2_ESTRUTURAVETORES_H