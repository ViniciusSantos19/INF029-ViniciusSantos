Mostra_tabuleiro(TabuleiroAtual);
    if(Turno == 1){
      Copia_matriz(TabuleiroJogador1, TabuleiroAtual);
      Turno = 2;
      strcpy(NomeAtual, Nome1);
    }else{
      Copia_matriz(TabuleiroJogador2, TabuleiroAtual);
      Turno = 1;
      strcpy(NomeAtual, Nome2);
    }
    /*if(Turno == 1){
      Turno = 2;
      strcpy(NomeAtual, Nome1);
    }
    else{
      Turno = 1;
      strcpy(NomeAtual, Nome2);
    }
    */

if(Turno == 1){
      Copia_matriz(TabuleiroJogador1, TabuleiroAtual);
      Turno = 2;
      strcpy(NomeAtual, Nome1);
    }else{
      Copia_matriz(TabuleiroJogador2, TabuleiroAtual);
      Turno = 1;
      strcpy(NomeAtual, Nome2);
    }
    /*if(Turno == 1){
      Turno = 2;
      strcpy(NomeAtual, Nome1);
    }
    else{
      Turno = 1;
      strcpy(NomeAtual, Nome2);
    }
    */


// int linha, coluna;
  int linhaJogada, colunaJogada;
  int aux = 0;
 while(aux > Qntd_barcos){
   printf("\n");
   do{
     printf("Jogador1 digite a linha que você gostaria de posicionar o barbo: \n");
     scanf("%d",&linhaJogada);
   }while(linhaJogada < 0 || linhaJogada > 9);

   do{
     printf("Jogador1 digite a coluna que você gostaria de posicionar o barco: \n");
     scanf("%d",&linhaJogada);
   }while(colunaJogada < 0 || colunaJogada > 9);
   if(TabuleiroJogador1[linhaJogada][colunaJogada] == 'A'){
     TabuleiroJogador1[linhaJogada][colunaJogada] =='N';
      aux++;
   }else{
     printf("Já tem um barco nessa posicao: \n");
   }
 }
  aux = 0;

 while(aux > Qntd_barcos){
   printf("\n");
   do{
     printf("Jogador2 digite a linha que você gostaria de posicionar o barco: \n");
     scanf("%d",&linhaJogada);
   }while(linhaJogada < 0 || linhaJogada > 9);

   do{
     printf("Jogador1 digite a coluna que você gos: \n");
     scanf("%d",&linhaJogada);
   }while(colunaJogada < 0 || colunaJogada > 9);
   if(TabuleiroJogador2[linhaJogada][colunaJogada] == 'B'){
     TabuleiroJogador2[linhaJogada][colunaJogada] =='N';
      aux++;
   }else{
     printf("Já tem um barco nessa posicao: \n");
   }
 } 