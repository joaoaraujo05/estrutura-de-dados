#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX 40

typedef struct Pedido {
    int codigo;
    char descricao[MAX];
    struct Pedido *prox;
} Pedido;

typedef struct Fila {
    Pedido *inicio;
    Pedido *fim;
} Fila;

Fila* criarFila() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

int isEmpty(const Fila *f) {
    return f->fim == NULL;
}

void adicionarPedido(Fila *f, int codigo, char *descricao) {
    Pedido *newPedido = (Pedido*)malloc(sizeof(Pedido));

    newPedido->codigo = codigo;
    strncpy(newPedido->descricao,descricao,MAX);
    newPedido->prox = NULL;

    if(f->inicio == NULL) {
        f->inicio = newPedido;
        f->fim = newPedido;
    } else {
        f->fim->prox = newPedido;
        f->fim = newPedido;
    }
}

int removerPedido(Fila *f) {
    if(isEmpty(f)) {
        printf("Fila de pedidos vazia\n");
        return -1;
    }

    Pedido *newPedido = f->inicio;
    int codigo = newPedido->codigo;
    f->inicio = f->inicio->prox;

    if(f->inicio == NULL) {
        f->fim = NULL;
    }

    free(newPedido);

    return codigo;
}

void imprimirFila(Fila *f) {
    Pedido *newPedido = f->inicio;
    
    if(isEmpty(f)) {
        printf("Fila vazia\n");
        return;
    }

    while (newPedido != NULL)
    { 
        printf("Codigo Pedido: %d", newPedido->codigo);   
        printf("Descricao pedido: %s",newPedido->descricao);
        newPedido = newPedido->prox;
    }
         
}


int main() {
    Fila *f = criarFila();

    int qtdProduto,codigoProduto;
    char descricao[MAX];

    printf("Digite a quantidade de produtos que deseja cadastrar: ");
    scanf("%d", &qtdProduto);


    for (int i = 0; i < qtdProduto; i++)
    {
        printf("Digite o codigo do produto: ");
        scanf("%d", &codigoProduto);
        getchar();
        printf("Digite o nome do produto: ");
        fgets(descricao,MAX,stdin);

        //descricao[strcspn(descricao, "\n")] = '\0';

        adicionarPedido(f,codigoProduto,descricao);
    }

    imprimirFila(f);

    return 0;

    return 0;
}