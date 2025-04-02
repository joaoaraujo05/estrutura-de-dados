#include<stdlib.h>
#include<stdio.h>

typedef struct Node {
    int dado;
    struct Node *prox;
} Node;

typedef struct Pilha {
    Node *topo;
} Pilha;

Pilha* criarPilha() {
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

int isEmpty(const Pilha *p) {
    return p->topo == NULL;
}

void push(Pilha *p, int valor) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->dado = valor;
    newNode->prox = p->topo;
    p->topo = newNode;
}

int peek(const Pilha *p) {
    if(isEmpty(p)) {
        printf("Pilha vazia\n");
        return -1;
    }
    return p->topo->dado;
}

int pop(Pilha *p) {
    if(isEmpty(p)) {
        printf("Pilha vazia\n");
        return -1;
    }
    Node *newNode = p->topo;
    int valorTopo = newNode->dado;
    p->topo = p->topo->prox;
    free(newNode);
    return valorTopo;
}

int main() {
    Pilha *p = criarPilha();
    push(p,5);
    push(p,10);
    push(p,20);
    push(p,30);

    int valorTopo = peek(p);
    printf("\nvalor topo %d", valorTopo);

    pop(p);
    valorTopo = peek(p);
    printf("\nvalor topo %d", valorTopo);

}