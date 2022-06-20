#ifndef ESTRUTURAMERCADO_H
#define ESTRUTURAMERCADO_H

#define VALE3 1
#define MGLU3 2
#define PETR4 3

#define SIM 1
#define NAO 2

#define COMPRA 1
#define VENDA 2



typedef struct  Compra{
    int idCompra;
    
    int papelCompra;

    int quantidaCompra;

    float precoCompra;

    struct Compra *proximo;
}Compra;

typedef struct  Venda{
    int idVenda;
    
    int papelVenda;

    int quantidaVenda;

    float precoVenda;

    struct Venda *proximo;
}Venda;

int menuPrincipal();
void inserirOferta();
void mostrarOfertas();
void carregaArquivoCompra();
void carregaArquivoVenda();
void inserirOfertaCompra(int papel, int quantidade, float preco);
void inserirOfertaVenda(int papel, int quantidade, float preco);
void finalizarPrograma();
void mostraOfertasVALE3();
void mostrarOfertasMGLU3();
void mostrarOfertasPETR4();
void buscaVendas();
void buscaCompras();
void escolherArquivo();
void salvarArquivoCompra();
void salvarArquivoVenda();
void negociarOfertas();
void eliminarOfertas();
void limpaTela();
void encherLista();


#endif