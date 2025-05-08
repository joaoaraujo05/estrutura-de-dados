#include<stdlib.h>
#include<stdio.h>

#define MAX 5

typedef struct Pilha {
    int dado[MAX];
    int topo;
} Pilha;

int inicializar(Pilha *p) {
    return p->topo = -1;
}

int isEmpty(const Pilha *p) {
    return p->topo == -1;
}   

int isFull(const Pilha *p) {
    return p->topo == MAX - 1;
}

void push(Pilha *p, int valor) {
    if(isFull(p)){
        printf("Pilha cheia\n");
        return;
    }
    p->dado[++p->topo] = valor;
}

int peek(const Pilha *p) {
    if(isEmpty(p)){
        printf("Pilha vazia\n");
        return -1;
    }
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
    push(&p,15);

    int valorTopo = peek(&p);
    printf("Valor topo: %d",valorTopo);

    pop(&p);
    valorTopo = peek(&p);
    printf("Valor topo: %d",valorTopo);
}