#include<stdlib.h>
#include<stdio.h>

#define CAPACIDADE 5

typedef struct Fila{
    int dado[CAPACIDADE];
    int tamanho;
    int inicio;
    int fim;
}Fila;

void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

int isEmpty(const Fila *f) {
    return f->fim == -1;
}

int isFull(const Fila *f) {
    return f->inicio == CAPACIDADE - 1;
}

void enqueue(Fila *f, int valor) {
    if(isFull(f)) {
        printf("Fila cheia\n");
        return;
    }
    f->dado[f->fim] = valor;
    f->fim = (f->fim+1) % CAPACIDADE;
    f->tamanho++;
}

int peek(const Fila *f) {
    if(isEmpty(f)) {
        printf("Fila vazia\n");
        return -1;
    }
    return f->dado[f->inicio];
}

int dequeue(Fila *f) {
    if(isEmpty(f)) {
        printf("Fila vazia\n");
        return -1;
    }
    int valor = f->dado[f->inicio];
    f->inicio = (f->inicio+1) % CAPACIDADE;
    f->tamanho--;
    return valor;
}

void imprimirFila(Fila *f) {
    if(isEmpty(f)) {
        printf("fila vaiza\n");
        return;
    }
    int s,i;

    for (s = 0, i = f->inicio;
        s < f->tamanho;
        s++, i = (i + 1) % CAPACIDADE) {
            printf("%d ",f->dado[i]);
        }
}

int main() {
    Fila f;
    inicializar(&f);

    enqueue(&f,5);
    enqueue(&f,10);
    enqueue(&f,20);
    enqueue(&f,30);

    imprimirFila(&f);

    int valorInicio = peek(&f);
    printf("Valor inicio: %d\n", valorInicio);

    dequeue(&f);
    valorInicio = peek(&f);
    printf("Valor inicio: %d\n", valorInicio);
}