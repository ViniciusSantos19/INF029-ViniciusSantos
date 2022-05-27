//#ifndef FUNCOES_H_INCLUIDAS
#define FUNCOES_H_INCLUIDAS
typedef struct Lista{
   int Quantidade;
   float Preco;
   char Nome[10];
   struct Lista *proximo;
}Lista;
int CountVendas = 0;
int CountCompras = 0;
int CountOperacoes = 0;

void InserirListaFim(Lista **Insere, int QntdAcoes, float PrecoAcoes, char Nome[]);
void MenuPrincipal();
void LimpaTela();
void MostraLista();
void RemoverLista();
void BuscaTitulo();
int TamanhoLista();
Lista* CriaLista();

//Função de menu 
void MenuPrincipal(int *Menu){
  
  
  printf("Digite |0| para fechar o programa: \n");
  printf("\n");
  printf("Digite |1| para adicoonar uma oferta de compra: \n");
  printf("\n");
  printf("Digite |2| para adicoonar uma oferta de venda: \n");
  printf("\n");
  printf("Digite |3| para ver a lista de ofertas de compra: \n");
  printf("\n");
  printf("Digite |4| para ver a lista de ofertas de venda: \n");
  printf("\n");
  printf("Digite |5| para mostras as ofertas por título: \n");
  printf("\n");
  printf("Digite |6| para mostrar a última  operação realizada: \n");
  printf("\n");
  printf("\n**************************************\n");
  printf("\n");
  scanf("%d",Menu);
  
}

void LimpaTela(){
  system("clear");
}
//inicializa vetor
Lista *CriaLista(){
   return NULL;
}
//Percorre a lista encadeada e vái somando até o final
int TamanhoLista(Lista *Aux){
   Lista *Copia;
   int Tamamnho = 0;
   for( Copia = Aux; Copia != NULL; Copia = Copia->proximo){
      Tamamnho++;
   }
   return Tamamnho;
}
//Insere um nó no final da lista encadeada
void InserirListaFim(Lista **Insere, int QntdAcoes, float PrecoAcoes, char Nome[]){
   Lista *Copia= *Insere;
   Lista *Novo =  (Lista *)  malloc(sizeof(Lista));
   Novo->Quantidade = QntdAcoes;
   Novo->Preco = PrecoAcoes;
   strcpy(Novo->Nome,Nome);
   Novo->proximo = NULL;
   
   //Se a lista estiver vazia adiciona o primeiro nó
   if(*Insere == NULL){
    *Insere = Novo;  
   }
   else{
     Copia = *Insere;
     while(Copia->proximo){
        Copia = Copia->proximo; 
     }
     
     Copia->proximo = Novo;
    
   }
   
   
}

void MostraLista(Lista *Mostra){
   Lista *Copia;
   for( Copia = Mostra; Copia != NULL; Copia = Copia->proximo){
      printf("\n**************************************\n");
      printf("O nome do papel é: %s",Copia->Nome);
      printf("\n");
      printf("O preço do pape é: %.2f",Copia->Preco);
      printf("\n");
      printf("A quantidade de papeis é: %d",Copia->Quantidade);
      printf("\n**************************************\n");
   }
}
void BuscaTitulo(Lista *Compra, Lista *Venda, char Titulo[]){
    Lista *CopiaCompra;  //= Compra;
    Lista *CopiaVenda;//=  Venda;
    for(CopiaVenda = Venda; CopiaVenda != NULL; CopiaVenda = CopiaVenda->proximo ){
        if(strcmp(CopiaVenda->Nome,Titulo) == 0){
      printf("\n**************************************\n");
      printf("Pesquisa por Título \n");
      printf("O nome do papel é: %s",CopiaVenda->Nome);
      printf("\n");
      printf("O preço do pape é: %.2f",CopiaVenda->Preco);
      printf("\n");
      printf("A quantidade de papeis é: %d",CopiaVenda->Quantidade);
      printf("\n**************************************\n");
        }
    }

    for(CopiaCompra = Compra; CopiaCompra != NULL; CopiaCompra = CopiaCompra->proximo ){
        if(strcmp(CopiaCompra->Nome,Titulo) == 0){
      printf("\n**************************************\n");
      printf("Pesquisa por Título \n");
      printf("O nome do papel é: %s",CopiaCompra->Nome);
      printf("\n");
      printf("O preço do pape é: %.2f",CopiaCompra->Preco);
      printf("\n");
      printf("A quantidade de papeis é: %d",CopiaCompra->Quantidade);
      printf("\n**************************************\n");
        }
    }
}

//FUNCOES_H_INCLUIDAS