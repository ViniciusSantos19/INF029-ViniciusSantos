#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define SUCESSO_CADASTRO -1
#define ERRO_CADASTRO_MATRICULA -2
#define ERRO_CADASTRO_SEXO -3
#define ERRO_CADASTRO_CPF -4
#define ERRO_CADASTRO_NOME -5
#define ERRO_CADASTRO_DATA -6
#define ERR0_CADASTRO_SEMESTRE -7  
#define TAM_LISTA_ALUNO 5
#define TAM_LISTA_PROFESSOR 4
typedef struct dma {
  int dia;
  int mes;
  int ano; 
} Data; 
typedef struct dados_aluno{
int matricula;
char nome[50];
char sexo; //M m para masculino e F f para feminino
char cpf[15];
Data  data_nascimento;
//Struct dados_aluno *proximo;
}Aluno;
typedef struct dados_professor{
int matricula;
char nome [50];
char sexo;
char cpf[15];
Data data_nascimento;
//Strcut dados_professor *proximo;
}Professor;
typedef struct dados_materia{
char nome_mat[10];
int codigo;
int semestre;
char nome_professor[50];
//Struct dados_materia *proximo;
}Materia;
int Menu_principal();
int Menu_mostrar();
int Inserir_aluno();
void Mostrar_aluno();
int Inserir_professor();
void Mostrar_professor();
int Inserir_materia();
void Mostrar_materia();
int Validar_cpf();
int Validar_nome();
int Converter_dias();
int Validar_matricula();
int Validar_data();
int Validar_sexo();
int Validar_semestre();
void Busca_aluno();
void Busca_professor();
void Aniversario_aluno();
void Aniversario_professor();
void Mostrar_materia();
void Orderm_alfabetica_aluno();
void Ordem_sexo_aluno();
void Ordem_data_aluno();
void Orderm_alfabetica_professor();
void Ordem_sexo_professor();
void Ordem_data_professor();
int main()
{
  int retorno;
  int opcao;
  int opcao2;
  int sair = 0;// variável para finalizar o switch case
  Aluno aluno; // variável aluno do tipo struct Aluno
  int qnt_alunos = 0 ; // variável para contar a quantidade de alunos
  int qnt_professor = 0;
  Professor lista_professor[TAM_LISTA_ALUNO];
  //Professor* lista_professores[TAM_LISTA_ALUNO];
  Materia lista_materia[TAM_LISTA_PROFESSOR];
  int qnt_materias = 0;
  Aluno lista_alunos[TAM_LISTA_ALUNO]; 
  while(!sair){
    opcao = Menu_principal();
    switch(opcao){
      case 0:
      printf("Finalizando escola \n");
      sair++; 
        break;
      case 1:
      retorno = Inserir_aluno(lista_alunos, qnt_alunos);
        if(retorno == SUCESSO_CADASTRO){
          printf("Cadastro realizado com sucesso\n");
          qnt_alunos++;
        }
        else {
          switch(retorno){
            case ERRO_CADASTRO_MATRICULA:
            printf("Erro ao cadastrar a matrula");
            break;
            case ERRO_CADASTRO_SEXO:
            printf("Erro ao cadastrar os sexos");
            break;
            case ERRO_CADASTRO_DATA:
            printf("Erro ao cadrastrar o data");
            break;
            case ERRO_CADASTRO_NOME:
            printf("Erro ao cadastrar o nome");
            break;
            case ERRO_CADASTRO_CPF:
            printf("Erro ao cadastroar o cpf");
          }
        }
      break;
      case 2:{ 
      retorno = Inserir_professor(lista_professor, qnt_professor);
      if(retorno ==  SUCESSO_CADASTRO){
        printf("Cadasttro realizado com sucesso: \n");
        qnt_professor++;
      }
       else {
          switch(retorno){
            case ERRO_CADASTRO_MATRICULA:
            printf("Erro ao cadastrar a matrula");
            break;
            case ERRO_CADASTRO_SEXO:
            printf("Erro ao cadastrar os sexos");
            break;
            case ERRO_CADASTRO_DATA:
            printf("Erro ao cadrastrar o data");
            break;
            case ERRO_CADASTRO_NOME:
            printf("Erro ao cadastrar o nome");
            break;
            case ERRO_CADASTRO_CPF:
            printf("Erro ao cadastrar o cpf");
            break;
          }
        }  
      break;
      }
      case 3:{ 
      retorno = Inserir_materia(lista_materia,qnt_materias);
      if(retorno == SUCESSO_CADASTRO){
        printf("Cadastro realizado com sucesso: \n");
        qnt_materias++;
      }
        else{
          case ERRO_CADASTRO_MATRICULA:
          printf("Erro ao cadastrar o código da matéria");
          break;
          case ERRO_CADASTRO_NOME:
          printf("Erro ao cadastrar o nome");
          break;
          case ERR0_CADASTRO_SEMESTRE:
          printf("Erro ao cadastrar o semestre da matéria");
          break;
        }
      break;
      }
      case 4:{
         opcao2 = Menu_mostrar();
       switch(opcao2){
         case 1:{
           Mostrar_aluno(lista_alunos, qnt_alunos);
           break;
         }
         case 2:{
           Mostrar_professor(lista_professor, qnt_professor);
           break;
         }
         case 3:{
           Mostrar_materia(lista_materia, qnt_materias);
           break;
         }
         case 4:{
           Orderm_alfabetica_aluno(lista_alunos, qnt_alunos);
           break;
         }
         case 5:{
           Orderm_alfabetica_professor(lista_professor, qnt_professor);
           break;
         }
         case 6:{
           Ordem_data_aluno(lista_alunos, qnt_alunos);
           break;
         }
         case 7:{
           Ordem_data_professor(lista_professor, qnt_professor);
           break;
         }
         case 8:{
           Ordem_sexo_aluno(lista_alunos, qnt_alunos);
           break;
         }
         case 9:{
            Ordem_sexo_professor(lista_professor, qnt_professor);
           break;
           case 10:{
           Aniversario_aluno(lista_professor, qnt_professor);
           break;
           }
           case 11:
           Aniversario_professor(lista_professor, qnt_professor);
           break;
         }
       }
      }
      break;
    }
  }
}
int Menu_principal(){
  int opcao;
  printf("\n ### Menu Principal ### \n");
  printf("Digite - 0 para sair \n");
  printf("Digite - 1 para adicionar o  aluno \n");
  printf("Digite - 2 para adicionar o professor \n");
  printf("Digite - 3 para adicionar uma matéria \n");
  printf("Digite - 4 para abrir o menu de mostrar \n");
  scanf("%d",&opcao);
  return opcao;
}
int Menu_mostrar(){
  int opcao2;
  printf("\n ### Menu Principal ### \n");
  printf("Digite - 1 para mostras alunos \n");
  printf("Digite - 2 para mostrar os professores \n");
  printf("Digite - 3 para mostrar a matéria \n");
  printf("Digite - 4  para ordenar o nome dos alunos \n");
  printf("Digite - 5 para ordenar o nome dos professores \n ");
  printf("Digite - 6 para ordenar os alunos por data \n");
  printf("Digite - 7 para ordenar os professores por data \n");
  printf("Digite - 8 para ordenar os alunos por sexo \n");
  printf("Digite - 9 para ordenar os professores por sexo \n");
  scanf("%d",&opcao2);
  return opcao2;
}
int Inserir_aluno(Aluno lista_alunos[], int qnt_alunos){
  printf("#### Matricula do aluno #### \n");
  printf("Digite a matricula do aluno: \n");
  scanf("%d", &lista_alunos[qnt_alunos].matricula);
  getchar();
  int retorno1 = Validar_matricula(lista_alunos[qnt_alunos].matricula);
  if(retorno1 ==  0){
    return ERRO_CADASTRO_MATRICULA;
  }
  printf("Digite o nome do aluno: \n");
  fgets(lista_alunos[qnt_alunos].nome,50,stdin);
  size_t ln = strlen(lista_alunos[qnt_alunos].nome) - 1;
  if (lista_alunos[qnt_alunos].nome[ln] == '\n'){
        lista_alunos[qnt_alunos].nome[ln] = '\0';
    }
  retorno1 =  Validar_nome(lista_alunos[qnt_alunos].nome);
  if(retorno1 == 0){
   return ERRO_CADASTRO_NOME; 
  }
  printf("Digite o sexo do aluno: \n");
  scanf("%c",&lista_alunos[qnt_alunos].sexo);
  lista_alunos[qnt_alunos].sexo = 
  toupper(lista_alunos[qnt_alunos].sexo);
  getchar();
  if(lista_alunos[qnt_alunos].sexo != 'M' && lista_alunos[qnt_alunos].sexo != 'F'){
    return ERRO_CADASTRO_SEXO;
  }
  
  
  printf("Digite o cpf do aluno: \n");
   fgets(lista_alunos[qnt_alunos].cpf,15,stdin);
  ln = strlen(lista_alunos[qnt_alunos].cpf) - 1;
  if (lista_alunos[qnt_alunos].cpf[ln] == '\n')
        lista_alunos[qnt_alunos].cpf[ln] = '\0';
   // printf("\n");
  retorno1 = Validar_cpf(lista_alunos[qnt_alunos].cpf);
  if(retorno1 == 0){
    return ERRO_CADASTRO_CPF;
  }
  printf("Digite o dia do nascimento do aluno: \n");
  scanf("%d",&lista_alunos[qnt_alunos].data_nascimento.dia);
  printf("Digite o mês do nascimento do aluno: \n");
  scanf("%d",&lista_alunos[qnt_alunos].data_nascimento.mes);
  printf("Digite o ano do nascimento do aluno: \n");
  scanf("%d",&lista_alunos[qnt_alunos].data_nascimento.ano);
  getchar();
   retorno1 = Validar_data(lista_alunos[qnt_alunos].data_nascimento.ano, lista_alunos[qnt_alunos].data_nascimento.mes, lista_alunos[qnt_alunos].data_nascimento.dia);
  printf("%d ",retorno1);
  if(retorno1 == 0){
    return ERRO_CADASTRO_DATA;  
  }
  return SUCESSO_CADASTRO;
}
void Mostrar_aluno(Aluno lista_alunos[], int qnt_alunos){
  printf("\n### Alunos Cadastrasdos ####\n");
  int i;
  for(i = 0; i < qnt_alunos; i++){
    printf("\n-----\n");
    printf("Matricula: %d \n",lista_alunos[i].matricula);
    printf("Nome: %s \n",lista_alunos[i].nome);
    printf("Sexo: %c \n",lista_alunos[i].sexo);
    printf("Cpf: %s \n",lista_alunos[i].cpf);
    printf("Data: %d/ %d / %d \n",lista_alunos[i].data_nascimento.dia, lista_alunos[i].data_nascimento.mes, lista_alunos[i].data_nascimento.ano);
  }
  printf("-----\n\n");
}
int Inserir_professor(Professor lista_professor[], int qnt_professor){
  int retorno1;
  printf("Digite a matricula do professor: \n");
  scanf("%d",&lista_professor[qnt_professor].matricula);
  getchar();
  retorno1 = Validar_matricula(lista_professor[qnt_professor].matricula);
  if(retorno1 == 0){
    ERRO_CADASTRO_MATRICULA;
  }
  printf("Digite o nome do professor: \n");
  fgets(lista_professor[qnt_professor].nome,50,stdin);
  size_t ln = strlen(lista_professor[qnt_professor].nome) - 1;
  if (lista_professor[qnt_professor].nome[ln] == '\n'){
        lista_professor[qnt_professor].nome[ln] = '\0';
    }
  retorno1 = Validar_nome(lista_professor[qnt_professor].nome);
  if(retorno1 == 0){
    return ERRO_CADASTRO_NOME;
  }
  printf("Diigte o sexo do professor: \n");
  scanf("%c",&lista_professor[qnt_professor].sexo);
  lista_professor[qnt_professor].sexo = 
  toupper(lista_professor[qnt_professor].sexo);
  getchar();
  if(lista_professor[qnt_professor].sexo != 'M' && lista_professor[qnt_professor].sexo != 'F'){
    return ERRO_CADASTRO_SEXO;
  }
  //farei função para averiguar sexo
  printf("Digite o cpf do professor: \n");
  fgets(lista_professor[qnt_professor].cpf, 15, stdin);
  ln = strlen(lista_professor[qnt_professor].cpf) - 1;
  retorno1 = Validar_cpf(lista_professor[qnt_professor].cpf);
  if(retorno1 == 0){
    return ERRO_CADASTRO_CPF;
  }
  printf("Digite o dia de nascimento: \n");
  scanf("%d",&lista_professor[qnt_professor].data_nascimento.dia);
  printf("Digite o mês de nascimento: \n");
  scanf("%d",&lista_professor[qnt_professor].data_nascimento.mes);
  printf("Digite o ano do nascimento:: \n");
  scanf("%d",&lista_professor[qnt_professor].data_nascimento.ano);
  retorno1 = Validar_data(lista_professor[qnt_professor].data_nascimento.ano, lista_professor[qnt_professor].data_nascimento.mes, lista_professor[qnt_professor].data_nascimento.dia);
  printf("%d ",retorno1);
  if(retorno1 == 0){
    return ERRO_CADASTRO_DATA;  
  }
  return SUCESSO_CADASTRO;
}
void Mostrar_professor(Professor lista_professor[], int qnt_professor){
  printf("\n### Professores Cadastrasdos ####\n");
  int i;
for(i = 0; i < qnt_professor; i++){
  printf("\n-----\n");
  printf("Matricula: %d \n",lista_professor[i].matricula);
  printf("Nome: %s \n",lista_professor[i].nome);
  printf("Sexo: %c \n",lista_professor[i].sexo);
  printf("Cpf: %s \n",lista_professor[i].cpf);
  printf("Data: %d / %d / %d",lista_professor[i].data_nascimento.dia, lista_professor[i].data_nascimento.mes, lista_professor[i].data_nascimento.ano);
}
}
int Inserir_materia(Materia lista_materia[],int qnt_materia){
  //espaco para verificação
  printf("Digite o código da matéria: \n");
  scanf("%d",&lista_materia[qnt_materia].codigo);
  getchar();
  int retorno1 = Validar_matricula(lista_materia[qnt_materia].codigo);
  if(retorno1 == 0){
    return ERRO_CADASTRO_MATRICULA;
  }
  printf("Digite o nome da matéria: \n");
  fgets(lista_materia[qnt_materia].nome_mat,10,stdin);
  size_t ln = strlen(lista_materia[qnt_materia].nome_mat) - 1;
  if (lista_materia[qnt_materia].nome_mat[ln] == '\n')
        lista_materia[qnt_materia].nome_mat[ln] = '\0';
  retorno1 = Validar_nome(lista_materia[qnt_materia].nome_mat);
  if(retorno1 == 0){
    return ERRO_CADASTRO_NOME;
  }
  //espaço para a verificação
  printf("Digite o semestre da matéria: \n");
  scanf("%d",&lista_materia[qnt_materia].semestre);
  getchar();
  retorno1 = Validar_semestre(lista_materia[qnt_materia].semestre);
  if(retorno1 == 0){
    return ERR0_CADASTRO_SEMESTRE;
  }
  //espaço para a verificação
  printf("Digite o nome do professor: \n");
  fgets(lista_materia[qnt_materia].nome_professor,50,stdin);
  ln = strlen(lista_materia[qnt_materia].nome_professor) - 1;
  if (lista_materia[qnt_materia].nome_professor[ln] == '\n')
        lista_materia[qnt_materia].nome_professor[ln] = '\0';
  retorno1 = Validar_nome(lista_materia[qnt_materia].nome_professor);
  if(retorno1 == 0){
    return ERRO_CADASTRO_NOME;
  }
  return SUCESSO_CADASTRO;
}
void Mostrar_materia(Materia lista_materia[],int qnt_materia){
  printf("\n### Materia cadastrada ####\n");
  int i;
  Materia verifica_codigo;
  printf("Digite o código da matéria: \n");
  scanf("%d",&verifica_codigo.codigo);
  for(i = 0 ; i < qnt_materia; i++){
    if(verifica_codigo.codigo == lista_materia[i].codigo){
      printf("O codigo da matéria é: %d \n",lista_materia[i].codigo);
      printf("O nome da matéria é: %s \n",lista_materia[i].nome_mat);
      printf("O semestre da matéria é: %d \n",lista_materia[i].semestre);
      printf("O nome do professor é: %s \n",lista_materia[i].nome_professor);
    }
  }
  printf("-----\n\n");
}
int Validar_cpf(char cpf[]){
  int i=0,a=0,j;
   int cpf_novo[9];
   int total_d1=0;
   int total_d2=0;
  if(strlen(cpf)!=14){
    return 0;
  }
  if(cpf[3]!='.' && cpf[7] != '.' && cpf[11] != '-'){
    return 0;
  }
  /*for(i = 0; i < strlen(cpf); i++){
    if(cpf[i]!= '.' || cpf[i]!='-'){
      cpf_novo[a]=cpf[i]-48;
      a++;
    }
  }
   j = 0;
   while(j < 9){
    total_d1 = total_d1 + cpf_novo[i]*(10-j);
    total_d2 = total_d2 + cpf_novo[i]*(11-j);
    j++;
   }
   total_d1= (total_d1 * 10) % 11;
   
   total_d2= (total_d2 + (total_d1 * 2)) * 10 % 11;
   if(total_d1 > 9 || total_d2 > 9){
    total_d1 = 0;
    total_d2 = 0;
   }
   printf("%d a",cpf_novo[9]);
   printf("%d b",cpf_novo[10]);
   
   if(total_d1 == cpf_novo[9] && total_d2 == cpf_novo[10]){
    return 1;   
   }
   else {
    return 0;
     }*/
   }  

int Validar_data(int ano, int mes, int dia){
  int checar_ano = 0, checar_mes = 0;
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
  else{
    int aux = checar_mes + checar_ano;
    return aux;  
  }
}

int Validar_semestre(int semestre){
   if(semestre <= 0 || semestre > 8){
    return 0;
   }
   else
   return 1;   
}
 
int Validar_matricula(int val_matricula){
  if(val_matricula < 0  && isdigit(val_matricula)){
    return 0;
  }
  else
  return 1;
}
int Validar_nome(char val_nome[]){
  int i;
  for(i = 0; i < strlen(val_nome); i++){
    if(!isalpha(val_nome[i])){
      return 0;
    }
    else {
      return 1;
    }
  }
}
void Orderm_alfabetica_aluno(Aluno lista_aluno[], int qnt_aluno){
  int i,j;
  Aluno aux;
  for(i = 1; i < qnt_aluno; i++){
    aux= lista_aluno[i];
    j = i - 1;
    while(j >= 0 && (strcmp(aux.nome, lista_aluno[j].nome) < 0) ){
      lista_aluno[j+1]=lista_aluno[j];
      j = j - 1;
    }
    lista_aluno[j+1] = aux;
  }
  printf("\n### Ordem alfabetica ####\n");
  for(i = 0; i < qnt_aluno; i++){
    printf("O nome do aluno é %s \n",lista_aluno[i].nome);
  }
}
void Orderm_alfabetica_professor(Professor lista_professor[], int qnt_professor){
  int i,j;
  Professor aux;
  for(i = 1; i < qnt_professor; i++){
    aux= lista_professor[i];
    j = i - 1;
    while(j >= 0 && (strcmp(aux.nome, lista_professor[j].nome) < 0) ){
      lista_professor[j+1]=lista_professor[j];
      j = j - 1;
    }
    lista_professor[j+1] = aux;
  }
  printf("\n### Ordem alfabetica ####\n");
  for(i = 0; i < qnt_professor; i++){
    printf("O nome do Professor é %s \n",lista_professor[i].nome);
  }
}
void Ordem_sexo_aluno(Aluno lista_aluno[], int qnt_aluno){
  int i;
  int opcao;
  printf("Digite 1 para ver os alunos de sexo masculino \n");
  printf("Digite 2 para ver as alunas de sexo feminino \n");
  scanf("%d",&opcao);
  switch(opcao){
    case 1:
    printf("\n## Alunos do sexo masculino ##\n");
    for(i = 0; i < qnt_aluno; i++){
      if(lista_aluno[i].sexo == 'M'){
       printf("\n-----\n");
    printf("Matricula: %d \n",lista_aluno[i].matricula);
    printf("Nome: %s \n",lista_aluno[i].nome);
    printf("Sexo: %c \n",lista_aluno[i].sexo);
    printf("Cpf: %s \n",lista_aluno[i].cpf);
    printf("Data: %d/ %d / %d \n",lista_aluno[i].data_nascimento.dia, lista_aluno[i].data_nascimento.mes, lista_aluno[i].data_nascimento.ano); 
      }
    }
      break;
    case 2: 
    printf("\n## Alunas do sexo feminino ##\n");
    for(i = 0; i < qnt_aluno; i++){
      if(lista_aluno[i].sexo == 'F'){
       printf("\n-----\n");
    printf("Matricula: %d \n",lista_aluno[i].matricula);
    printf("Nome: %s \n",lista_aluno[i].nome);
    printf("Sexo: %c \n",lista_aluno[i].sexo);
    printf("Cpf: %s \n",lista_aluno[i].cpf);
    printf("Data: %d/ %d / %d \n",lista_aluno[i].data_nascimento.dia, lista_aluno[i].data_nascimento.mes, lista_aluno[i].data_nascimento.ano); 
      }
  }
    break;
    default:
    printf("Opção inválida \n");
    }
}
void Ordem_sexo_professor(Professor lista_professor[], int qnt_professor){
  int i;
  int opcao;
  printf("Digite 1 para ver os alunos de sexo masculino \n");
  printf("Digite 2 para ver as alunas de sexo feminino \n");
  scanf("%d",&opcao);
  switch(opcao){
    case 1:
    printf("\n## Professores do sexo masculino ##\n");
    for(i = 0; i < qnt_professor; i++){
      if(lista_professor[i].sexo == 'M'){
       printf("\n-----\n");
    printf("Matricula: %d \n",lista_professor[i].matricula);
    printf("Nome: %s \n",lista_professor[i].nome);
    printf("Sexo: %c \n",lista_professor[i].sexo);
    printf("Cpf: %s \n",lista_professor[i].cpf);
    printf("Data: %d/ %d / %d \n",lista_professor[i].data_nascimento.dia, lista_professor[i].data_nascimento.mes, lista_professor[i].data_nascimento.ano); 
      }
    }
      break;
    case 2:
    printf("\n## Professoras do sexo feminino ##\n");
    for(i = 0; i < qnt_professor; i++){
      if(lista_professor[i].sexo == 'F'){
       printf("\n-----\n");
    printf("Matricula: %d \n",lista_professor[i].matricula);
    printf("Nome: %s \n",lista_professor[i].nome);
    printf("Sexo: %c \n",lista_professor[i].sexo);
    printf("Cpf: %s \n",lista_professor[i].cpf);
    printf("Data: %d/ %d / %d \n",lista_professor[i].data_nascimento.dia, lista_professor[i].data_nascimento.mes, lista_professor[i].data_nascimento.ano); 
      }
  }
    break;
    default:
    printf("Opcão inválida \n");
    break;
    }
}
void Ordem_data_aluno(Aluno lista_aluno[], int qnt_aluno){
 int i,j;
  Aluno aux;
  for(i = 0; i < qnt_aluno; i++){
    aux= lista_aluno[i];
    j = i - 1;
    while(j >= 0 && (aux.data_nascimento.ano < lista_aluno[j-1].data_nascimento.ano)){
     lista_aluno[j+1]=lista_aluno[j];
      j = j - 1; 
    }
     lista_aluno[j+1] = aux;
  }
for(i = 0; i < qnt_aluno; i++){
     printf("O nome do aluno é %s \n",lista_aluno[i].nome);
    printf("Data: %d/ %d / %d \n",lista_aluno[i].data_nascimento.dia, lista_aluno[i].data_nascimento.mes, lista_aluno[i].data_nascimento.ano); 
}
}

void Ordem_data_professor(Professor lista_professor[], int qnt_professor){
 int i,j;
  Professor aux;
  for(i = 0; i < qnt_professor; i++){
    aux= lista_professor[i];
    j = i - 1;
    while(j >= 0 && (aux.data_nascimento.ano < lista_professor[j-1].data_nascimento.ano)){
     lista_professor[j+1]=lista_professor[j];
      j = j - 1; 
    }
     lista_professor[j+1] = aux;
  }
for(i = 0; i < qnt_professor; i++){
     printf("O nome do professor é %s \n",lista_professor[i].nome);
    printf("Data: %d/ %d / %d \n",lista_professor[i].data_nascimento.dia, lista_professor[i].data_nascimento.mes, lista_professor[i].data_nascimento.ano); 
}
}
void Aniversario_aluno(Aluno lista_aluno[], int qnt_aluno){
 Aluno compara;
int i;
printf("Digite o dia do aniversário: \n");
scanf("%d",&compara.data_nascimento.dia);
printf("Digite o mês do aniversário: \n");
scanf("%d",&compara.data_nascimento.mes);
printf("Digite o ano do aniversário: \n");
scanf("%d",&compara.data_nascimento.ano);
for(i = 0; i < qnt_aluno; i++){
  if((compara.data_nascimento.dia == lista_aluno[i].data_nascimento.dia) && (compara.data_nascimento.mes == lista_aluno[i].data_nascimento.mes) && (compara.data_nascimento.ano == lista_aluno[i].data_nascimento.ano )){
    printf("Feliz aniversário: %s \n",lista_aluno[i].nome);
  }
  else{
    printf("Nenhum aluno faz aniversário nessa data \n");
  }
}
}
void Aniversario_professor(Professor lista_professor[], int qnt_professor){
 Professor compara;
int i;
printf("Digite o dia do aniversário: \n");
scanf("%d",&compara.data_nascimento.dia);
printf("Digite o mês do aniversário: \n");
scanf("%d",&compara.data_nascimento.mes);
printf("Digite o ano do aniversário: \n");
scanf("%d",&compara.data_nascimento.ano);
for(i = 0; i < qnt_professor; i++){
  if((compara.data_nascimento.dia == lista_professor[i].data_nascimento.dia) && (compara.data_nascimento.mes == lista_professor[i].data_nascimento.mes) && (compara.data_nascimento.ano == lista_professor[i].data_nascimento.ano )){
    printf("Feliz aniversário: %s \n !!!",lista_professor[i].nome);
  }
  else{
    printf("Nenhum professor faz aniversário nessa data \n");
  }
}
}