#include<stdlib.h>
#include<stdio.h>

typedef struct Node {
    int dado;
    struct Node *prox;
} Node;

typedef struct Fila {
    Node *inicio;
    Node *fim;
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

void enqueue(Fila *f, int valor) {
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode->dado = valor;
    newNode->prox = NULL;

    if(f->inicio == NULL) {
        f->inicio = newNode;
    } else {
        f->fim->prox = newNode;
    }
    f->fim = newNode;
}

int dequeue(Fila *f) {
    if(isEmpty(f)) {
        printf("Fila vazia\n");
        return -1;
    }
    Node *newNode = f->inicio;
    int dado = newNode->dado;
    f->inicio = f->inicio->prox;

    if(f->inicio == NULL) {
        f->fim = NULL;
    }

    free(newNode);

    return dado;
}

void imprimirFila(Fila *f) {
    Node *newNode = f->inicio;
    if(isEmpty(f)) {
        printf("Fila vazia\n");
        return;
    } else {
        while (newNode != NULL) {
            printf("%d ", newNode->dado);
            newNode = newNode->prox;
        }
    }
}

int main() {
    Fila *f = criarFila();

    enqueue(f,5);
    enqueue(f,10);
    enqueue(f,20);

    imprimirFila(f);

    puts("\nDecrementando o primeiro valor");
    dequeue(f);
    imprimirFila(f);
}
