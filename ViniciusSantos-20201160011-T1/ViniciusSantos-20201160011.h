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
// Última atualização: 07/05/2022

// struct da questão 1
#ifndef TRABALHO1_ViniciusSantos20201160011_H
#define TRABALHO1_ViniciusSantos20201160011_H
typedef struct DQ{
    int iDia;
    int iMes;
    int iAno;
    int valido; // 0 se inválido, e 1 se válido 
} DataQuebrada;
// struct daa questão 2
typedef struct Qtd{
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;

} DiasMesesAnos;

int Q1(char Data[]);
DiasMesesAnos Q2(char data_inicial[], char data_final[]);
int Q3(char *texto, char c, int isCaseSensitive);
int Q4(char *strTexto, char *strBusca, int posicoes[30]);
int Q5(int num);
int Q6(int numerobase, int numerobusca);
DataQuebrada quebraData(char data[]);
#endif 