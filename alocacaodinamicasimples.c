/*Escreva um programa em C que aloque dinamicamente uma estrutura Produto com os campos preco (float) e quantidade (int). 
Atribua valores aos campos, imprima-os e libere a memória corretamente. Explique por que a alocação dinâmica é necessária nesse caso.*/

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct Produto {
    float preco;
    int quantidade;
} Produto;

int main() {
    Produto *p = (Produto*)malloc(sizeof(Produto));
    p->preco = 10.5;
    p->quantidade = 2;
    
    printf("Preco do produto: %.2f \n", p->preco);
    printf("Quantidade do produto: %d \n", p->quantidade);

    float precoTotal = p->preco * p->quantidade;

    printf("Preco Total do produto: %.2f \n", precoTotal);
}