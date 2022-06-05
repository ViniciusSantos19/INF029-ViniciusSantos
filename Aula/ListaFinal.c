#include <stdio.h>
#include <stdlib.h>
typedef struct Reg{
    int Num;
    struct Reg *Proximo;
}No;

No *IniciaLista();
void ImplementaLista( No **Lista, int NumAux);
int main()
{
    No *Lista;
    Lista = IniciaLista();
    ImplementaLista(&Lista, 14);
    printf("%d ",Lista->Num);
    ImplementaLista(&Lista, 4);
    printf("%d ",Lista->Num);
    ImplementaLista(&Lista, 1);
    printf("%d ",Lista->Num);
}

No *IniciaLista(){
    return NULL;
}

void ImplementaLista( No **Lista, int NumAux){
    No *ListaAux = *Lista =  (No *) malloc(sizeof(No));;
    No *Aux, *Anterior;
    if(ListaAux){
        ListaAux->Num = NumAux;
        ListaAux->Proximo = NULL;
            if(Lista){
                *Lista = ListaAux;
            }else{
                Aux = *Lista;
                Anterior = *Lista;
                while(Aux != NULL && Aux->Num < NumAux){
                  Anterior = Aux;  
                  Aux = Aux->Proximo; 
                }
                  Anterior->Proximo = ListaAux;
            }
    }else{
        printf("erro");
    }
}