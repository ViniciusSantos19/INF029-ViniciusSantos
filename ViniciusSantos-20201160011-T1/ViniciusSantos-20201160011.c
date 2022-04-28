// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Vinícius Rodrigues dos Santos Moreira
//  email:vinicontatosq@gmail.com
//  Matrícula:20201160011
//  Semestre:2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#include "ViniciusSantos-20201160011.h"
int main(){
  
}
DataQuebrada Converte_num(char data[]){
 int i,j;
 char array_dia[3];
 char array_mes[3];
 char array_ano[5];
 DataQuebrada dq;
  for(i = 0; data[i]!= '/'; i++){
    array_dia[i] = data[i];  
  }
    if(i == 1 || i == 2){
      array_dia[i] = '\0';
    }
    else{
      dq.valido = 0;
    }
  j = i + 1;
  i = 0;
    for(;data[j] != '/'; j++){
      array_mes[i] = data[j];
      i++;
    }
  if(i == 1 || i == 2){
      array_mes[i] = '\0';
    }
    else{
      dq.valido = 0;
    }
  j = i + 1;
  i = 0;
    for(;data[j] != '/'; j++){
      array_ano[i] = data[j];
      i++;
    }
   if(i == 2 || i == 4){
      array_ano[i] = '\0';
    }
    else{
      dq.valido = 0;
    }
 dq.iDia = atoi(array_dia);
 dq.iMes = atoi(array_mes);
 dq.iAno = atoi(array_ano);

dq.valido = 1;
  return dq;
}
int Q1(char Data[]){
int checar_ano = 0, checar_mes = 0;
DataQuebrada retorno;
  retorno =  Converte_num(Data);
    if(retorno = 1)
  if(ano> 0 && ano <= 9999){
    checar_ano++;
  }
  if((dia>=1 && dia<=31) && (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)){
    checar_mes++;  
  }
  else if((dia>=1 && dia<=30) && (mes==4 || mes==6 || mes==9 || mes==11)){
    checar_mes++;  
  }
  else if((dia>=1 && dia<=29) && (mes==2) && (ano%400==0 ||(ano%4==0 && ano%100!=0))){
    checar_mes++;  
  }
  if(checar_mes !=1 || checar_ano != 1){
    return 0;  
  }
  else
    return 1;
}
int Q3(char *texto, char c, int isCaseSensitive){
  int i, qtdOcorrencias = 0;
     for(i=0;texto[i];i++)  
    {
    		if(tolower(texto[i])==tolower(c))
    	{
          qtdOcorrencias++;
		}
 	}
 	return qtdOcorrencias;
}
int Q4(char *strTexto, char *strBusca, int posicoes[30]){
  
}
int Q5(int num){
    int last_digit;
    int reverse;
    if(num < 0){
       num = num * -1;    
      }
  last_digit = num % 10;
      while(num > 0){
          reverse = reverse * 10 + num % 10;
          num = num/10;
      }
    return reverse;
}
int Q6(int num, int numerobusca){
  int Qntnumero = 0;
  int i = 0, n;
    if(num < 0){
       num = num * -1;    
      }
    while(num > 0){
       n =  num % 10;
        num = num / 10;
      if(n == numerobusca){
        Qntnumero++;
      }
        i++;
    }
  return Qntnumero;
}