#include <stdio.h>
#include<stdlib.h>
typedef struct DadosAluno{
    float nota1;
    float nota2;
    float nota3;
    char nome[10];
    float media;
}Aluno;
Aluno* InsereAluno(int tamanho){
    Aluno *v;
    v = (Aluno *) malloc(tamanho * sizeof(Aluno));
    return v;
}
void SortStruct(int tamanho, Aluno *vetor){
    int i, j;
    int aux, aux2;
    for(i = 0; i < tamanho; i++){
        aux = i;
        for(j = i + 1; j < tamanho; j++){
            if(vetor[j].media > vetor[aux].media){
                aux = j;
            }   
        }
        aux2 = vetor[aux].media;
        vetor[aux].media = vetor[i].media;
        vetor[i].media = aux2;
    }
}
void MostraStruct(int tamanho, Aluno *vetor){
    int i;
    for(i = 0; i < tamanho; i++){
        printf("Aluno %s:\n",vetor[i].nome);
        printf("A média foi %.2f \n",vetor[i].media);
    }
}
int main(){
    int tamanho;
    Aluno *vetor;
    int i;
    int aux = 0;
    printf("Digite o tamamnho do vetor: \n");
    scanf("%d",&tamanho);
    vetor = InsereAluno(tamanho);
    for(i = 0; i < tamanho; i++){
       printf("Aluno %d: \n",aux);
        printf("\n");
        printf("Digite a nota 1 do aluo:\n");
        scanf("%f",&vetor[i].nota1);
        printf("Digite a nota 2 do aluo:\n");
        scanf("%f",&vetor[i].nota2);
        printf("Digite a nota 3 do aluo:\n");
        scanf("%f",&vetor[i].nota3);
        getchar();
        vetor[i].media = (vetor[i].nota1 + vetor[i].nota2 + vetor[i].nota3)/3;
        aux++;
        printf("Digite o nome do aluno: \n");
        fgets(vetor[i].nome,10,stdin);
    }
    SortStruct(tamanho, vetor);
    MostraStruct(tamanho, vetor);
  free(vetor);
}
