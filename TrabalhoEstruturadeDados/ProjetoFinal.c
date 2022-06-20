#include <stdio.h>
#include <stdlib.h>
#include "Funcoes.h"
 Compra *cabecoteCompra = NULL;
 Venda *cabecoteVenda = NULL;

int ultimaCompra = 0;
int ultimaVenda = 0;

int main(){
    menuPrincipal();
}

void limpaTela(){
    system("clear");
}

int menuPrincipal(){
    int opcao;
    int sair = 0;
    while(!sair){
        //limpaTela();
        printf("###### BEM VINDO AO PROJETO MERCADO FINANCEIRO ######\n");
        printf("\n| 1 | para inserir uma oferta");
        printf("\n| 2 | para listar  ofertas");
        printf("\n| 3 | para negociar ofertas");
        printf("\n| 4 | para sair");
        printf("\n");
        scanf("%d",&opcao);
        printf("\n");
        switch(opcao){
            case 1:
            inserirOferta();
            break;
            case 2:
            mostrarOfertas();
            break;
            case 3:
            negociarOfertas();
            break;
            case 4:
            sair = 1;
            salvarArquivoVenda();
            salvarArquivoCompra();
            finalizarPrograma();
            break;
        }
    }
    return 0;
}

void inserirOferta(){
    int opcao;
    int sair = 0;
    while(!sair){
        limpaTela();
        printf("###### MENU DE INSERÇÃO ######\n");
        printf("Voce deseja inserir  ofertas de compra ou venda?\n");
        printf("\n| 1 | para inserir  ofertas de compra via arquivo");
        printf("\n| 2 | para inserir ofertas de venda via arquivo");
        printf("\n| 4 | para inserir uma oferta de compra");
        printf("\n| 5 | para inserir uma oferta de venda");
        printf("\n| 3 | para voltar ao menu principal");
        printf("\n");
        scanf("%d",&opcao);
        printf("\n");
        switch(opcao){
            case 1:
            carregaArquivoCompra();
            printf("Você adicionou 9 ofertas de compra\n");
            printf("\n");
            sair = 1;
            break;
            case 2:
            carregaArquivoVenda();
            printf("Você adicionou 9 ofertas de venda\n");
            printf("\n");
            sair = 1;
            break;
            case 3:
            sair = 1;
            menuPrincipal;
            break;
            case 4:
            encherLista(COMPRA);
            printf("Você inseriu uma oferta de compra\n");
            printf("\n");
            sair = 1;
            break;
            case 5:
            encherLista(VENDA);
            printf("Você inseriu uma oferta de venda\n");
            printf("\n");
            sair = 1;
            break;
            default:
            printf("\n | %d | O número é inválido\n",opcao);
            break;
        }
    }
}

void inserirOfertaCompra(int papel, int quantidade, float preco){
    Compra *anteriorCompra, *atualCompra, *novoCompra;
    novoCompra = (Compra*) malloc(sizeof(Compra));
    int opcao;
    int sair = 0;
    if(novoCompra){
        
        

        novoCompra->precoCompra = preco;
        novoCompra->quantidaCompra = quantidade;
        novoCompra->papelCompra =papel;
        novoCompra->proximo = NULL;
        
        if(cabecoteCompra == NULL){
            
            cabecoteCompra = novoCompra;
            //menuPrincipal();

        }else{
            
            atualCompra = cabecoteCompra;
            anteriorCompra = cabecoteCompra;

            if(novoCompra->precoCompra < atualCompra->precoCompra){
                    cabecoteCompra = novoCompra;
                    novoCompra->proximo = atualCompra;
            }else{
                while(atualCompra != NULL && atualCompra->precoCompra <= novoCompra->precoCompra){
                anteriorCompra = atualCompra;
                atualCompra = atualCompra->proximo;
                }

                anteriorCompra->proximo = novoCompra;
                novoCompra->proximo = atualCompra;
            }
            
        }
    }else{
        printf("ERRO AO ALOCAR MEMÓRIA");
    }
}

void inserirOfertaVenda(int papel, int quantidade, float preco){
    Venda *anteriorVenda, *atualVenda, *novoVenda;
    novoVenda = (Venda*) malloc(sizeof(Venda));
    int  escolha;

    if(novoVenda){
        
        novoVenda->papelVenda = papel;
        novoVenda->quantidaVenda = quantidade;
        novoVenda->precoVenda = preco;
        novoVenda->proximo = NULL;
        
        if(cabecoteVenda == NULL){
            
            cabecoteVenda = novoVenda;
            //menuPrincipal();

        }else{

            atualVenda = cabecoteVenda;
            anteriorVenda = cabecoteVenda;

            if(novoVenda->precoVenda < atualVenda->precoVenda){
                
                cabecoteVenda = novoVenda;
                novoVenda->proximo = atualVenda;
            }
            else{
                while(atualVenda != NULL && atualVenda->precoVenda < novoVenda->precoVenda){
                anteriorVenda = atualVenda;
                atualVenda = atualVenda->proximo;
                }

                anteriorVenda->proximo = novoVenda;
                novoVenda->proximo = atualVenda;
            }
            

        }
    }else{
        printf("ERRO AO ALOCAR MEMÓRIA");
    }
}

void mostrarOfertas(){
    int opcao;
    int sair = 0;

    while(!sair){
        //limpaTela();
        printf("###### QUAL PAPEL VOCẼ DESEJA LISTAR? ######\n");
        printf("\n| 1 | para VALE3");
        printf("\n| 2 | para MGLU3");
        printf("\n| 3 | para PETR4");
        printf("\n| 4 | para voltar ao menu principal");
        printf("\n");
        scanf("%d",&opcao);

        switch(opcao){
            case VALE3:
            mostraOfertasVALE3();
            break;
            case MGLU3:
            mostrarOfertasMGLU3();
            break;
            case PETR4:
            mostrarOfertasPETR4();
            case 4:
            sair = 1;
            menuPrincipal();
            break;
            default:
            printf("\n| %d | não é um papel válido",opcao);
            break;
        }
    }
}

void mostraOfertasVALE3(){
    Venda *atualVenda = cabecoteVenda;
    Compra *atualCompra = cabecoteCompra;
    int auxCompra = 0, auxVenda = 0;
    if(cabecoteCompra == NULL || cabecoteVenda == NULL){
        
        printf("Não há um número de ofertas suficente no momento\n");
        printf("\n");
        menuPrincipal();
    
    }else{

        printf("###### PAPEL VALE3 COMPRA ######\n");

        while(atualCompra != NULL){

            if(atualCompra->papelCompra == VALE3){
                
                printf("\n***************************************");
                printf("\n*O preco da oferta de compra é: %.2f",atualCompra->precoCompra);
                printf("\n*A quantidade da oferta de compra é: %d ",atualCompra->quantidaCompra);
                printf("\n***************************************");
                printf("\n");
                auxCompra++;

            }
            atualCompra = atualCompra->proximo;

        }

        if(auxCompra == 0){
             printf("Sem ofertas de compra para esse papel no momento\n");
        }
        printf("\n");
        printf("###### PAPEL VALE3 VENDA######\n");

        while(atualVenda != NULL){

            if(atualVenda->papelVenda == VALE3){
                
                printf("\n***************************************");
                printf("\n*O preco da oferta de venda é: %.2f   ",atualVenda->precoVenda);
                printf("\n*A quantidade da oferta de venda é: %d ",atualVenda->quantidaVenda);
                printf("\n***************************************");
                printf("\n");
                auxVenda++;

            }
            atualVenda = atualVenda->proximo;

        }

        if(auxVenda == 0){
             printf("Sem ofertas de venda para esse papel no momento\n");
        }

        printf("\n");  
    }

}
void mostrarOfertasMGLU3(){
    Venda *atualVenda = cabecoteVenda;
    Compra *atualCompra = cabecoteCompra;
    int auxCompra = 0, auxVenda = 0;
    if(cabecoteCompra == NULL || cabecoteVenda == NULL){
        
        printf("Não há um número de ofertas suficente no momento\n");
        printf("\n");
        menuPrincipal();
    
    }else{

         printf("###### PAPEL MGLU3 COMPRA ######\n");


        while(atualCompra != NULL){

            if(atualCompra->papelCompra == MGLU3){
                
                 printf("\n***************************************");
                printf("\n*O preco da oferta de compra é: %.2f",atualCompra->precoCompra);
                printf("\n*A quantidade da oferta de compra é: %d",atualCompra->quantidaCompra);
                printf("\n***************************************");
                printf("\n");
                auxCompra++;

            }
            atualCompra = atualCompra->proximo;

        }

        if(auxCompra == 0){
             printf("Sem ofertas de compra para esse papel no momento\n");
        }
         printf("\n");
         printf("###### PAPEL MGLU3 VENDA ######\n");

        while(atualVenda != NULL){

            if(atualVenda->papelVenda == MGLU3){
                
                printf("\n***************************************");
                printf("\n*O preco da oferta de venda é: %.2f",atualVenda->precoVenda);
                printf("\n*A quantidade da oferta de venda é: %d",atualVenda->quantidaVenda);
                printf("\n***************************************");
                printf("\n");
                auxVenda++;

            }
            atualVenda = atualVenda->proximo;

        }
        if(auxVenda == 0){
            printf("Sem ofertas de venda para esse papel no momento\n");
        }
        printf("\n");  
    }

}

void mostrarOfertasPETR4(){
    Venda *atualVenda = cabecoteVenda;
    Compra *atualCompra = cabecoteCompra;
    int auxVenda = 0, auxCompra = 0;

    if(cabecoteCompra == NULL || cabecoteVenda == NULL){
        
        printf("Não há um número de ofertas suficente no momento\n");
        menuPrincipal();
    
    }else{

        printf("###### PAPEL PETR4  COMPRA######\n");
        
        while(atualCompra != NULL){

            if(atualCompra->papelCompra == PETR4){
                
                printf("\n***************************************");
                printf("\n*O preco da oferta de compra é: %.2f",atualCompra->precoCompra);
                printf("\n*A quantidade da oferta de compra é: %d ",atualCompra->quantidaCompra);
                printf("\n***************************************");
                printf("\n");
                auxCompra++;

            }
            atualCompra = atualCompra->proximo;

        }

        if(auxCompra == 0){
            printf("Sem ofertas de compra para esse papel no monento\n");
        }
        printf("\n");
        printf("###### PAPEL PETR4 VENDA ######\n");

        while(atualVenda != NULL){

            if(atualVenda->papelVenda == PETR4){
                
                printf("\n***************************************");
                printf("\n*O preco da oferta de venda é: %.2f",atualVenda->precoVenda);
                printf("\n*A quantidade da oferta de venda é: %d ",atualVenda->quantidaVenda);
                printf(" \n***************************************");
                printf("\n");
                auxVenda++;
            }
            atualVenda = atualVenda->proximo;

        }  

        if(auxVenda == 0){
            printf("Sem ofertas de compra para esse papel no monento\n");
        }

        printf("\n"); 
    }

    
}
void finalizarPrograma(){
    Compra *atualCompra;
    Venda *atualVenda;

    while(cabecoteCompra != NULL){
        
        atualCompra = cabecoteCompra;
        cabecoteCompra = cabecoteCompra->proximo;
        free(atualCompra);

    }

    while(cabecoteVenda != NULL){
        
        atualVenda = cabecoteVenda;
        cabecoteVenda = cabecoteVenda->proximo;
        free(atualVenda);

    }

    printf("SAIU");
    exit(0);

}

void eliminarOfertas(int posicaoVenda, int valorVenda, int posicaoCompra, int valorCompra){
    Compra *anteirorCompra,*atualCompra;
    Venda *anteriorVenda, *atualVenda;

    if(valorCompra == 0){

        if(cabecoteCompra == NULL){
            
            printf("A lista está vaiza");
            menuPrincipal();

        }else{

            if(posicaoCompra == 0){
                
                atualCompra = cabecoteCompra;
                cabecoteCompra = cabecoteCompra->proximo;
                free(atualCompra);

            }else{

                atualCompra = cabecoteCompra;
                for(int i = 0; i < posicaoCompra; i++){
                    anteirorCompra = atualCompra;
                    atualCompra = atualCompra->proximo;

                    if(atualCompra == NULL){
                        printf("Posição não encontrada\n");
                        return;
                    }

                }
                
                anteirorCompra->proximo = atualCompra->proximo;
                free(atualCompra);

            }
        }
    }


    if(valorVenda == 0){

        if(cabecoteVenda == NULL){
            
            printf("A lista está vaiza");
            menuPrincipal();

        }else{

            if(posicaoVenda == 0){
                
                atualVenda = cabecoteVenda;
                cabecoteVenda = cabecoteVenda->proximo;
                free(atualVenda);

            }else{

                atualVenda = cabecoteVenda;
                for(int i = 0; i < posicaoVenda; i++){
                    anteriorVenda = atualVenda;
                    atualVenda = atualVenda->proximo;

                    if(atualVenda == NULL){
                        printf("Posição não encontrada\n");
                        return;
                    }

                }

                anteriorVenda->proximo = atualVenda->proximo;
                free(atualVenda);

            }
        }
    }

}

void negociarOfertas(){

    Compra *atualCompra =  cabecoteCompra;
    Venda *atualVenda = cabecoteVenda;
    int sair = 0, papel, quantidade, operacao;
    float preco;

    if(cabecoteCompra == NULL || cabecoteVenda == NULL){
        printf("Sem ofertas o suficiente no momento\n");
        menuPrincipal();
    }

    while(!sair){
            limpaTela();
            printf("###### QUAL PAPEL VOCẼ DESEJA   NEGOCIAR? ######\n");
            printf("\n| 1 | para VALE3");
            printf("\n| 2 | para MGLU3");
            printf("\n| 3 | para PETR4");
            printf("\n| 4 | para voltar ao menu principal");
            printf("\n");
            scanf("%d",&papel);

            switch(papel){
                case  VALE3:
                papel = VALE3;
                sair = 1;
                break;
                case MGLU3:
                papel = MGLU3;
                sair = 1;
                break;
                case PETR4:
                papel =  PETR4;
                sair =  1;
                break;
                case 4:
                sair = 1;
                menuPrincipal();
                break;
            }
            
        }

        do{
            
            limpaTela();
            printf("Quantas ações você deseja negociar?\n");
            scanf("%d",&quantidade);

        }while(quantidade <= 0);


        do{

            limpaTela();
            printf("Qual o preço das ações?\n");
            scanf("%f",&preco);

        }while(preco <= 0);

        do{

            limpaTela();
            printf("Qual tipo de operação você desja fazer?\n");
            printf("\n| 1 | para compra");
            printf("\n| 2 | para venda");
            scanf("%d",&operacao);

        }while(operacao != COMPRA && operacao != VENDA);


        int poiscaoCompra = 0, posicaoVenda = 0;

        if(operacao == VENDA){
            
            int checa = 0;

            while(atualVenda != NULL){

                if(atualVenda->precoVenda == preco && atualVenda->papelVenda == papel){

                    checa = 1;
                    break;

                }

                posicaoVenda++;
                atualVenda = atualVenda->proximo;

            }

            if(checa == 0){
                printf("Esse pedido de venda ainda não foi cadastrado\n");
                menuPrincipal();
            }

            while(atualCompra != NULL){

                if(atualCompra->precoCompra >= preco && atualCompra->quantidaCompra > 0 && atualCompra->papelCompra == papel){

                    
                    int decisao;

                    do{

                        limpaTela();
                        printf("###### ENCONTRAMOS UM PAR PARA SUA OFERTA DE VENDA ######\n");
                        printf("\n| 1 | para continuar a transação");
                        printf("\n| 2 | para voltar ao menu principal");
                        scanf("%d",&decisao);

                    }while(decisao != SIM && decisao != NAO);

                    int restoCompra;
                    int restoVenda;

                    if(decisao == SIM){

                        if(papel == VALE3){

                            if(quantidade <= atualCompra->quantidaCompra && quantidade <= atualVenda->quantidaVenda){

                                atualCompra->quantidaCompra -= quantidade;
                                atualVenda->quantidaVenda -= quantidade;

                                restoCompra = atualCompra->quantidaCompra;
                                restoVenda = atualVenda->quantidaVenda;

                                printf("\n| VALE3 | ULTIMO PREÇO NEGOCIADO | %d | %.2f |\n",atualVenda->quantidaVenda, atualVenda->precoVenda);

                            }else{

                                printf("A quantidade de ações do pedido excede a quantidade de ofertas disponivéis\n");
                                menuPrincipal();

                            }

                            if(restoCompra == 0 || restoVenda == 0){

                                eliminarOfertas(posicaoVenda, restoCompra, poiscaoCompra, restoCompra);

                            }
                            
                            break;
                        }


                        if(papel == MGLU3){

                            if(quantidade <= atualCompra->quantidaCompra && quantidade <= atualVenda->quantidaVenda){

                                atualCompra->quantidaCompra -= quantidade;
                                atualVenda->quantidaVenda -= quantidade;

                                restoCompra = atualCompra->quantidaCompra;
                                restoVenda = atualVenda->quantidaVenda;

                                printf("\n| MGLU3 | ULTIMO PREÇO NEGOCIADO | %d | %.2f |\n",atualVenda->quantidaVenda, atualVenda->precoVenda);

                            }else{

                                printf("A quantidade de ações do pedido excede a quantidade de ofertas disponivéis\n");
                                menuPrincipal();

                            }

                            if(restoCompra == 0 || restoVenda == 0){

                                eliminarOfertas(posicaoVenda, restoCompra, poiscaoCompra, restoCompra);

                            }

                            break;

                        }

                        if(papel == PETR4){

                            if(quantidade <= atualCompra->quantidaCompra && quantidade <= atualVenda->quantidaVenda){

                                atualCompra->quantidaCompra -= quantidade;
                                atualVenda->quantidaVenda -= quantidade;

                                restoCompra = atualCompra->quantidaCompra;
                                restoVenda = atualVenda->quantidaVenda;

                                printf("\n| PETR4 | ULTIMO PREÇO NEGOCIADO | %d | %.2f |\n",atualVenda->quantidaVenda, atualVenda->precoVenda);

                            }else{

                                printf("A quantidade de ações do pedido excede a quantidade de ofertas disponivéis\n");
                                menuPrincipal();

                            }

                            if(restoCompra == 0 || restoVenda == 0){

                                eliminarOfertas(posicaoVenda, restoCompra, poiscaoCompra, restoCompra);

                            }
                            break;

                        }

                    }else{

                        menuPrincipal();

                    }

                }

                poiscaoCompra++;
                atualCompra =  atualCompra->proximo;

            }

        }

    if(operacao == COMPRA){

        int checa  = 0;

        while(atualCompra != NULL){

            if(atualCompra->precoCompra == preco && atualCompra->papelCompra == papel){

                checa = 1;
                break;

            }

            poiscaoCompra++;
            atualCompra = atualCompra->proximo;

        }

        if(checa == 0){

             printf("Esse pedido de venda ainda não foi cadastrado\n");
            menuPrincipal();

        }

        while(atualVenda != NULL){

            if(atualVenda->precoVenda == preco && atualVenda->quantidaVenda > 0 && atualVenda->papelVenda == papel){

                int decisao;

                    do{

                        limpaTela();
                        printf("###### ENCONTRAMOS UM PAR PARA SUA OFERTA DE VENDA ######\n");
                        printf("\n| 1 | para continuar a transação");
                        printf("\n| 2 | para voltar ao menu principal");
                        scanf("%d",&decisao);

                    }while(decisao != SIM && decisao != NAO);

                    int restoCompra;
                    int restoVenda;

                    if(decisao == SIM){

                        if(papel == VALE3){

                            if(quantidade <= atualVenda->quantidaVenda && quantidade <= atualCompra->quantidaCompra){

                                atualCompra->quantidaCompra -= quantidade;
                                atualVenda->quantidaVenda -= quantidade;

                                restoCompra = atualCompra->quantidaCompra;
                                restoVenda = atualVenda->quantidaVenda;

                                 printf("\n| VALE3 | ULTIMO PREÇO NEGOCIADO | %d | %.2f |\n",atualVenda->quantidaVenda, atualVenda->precoVenda);


                            }else{

                                printf("A quantidade de ações do pedido excede a quantidade de ofertas disponivéis\n");
                                menuPrincipal();

                            }
                            
                            if(restoCompra == 0 || restoVenda == 0){

                                eliminarOfertas(posicaoVenda, restoCompra, poiscaoCompra, restoCompra);

                            }

                            break;

                        }

                        if(papel == MGLU3){

                            if(quantidade <= atualVenda->quantidaVenda && quantidade <= atualCompra->quantidaCompra){

                                atualCompra->quantidaCompra -= quantidade;
                                atualVenda->quantidaVenda -= quantidade;

                                restoCompra = atualCompra->quantidaCompra;
                                restoVenda = atualVenda->quantidaVenda;

                                 printf("\n| MGLU3 | ULTIMO PREÇO NEGOCIADO | %d | %.2f |\n",atualVenda->quantidaVenda, atualVenda->precoVenda);


                            }else{

                                printf("A quantidade de ações do pdeido excede a quantidade de ofertas disponivéis\n");
                                menuPrincipal();

                            }
                            
                            if(restoCompra == 0 || restoVenda == 0){

                                eliminarOfertas(posicaoVenda, restoCompra, poiscaoCompra, restoCompra);

                            }

                            break;

                        }

                        if(papel == PETR4){

                            if(quantidade <= atualVenda->quantidaVenda && quantidade <= atualCompra->quantidaCompra){

                                atualCompra->quantidaCompra -= quantidade;
                                atualVenda->quantidaVenda -= quantidade;

                                restoCompra = atualCompra->quantidaCompra;
                                restoVenda = atualVenda->quantidaVenda;

                                 printf("\n| PETR4 | ULTIMO PREÇO NEGOCIADO | %d | %.2f |\n",atualVenda->quantidaVenda, atualVenda->precoVenda);


                            }else{

                                printf("A quantidade de ações do pdeido excede a quantidade de ofertas disponivéis\n");
                                menuPrincipal();

                            }
                            
                            if(restoCompra == 0 || restoVenda == 0){

                                eliminarOfertas(posicaoVenda, restoCompra, poiscaoCompra, restoCompra);

                            }

                            break;

                        }

                    }else{

                        menuPrincipal();

                    }

            }


            posicaoVenda++;
            atualVenda = atualVenda->proximo;

        }

    }

    menuPrincipal();
}

void carregaArquivoVenda(){
    int quantidade, papel; 
    float preco;
    FILE* arquivoVenda;
    arquivoVenda = fopen("Vendas.txt", "r");
    


    if(arquivoVenda ==  NULL){
        printf("Não foi possivel fazer a leitura do arquivo de venda\n");
        printf("\n");
        menuPrincipal();
    }

    while(fscanf(arquivoVenda, "%d %d %f", &papel, &quantidade, &preco) != -1){

        inserirOfertaVenda(papel, quantidade, preco);

    }

    fclose(arquivoVenda);

}

void carregaArquivoCompra(){
    int quantidade, papel; 
    float preco;
    FILE *file;
    file = fopen("Compras.txt", "r");
    


    if(file ==  NULL){
        printf("Não foi possivel fazer a leitura do arquivo de compra\n");
        printf("\n");
        menuPrincipal();
    }

   while (fscanf(file, "%d %d %f", &papel, &quantidade, &preco) != -1 ){

        inserirOfertaCompra(papel, quantidade, preco);

    }

    fclose(file);

}


void encherLista(int opcao){
    int papel , quantidade;
    float preco;
    int sair = 0;
    
    
             while(!sair){
            limpaTela();
            printf("###### QUAL PAPEL VOCẼ DESEJA VENDER? ######\n");
            printf("\n| 1 | para VALE3");
            printf("\n| 2 | para MGLU3");
            printf("\n| 3 | para PETR4");
            printf("\n| 4 | para voltar ao menu principal");
            printf("\n");
            scanf("%d",&papel);

            switch(papel){
                case  VALE3:
                papel = VALE3;
                sair = 1;
                break;
                case MGLU3:
                papel = MGLU3;
                sair = 1;
                break;
                case PETR4:
                papel =  PETR4;
                sair =  1;
                break;
                case 4:
                sair = 1;
                menuPrincipal();
                break;
            }
            
        }


        do{

            limpaTela();
            printf("###### QUAL É O PREÇO DA OFERTA DE VENDA? ######\n");
            scanf("%f",&preco);

        }while(preco <= 0);

        do{
            
            limpaTela();
            printf("###### QUAL É A QUANTIDADE  DE PAPEIS QUE VOCÊ DESEJA VENDER? ######\n");
            scanf("%d",&quantidade);

        }while(quantidade <= 0);

        if(opcao == VENDA){

            inserirOfertaVenda(papel, quantidade, preco);

        }

        if(opcao == COMPRA){

            inserirOfertaCompra(papel, quantidade, preco);

        }

}

void salvarArquivoCompra(){

    Compra *atualCompra = cabecoteCompra;
    FILE *file;
    file =fopen("ComprasSalvar.txt", "w");

    if(file ==  NULL){

        printf("Não foi possivel abir o arquivo\n");

    }

    while(atualCompra != NULL){

        if(atualCompra->papelCompra == VALE3){

            fprintf(file, "%s", "| VALE3 |");

        }

        if(atualCompra->papelCompra == MGLU3){

            fprintf(file, "%s", "| MGLU3 |");

        }

        if(atualCompra->papelCompra == PETR4){

            fprintf(file, "%s", "| PETR4 |");

        }

        fprintf(file, "| %d | | %.2f |\n",atualCompra->quantidaCompra, atualCompra->precoCompra);
        atualCompra = atualCompra->proximo;

    }

    fclose(file);
}

void salvarArquivoVenda(){

    Venda *atualVenda = cabecoteVenda;
    FILE *file;
    file =fopen("VendasSalvar.txt", "w");

    if(file ==  NULL){

        printf("Não foi possivel abir o arquivo\n");

    }

    while(atualVenda != NULL){

        if(atualVenda->papelVenda == VALE3){

            fprintf(file, "%s", "| VALE3 |");

        }

        if(atualVenda->papelVenda == MGLU3){

            fprintf(file, "%s", "| MGLU3 |");

        }

        if(atualVenda->papelVenda == PETR4){

            fprintf(file, "%s", "| PETR4 |");

        }

        fprintf(file, "| %d | | %.2f |\n",atualVenda->quantidaVenda, atualVenda->precoVenda);
        atualVenda = atualVenda->proximo;

    }

}