#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#define TAM_NOME 50
int Qntd_barcos = 9;
void Copia_matriz();
void Menu_principal();
void Jogo();
void Inicializa_tabuleiro();
void Mostra_tabuleiro();
void Limpa_tela();
void Posiciona_barcos();
int main(){
 Menu_principal(); 
}
void Menu_principal(){
  int Opcao = 1;
  char Nome1[TAM_NOME] = {"Jogador1"};
  char Nome2[TAM_NOME] = {"Jogador2"};
  do{
    printf("Digite 1 para iniciar o jogo: ");
    printf("\n");
    printf("Digite 2 para ver as regras do jogo: ");
    printf("\n");
    printf("Digite 3 para sair do jogo:");
    printf("\n");
    scanf("%d",&Opcao);
    switch(Opcao){
      case 1:{
        Jogo(Nome1, Nome2);
        break;
      }
      case 2:{
        printf("1 Cada jogador tem uma matriz 10 x 10");
        printf("\n");
        printf("2 Cada jogador pode posicionar %d navios de guerra",Qntd_barcos);
        printf("\n");
        printf("3 Os navios podem ser posicionado na horizontal ou na vertical, mas um navio não pode sobrepor o outro");
        printf("\n");
        printf("4 A cada rodada um jogador pode tentar atacar um ponto da matriz de outro jogador");
        printf("\n");
        printf("O jogador que destruir todos os navio inimigos primeiro vence");
        break;
      }
      case 3:{
        printf("Obrigado por jogar!");
        break;
      }
    }
  }while(Opcao < 1 || Opcao > 9);
}
void Jogo(char Nome1[], char Nome2[]){
  char Mascara1[10][10];
  char Mascara2[10][10];
  char TabuleiroJogador1[10][10];
  char TabuleiroJogador2[10][10];
  char NomeAtual[TAM_NOME];
  int linhaJogada, colunaJogada;
  int EstadodeJogo = 1;
  int PontosJ1 = 0, PontosJ2 = 0;
  int Tentativas = 0;
  int PontosAtual;
  int opcao;
  int Turno = 1;
  int Opcao;
  Inicializa_tabuleiro(TabuleiroJogador1, TabuleiroJogador2, Mascara1, Mascara2);
  
  Posiciona_barcos(TabuleiroJogador1, TabuleiroJogador2);
  while(EstadodeJogo == 1){
   Limpa_tela();
    if(Turno == 1){
        strcpy(NomeAtual, Nome1);
    }else{
        strcpy(NomeAtual, Nome2);
    }
    
    printf("\n### O jogador %s está jogando ###\n",NomeAtual);
    printf("\n### RODADA %d ###\n",Tentativas);
    
    if(Turno == 1){
      printf("\n###  tabuleiro inimigo 2 ###\n");
      Mostra_tabuleiro(Mascara2);
      printf("\n### Seu tabuleiro %d ###\n",Turno);
      Mostra_tabuleiro(TabuleiroJogador1);
      printf("\n");
    }
    if(Turno == 2){
      printf("\n###  tabuleiro inimigo 1 ###\n");
      Mostra_tabuleiro(Mascara1);
      printf("\n### Seu tabuleiro %d ###\n",Turno);
      Mostra_tabuleiro(TabuleiroJogador2);
      printf("\n");
    }
    
    
   
    do{
    printf("Digite a linha que você gostaria de atacar: \n");
    scanf("%d",&linhaJogada);
    }while(linhaJogada < 0 || linhaJogada > 9);
    do{
    printf("Digite a coluna que você gostaria de atacar: \n");
    scanf("%d",&colunaJogada); 
    }while(colunaJogada < 0 || colunaJogada >9 );
  
    if(Turno == 1){
      strcpy(NomeAtual, Nome1);
       Mascara2[linhaJogada][colunaJogada] = TabuleiroJogador2[linhaJogada][colunaJogada];
     TabuleiroJogador2[linhaJogada][colunaJogada] = '0';
    }else{
      strcpy(NomeAtual, Nome2);
      Mascara1[linhaJogada][colunaJogada] = TabuleiroJogador1[linhaJogada][colunaJogada];
     TabuleiroJogador1[linhaJogada][colunaJogada] = '0';
    }
     
    
    switch(Turno){
       case 1:
       if(Mascara2[linhaJogada][colunaJogada] == 'N'){
         PontosJ1+= 10;
         break;
       }
       case 2:{
          if(Mascara1[linhaJogada][colunaJogada] == 'N'){
         PontosJ2+= 10;
         break;
       }
       }
     }
      
    if(PontosJ1 == Qntd_barcos * 10){
        EstadodeJogo = 3;
    }else if(PontosJ2 == Qntd_barcos * 10){
     EstadodeJogo = 2;
    }
    
    if(Turno == 1){
     Turno = 2;
    }else{
     Turno = 1;
    } 
    if(Turno == 1){
       PontosAtual = PontosJ1;
    }
  if(Turno == 2){
        PontosAtual = PontosJ2;
    }
     
    
    Tentativas++;
  }
  printf("\n");
  if(EstadodeJogo == 3){
      printf("O %s venceu com %d pontos: \n",Nome1,PontosJ1);
    }else if(EstadodeJogo == 2){
      printf("O %s venceu com %d pontos: \n",Nome2,PontosJ2);
    }
  printf("Digite 1 para jogar novamente: \n");
  printf("Digite 2 para voltar ao menu principal: \n");
  printf("Digite outro número para sair do jogo: \n");
  scanf("%d",&Opcao);
  if(Opcao == 1){
    Jogo(Nome1, Nome2);
  }else if(Opcao == 2){
    Menu_principal();
  }
}
void Limpa_tela(){
  system("clear");
}
void Inicializa_tabuleiro(char TabuleiroJogador1[10][10], char TabuleiroJogador2[10][10], char Mascara1[10][10], char Mascara2[10][10]){
  int linha, coluna;
  for(linha = 0; linha < 10; linha++){
    for(coluna = 0; coluna < 10; coluna++){
      TabuleiroJogador1[linha][coluna] = '~';
      TabuleiroJogador2[linha][coluna] = '~';
      Mascara1[linha][coluna] = '*';
      Mascara2[linha][coluna] = '*';
    }
  }
}
void Mostra_tabuleiro(char TabuleiroJogadorX[10][10]){
  int linha, coluna;
  for(linha = 0; linha < 10; linha++){
    for(coluna = 0; coluna < 10; coluna++){
      printf("[%c] ",TabuleiroJogadorX[linha][coluna]);
    }
    printf("\n");
  }
}
void Posiciona_barcos(char TabuleiroJogador1[10][10], char TabuleiroJogador2[10][10]){
  int linhaJogada, colunaJogada;
  int aux = 0;
 do{
   Limpa_tela();
   do{
     printf("Jogador1 digite a linha que você gostaria de posicionar o barco %d: \n",aux);
     scanf("%d",&linhaJogada);
   }while(linhaJogada < 0 || linhaJogada > 9);

   do{
     printf("Jogador1 digite a coluna que você gostaria de posicionar o barco %d: \n",aux);
     scanf("%d",&colunaJogada);
   }while(colunaJogada < 0 || colunaJogada > 9);
   if(TabuleiroJogador1[linhaJogada][colunaJogada] == '~'){
     TabuleiroJogador1[linhaJogada][colunaJogada] = 'N';
      aux++;
   }else{
     printf("Já tem um barco nessa posicao: \n");
   }
 }while(aux < Qntd_barcos);
  aux = 0;

 do{
   Limpa_tela();
   do{
     printf("Jogador2 digite a linha que você gostaria de posicionar o barco %d: \n",aux);
     scanf("%d",&linhaJogada);
   }while(linhaJogada < 0 || linhaJogada > 9);

   do{
     printf("Jogador1 digite a coluna que você gostaria de posicionar o barco %d: \n",aux);
     scanf("%d",&colunaJogada);
   }while(colunaJogada < 0 || colunaJogada > 9);
   if(TabuleiroJogador2[linhaJogada][colunaJogada] == '~'){
     TabuleiroJogador2[linhaJogada][colunaJogada] ='N';
      aux++;
   }else{
     printf("Já tem um barco nessa posicao: \n");
   }
 }while(aux < Qntd_barcos);
}