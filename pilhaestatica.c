#include <stdlib.h>
#include <stdio.h>

#define MAX 5

typedef struct Pilha {
    int dado[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int isEmpty(const Pilha *p) {
    return p->topo == -1;
}

int isFull(const Pilha *p) {
    return p->topo == MAX - 1;
}

void push(Pilha *p, int valor) {
    if(isFull(p)) {
        printf("Pulha cheia\n");
        return;
    }
    p->dado[++p->topo] = valor;
}

int peek(const Pilha *p) {
    return p->dado[p->topo];
}

int pop(Pilha *p) {
    if(isEmpty(p)){
        printf("Pilha vazia\n");
        return -1;
    }
    return p->dado[p->topo--];
}

int main() {
    Pilha p;

    inicializar(&p);
    push(&p,5);
    push(&p,10);
    push(&p,20);

    int valorTopo = peek(&p);
    printf("Valor topo: %d", valorTopo);

    printf("\nRemovendo valor topo: \n");
    pop(&p);
    valorTopo = peek(&p);
    printf("Valor topo: %d", valorTopo);
}