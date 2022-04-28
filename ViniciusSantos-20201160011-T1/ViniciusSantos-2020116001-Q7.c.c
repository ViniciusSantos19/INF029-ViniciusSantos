#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#define TAM_NOME 50
#define TAM_TABULEIRO 3
void Limpa_tela();
void Menu_Principal();
void Inicializa_tabuleiro();
void Mostra_tabuleiro();
void Jogo();
void Placar();
int Verifica_tabuleiro();
void Instrucoes();
int main(){
  Menu_Principal();
}
void Menu_Principal(){
  int opcao = 2;
  char Nome1[TAM_NOME] = {"JogadorX"};
  char Nome2[TAM_NOME] = {"jogadorO"};
  while(opcao < 1 || opcao > 3)
  Limpa_tela();
  printf("Digite 1 para começar a jogar:");
  printf("\n");
  printf("Digite 2 para  ver as instruções do jogo:");
  printf("\n");
  printf("Digite 3 para fechar o jogo:");
  printf("\n");
  scanf("%d",&opcao);
  switch(opcao){
    case 1:{
      Jogo(Nome1, Nome2, 0, 0);
      break;
    }
    case 2:{
      printf("\n### REGRAS DO JOGO ###\n");
      printf("\n");
      printf("1 À vez, cada jogador coloca a sua marca onde pretender (um joga com “0”, outro jogador com “X”)");
      printf("\n");
      printf("2 O objetivo do jogo é fazer uma sequência de três símbolos iguais, seja em linha vertical, horizontal ou diagonal, enquanto tenta impedir que seu adversário faça o mesmo");
      printf("\n");
      printf("3 Quando um dos participantes faz uma linha, coluna  ou uma diagonal ganha o jogo;");
      break;
    }
    case 3:{
      printf("Você fechou o jogo");
      break;
    }
  }
}
void Inicializa_tabuleiro(char tabuleiro[3][3]){
  int linha, coluna;
  
  for(linha = 0;linha < TAM_TABULEIRO; linha++){
    for(coluna = 0; coluna < TAM_TABULEIRO; coluna++){
      tabuleiro[linha][coluna] = '-';
    }
  }

  
}
void Mostra_tabuleiro(char tabuleiro[3][3]){
  int linha, coluna;
  
  for(linha = 0;linha < TAM_TABULEIRO; linha++){
    for(coluna = 0; coluna < TAM_TABULEIRO; coluna++){
       printf("%c ",tabuleiro[linha][coluna]);
    }
    printf("\n");
  }

  
}
void Limpa_tela(){
  system("clear");
}
void Placar(int pontosX, int pontosO){
  int opcao;
  printf("Digite 1 para ver quem está vencendo: \n");
  printf("Digite 2  para ver o placar: \n");
  scanf("%d",&opcao);
  switch(opcao){
    case 1:{
       if(pontosX > pontosO){
    printf("O jogador 1 está vencendo com %d pontos",pontosX);
  }else if(pontosX == pontosO){
    printf("Empate!");
  }else {
     printf("O jogador 2 está vencendo com %d pontos",pontosO);
  }
      break;
    }
    case 2:{
        printf("\n P1 (X) %d vs P2 (O) %d",pontosX, pontosO);
      break;
      }
    default:{
      printf("Comando inválido");
      break;
    }
  }
 
  }
int  Verifica_tabuleiro(char tabuleiro[3][3]){
  int linha,colunas;
  for(linha = 0; linha < 3; linha++){
    if(tabuleiro[linha][0] == 'X' && tabuleiro[linha][1] == tabuleiro[linha][0] && tabuleiro[linha][2] == tabuleiro[linha][1]){
    return 1;
  }
  if(tabuleiro[linha][0] == 'O' && tabuleiro[linha][1] == tabuleiro[linha][0] && tabuleiro[linha][2] == tabuleiro[linha][1]){
   return 2;
  }
  }
  for(colunas = 0; colunas < 3; colunas++){
    if(tabuleiro[0][colunas] == 'X' && tabuleiro[1][colunas] == tabuleiro[0][colunas] && tabuleiro[2][colunas] == tabuleiro[1][colunas]){
   return 1;
  }
  if(tabuleiro[0][colunas] == 'O' && tabuleiro[1][colunas] == tabuleiro[0][colunas] && tabuleiro[2][colunas] == tabuleiro[1][colunas]){
    return 2;
  }
  }
  if(tabuleiro[0][0] != '-' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[2][2] == tabuleiro[1][1])
    if(tabuleiro[0][0] == 'X'){
    return 1;
    }else if(tabuleiro[0][0] == 'O'){
    return 2;
    }

    if(tabuleiro[0][2] != '-' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[2][0] == tabuleiro[1][1])
    if(tabuleiro[0][2] == 'X'){
    return 1;
    }else if(tabuleiro[0][2] == 'O'){
    return 2;
    }
  return 0;
  
}

void Jogo(char Nome1[], char Nome2[], int pontosX, int pontosO){
  char tabuleiro[3][3];
  char NomeAtual[TAM_NOME];
  int linhajogada, colunajogada;
  int turno = 1;
  int rodada = 0;
  int estadoDejogo = 1;
  int opcao;
  int PosicaoJogada;
  int Onde;
   Inicializa_tabuleiro(tabuleiro);
  while(rodada < 9 && estadoDejogo == 1){
  Limpa_tela();
  printf("\n### RODADA %d ### \n",rodada);
  Mostra_tabuleiro(tabuleiro);
  printf("\n");
  Instrucoes();
  printf("\n");
  PosicaoJogada = 0;
  int Posicoes[9][2] ={{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
   if(turno == 1){
     strcpy(NomeAtual, Nome1);
  }
  else{
   strcpy(NomeAtual, Nome2);  
  }
  do{
  printf("Jogador %s: \n",NomeAtual);
  do{
    printf("Digite a posicao que você gostaria de joga: \n");
  scanf("%d",&Onde);
  }while(Onde < 1 || Onde > 9);
  
  linhajogada = Posicoes[Onde - 1][0];
  colunajogada = Posicoes[Onde - 1][1];
    if(tabuleiro[linhajogada][colunajogada] == '-'){
    PosicaoJogada = 1;
    if(turno == 1){
    tabuleiro[linhajogada][colunajogada] = 'X';
    strcpy(NomeAtual, Nome1);
    turno = 2;
  }else{
    tabuleiro[linhajogada][colunajogada] = 'O';
    turno = 1;
  }
  }
  }while(PosicaoJogada == 0);
    
    
  
  //função que verifica quem venceu ou se empatou
  
  if(Verifica_tabuleiro(tabuleiro) == 1){
    printf("O jogador %s venceu",Nome1);
    pontosX++;
    estadoDejogo = 0;
  }
  if(Verifica_tabuleiro(tabuleiro) == 2){
    printf("O jogador %s venceu",Nome2);
    pontosO++;
    estadoDejogo = 0;
  }
    
  rodada++;
  }
  printf("\n### Fim de jogo ###\n");
  Mostra_tabuleiro(tabuleiro);
  Placar(pontosX, pontosO);
  printf("\n O que você deseja fazer? \n");
  printf("Digite 1 para jogar novamente: \n");
  printf("Digite 2 para voltar ao menu inicial (vai reiniciar o jogo): \n");
  printf("Digite 3 para sair: \n");
  scanf("%d",&opcao);
  if(opcao == 1){
    Jogo(Nome1, Nome2, pontosX, pontosO);
  }else if(opcao == 2){
    Menu_Principal();
  }
  
}
void Instrucoes(){
  printf("\nMapa de Posicoes:");
  printf("\n 1| 2 | 3");
  printf("\n 4 | 5 | 6");
  printf("\n 7 | 8 | 9");
}