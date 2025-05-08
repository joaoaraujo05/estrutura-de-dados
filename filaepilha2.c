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
    f->inicio = NULL;
    f->fim = NULL;

    return f;
}

Pilha *criarPilha() {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

int isEmpty(Fila *f) {
    return f->inicio == NULL;
}

void adicionarPedidoFila(Fila *f, int codigo) {
    Pedido *pedido = (Pedido*)malloc(sizeof(Pedido));
    if (pedido == NULL) {
        printf("Erro de alocacao\n");
        return;
    }
    pedido->codigo = codigo;
    pedido->prox = NULL;

    if(f->inicio == NULL) {
        f->inicio = pedido;
        f->fim = pedido;
    } else {
        f->fim->prox = pedido ; 
        f->fim = pedido;
    }
}

int removerPedidoFila(Fila *f) {
    if(isEmpty(f)) {
        printf("Fila de pedidos vazia\n");
        return -1;
    }
    Pedido *pedido = f->inicio;
    int copia = pedido->codigo;
    f->inicio = f->inicio->prox;

    if(f->inicio == NULL) {
        f->fim = NULL;
    }

    free(pedido);

    return copia;
}

void adicionarPedidoPilha(Pilha *p, int codigo) {
    Pedido *pedido = (Pedido*)malloc(sizeof(Pedido));
    pedido->codigo = codigo;
    pedido->prox = p->topo;
    p->topo = pedido;
}

int removerPedidoPilha(Pilha *p) {
    if(p->topo == NULL) {
        printf("Pilha vazia\n");
        return -1;
    }
    Pedido *pedido = p->topo;
    int codigo = pedido->codigo;
    p->topo = p->topo->prox;
    pedido->prox = NULL;

    free(pedido);

    return codigo;
}

void imprimirFila(Fila *f) {
    Pedido *pedido = f->inicio;
    if(isEmpty(f)) {
        printf("Fila de pedidos vazia\n");
        return;
    } else {
        while(pedido != NULL) {
            printf("Pedido numero: %d\n", pedido->codigo);
            pedido = pedido->prox;
        }
    }
}

void imprimirPilha(Pilha *p) {
    Pedido *pedido = p->topo;
    if(p->topo == NULL) {
        printf("Pilha de pedidos vazia\n");
        return;
    } else {
        while(pedido != NULL) {
            printf("Pedido numero: %d\n", pedido->codigo);
            pedido = pedido->prox;
        }
    }
}

int main() {
    Fila *f = criarFila();
    Pilha *p = criarPilha();

    int codigoPedido;
    int qtd = 0;

    printf("\nDigite a quantidade de produtos que deseja adicionar a fila: ");
    scanf("%d", &qtd);

    for (int i = 0; i<qtd; i++) {
        printf("Digite o codigo do Pedido: ");
        scanf("%d", &codigoPedido);
        adicionarPedidoFila(f,codigoPedido);
    }

    puts("\nIMPRIMINDO FILA");
    imprimirFila(f);

    printf("\nDigite a quantidade de produtos que deseja remover da fila: ");
    scanf("%d", &qtd);

    int pedidoRemovido;
    for (int i = 0; i<qtd; i++) {
        printf("Removendo pedido...\n");
        pedidoRemovido = removerPedidoFila(f);
        adicionarPedidoPilha(p,pedidoRemovido);
    }

    puts("\nIMPRIMINDO PILHA");
    imprimirPilha(p);
}