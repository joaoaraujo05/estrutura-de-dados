/* Desenvolva um programa em C que simule um sistema de pedidos de um restaurante. Use uma fila 
para registrar pedidos (cada pedido tem um código int) e uma pilha para armazenar pedidos cancelados. 
Implemente funções para adicionar um pedido à fila, remover o pedido mais antigo da fila e adicionar 
um pedido cancelado à pilha. Teste o programa com 3 pedidos e 1 cancelamento.*/

#include<stdlib.h>
#include<stdio.h>

typedef struct Pedido {
    int codigo;
    struct Pedido *prox;
} Pedido;

typedef struct Fila {
    Pedido *inicio;
    Pedido *fim;
} Fila;

typedef struct Pilha {
    Pedido *topo;
} Pilha;

Fila *criarFila() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->fim = NULL;
    f->inicio = NULL;

    return f;
}

Pilha *criarPilha() {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;

    return p;
}

void adicionarPedido(Fila *f, int codigo) {
    Pedido *newPedido = (Pedido*)malloc(sizeof(Pedido));
    
    newPedido->codigo = codigo;
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
    Pedido *newPedido = f->inicio;

    if(f->inicio == NULL) {
        printf("Fila vazia\n");
        return -1;
    }
    
    int codigo = newPedido->codigo;
    f->inicio = f->inicio->prox;

    free(newPedido);

    return codigo;
}

void imprimirFila(Fila *f) {
    Pedido *newPedido = f->inicio;
    if (f->fim == NULL) {
        printf("Sem pedidos na fila, fila vazia\n");
        return;
    } else {
        while(newPedido != NULL) {
            printf("Pedido: %d \n",newPedido->codigo);
            newPedido = newPedido->prox;
        }
    }

}

void pushPilha(Pilha *p, int pedidoRemovido) {
    Pedido *newPedido = (Pedido*)malloc(sizeof(Pedido));
    newPedido->codigo = pedidoRemovido;
    newPedido->prox = p->topo;
    p->topo = newPedido;
}

void imprimirPilha(Pilha *p) {
    Pedido *newPedido = p->topo;
    if(p->topo == NULL) {
        printf("Pilha vazia\n");
        return;
    } else {
        while(newPedido != NULL) {
            printf("Pedido: %d\n",newPedido->codigo);
            newPedido = newPedido->prox;
        }
    }
}

int main() {
    Fila *f = criarFila();
    Pilha *p = criarPilha();

    adicionarPedido(f, 123);
    adicionarPedido(f, 124);
    adicionarPedido(f, 125);

    puts("\nIMPRIMINDO PRIMEIROS PEDIDOS\n");
    imprimirFila(f);

    puts("\nRemovendo 1 pedido");
    int pedidoRemovido = removerPedido(f);
    printf("Codigo: %d\n", pedidoRemovido);

    puts("\nIMPRIMINDO RESTO DOS PEDIDOS");
    imprimirFila(f);

    pushPilha(p, pedidoRemovido);
    puts("\nImprimindo Pilha 1 vez:");
    imprimirPilha(p);

    puts("\nRemovendo 2 pedido");
    pedidoRemovido = removerPedido(f);
    printf("Codigo: %d\n", pedidoRemovido);

    pushPilha(p, pedidoRemovido);
    puts("\nImprimindo Pilha 2 vez:");
    imprimirPilha(p);

}