/*Crie uma estrutura de fila em C para gerenciar pedidos de uma loja online. A fila deve armazenar o código do pedido (int) e o nome do produto (string de até 20 caracteres). 
Implemente as funções adicionarPedido(int codigo, char* produto) e removerPedido() seguindo o princípio FIFO (First In, First Out). Use alocação dinâmica para os nós da fila.*/

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

Fila *criarFila() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

int isEmpty(const Fila *f) {
    return f->fim == NULL;
}

void adicionarPedido(Fila *f, int codigo, char* descricao) {
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
    if (isEmpty(f)) {
        printf("Fila de pedidos vazia\n");
        return -1;
    }
    
    Pedido *newPedido = f->inicio;
    int codigo = newPedido->codigo;
    f->inicio = f->inicio->prox;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(newPedido);
    
    return codigo;
}

void imprimirPedidos(Fila *f) {
    Pedido *newPedido = f->inicio;
    if(isEmpty(f)) {
        printf("Fila de pedidos vazia\n");
        return;
    } else {
        while(newPedido != NULL) {
            printf("codigo do pedido: %d \n",newPedido->codigo);
            printf("decricao do pedido: %s \n",newPedido->descricao);
            puts("");
            newPedido = newPedido->prox;
        }
    }
}

int main() {
    Fila *f = criarFila();

    adicionarPedido(f, 123, "Hamburguer");
    adicionarPedido(f, 124, "Coca");
    adicionarPedido(f, 125, "Batata");

    printf("\nFila de pedidos: ");
    imprimirPedidos(f);
    
}