#include <string.h>
#include <stdio.h>

typedef struct dma {
  int dia;
  int mes;
  int ano; 
} Data; 
typedef struct dados_aluno{
char nome[50];
char sexo; //M m para masculino e F f para feminino
char cpf[15];
int dia;
int mes;
int ano; 
}Aluno;
void Inserir_aluno(){
  Aluno aluno;
  printf("Digite o nome do alunno: \n");
  fgets(aluno.nome,50,stdin);
  size_t ln = strlen(aluno.nome) - 1;
  printf("Digite o sexo do aluno: \n");
  scanf("%c",&aluno.sexo);
  getchar();
  printf("Digite o cpf do aluno: \n");
  fgets(aluno.cpf,15,stdin);
  printf("Digite o dia de nascimento: \n");
  scanf("%d",&aluno.dia);
  printf("Digite o mes de nascimento: \n");
  scanf("%d",&aluno.mes);
  printf("Digite o ano de nascimento: \n");
  scanf("%d",&aluno.ano);
  printf("O nome do aluno é: %s \n",aluno.nome);
  printf("O sexo do aluno é: %c \n",aluno.sexo);
  printf("O cpf do aluno é: %s \n",aluno.cpf);
  printf("A data de nascimento do aluno é: %d / %d / %d \n",aluno.dia,aluno.mes,aluno.ano);
}
int main()
{
  Inserir_aluno();

}