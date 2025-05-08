// Alunos: Adrian Faifer Fantozi - 842423, Davi Monsalves Tunes - 842289, Fabio Dellaspora Coral - 842538, Joao Pedro Leme Araujo - 842123

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Caminhao {
    char conteudo[30];
    struct Caminhao* anterior;
    struct Caminhao* proximo;
} Caminhao;

typedef struct Deque {
    Caminhao* frente;
    Caminhao* tras;
} Deque;

Caminhao *criarNo(const char* conteudo) {
    Caminhao* novoCaminhao = (Caminhao*)malloc(sizeof(Caminhao));
    strcpy(novoCaminhao->conteudo, conteudo);
    novoCaminhao->anterior = NULL;
    novoCaminhao->proximo = NULL;
    return novoCaminhao;
}

Deque *criarDeque() {
    Deque* novoDeque = (Deque*)malloc(sizeof(Deque));
    novoDeque->frente = NULL;
    novoDeque->tras = NULL;
    return novoDeque;
}

void adicionarNormal(Deque* deque, const char* conteudo) {
    Caminhao* novoCaminhao = criarNo(conteudo);
    if (deque->frente == NULL) {
        deque->frente = deque->tras = novoCaminhao;
    } else {
        deque->tras->proximo = novoCaminhao;
        novoCaminhao->anterior = deque->tras;
        deque->tras = novoCaminhao;
    }
}

void adicionarUrgente(Deque* deque, const char* conteudo) {
    Caminhao* novoCaminhao = criarNo(conteudo);
    if (deque->frente == NULL) {  // Se a fila estiver vazia
        deque->frente = deque->tras = novoCaminhao;
    } else {
        novoCaminhao->proximo = deque->frente;
        deque->frente->anterior = novoCaminhao;
        deque->frente = novoCaminhao;
    }
}

void descarregar(Deque* deque) {
    if (deque->frente == NULL) {
        printf("FILA DE CAMINHAO VAZIA !!!\n");
        return;
    }
    
    Caminhao* temp = deque->frente;
    printf("\nDESCARREGANDO CAMINHAO QUE CONTEM: %s\n", temp->conteudo);
    
    deque->frente = deque->frente->proximo;
    if (deque->frente != NULL) {
        deque->frente->anterior = NULL;
    } else {
        deque->tras = NULL;  
    }

    free(temp);
}

void removerFinal(Deque* deque) {
    if (deque->tras == NULL) {
        printf("FILA DE CAMINHAO VAZIA !!!\n");
        return;
    }

    Caminhao* temp = deque->tras;
    printf("\nREMOVENDO CAMINHAO NO FINAL QUE CONTEM: %s\n", temp->conteudo);

    deque->tras = deque->tras->anterior;
    if (deque->tras != NULL) {
        deque->tras->proximo = NULL;
    } else {
        deque->frente = NULL;
    }

    free(temp);
}

void exibirFila(Deque* deque) {
    Caminhao* temp = deque->frente;

    if (deque->frente == NULL) {
        printf("FILA VAZIA\n");
        return;
    } else {
        system("cls");
        printf("\nFILA DE CAMINHOES\n");
        while (temp != NULL) {
            printf("\n--------------------------------------------\n");
            printf("\tCAMINHAO COM CARGA: %s\n", temp->conteudo);
            printf("--------------------------------------------\n");
            temp = temp->proximo;
        }
        printf("\n");
    }
}

int main() {
    Deque* deque = criarDeque();
    
    int opcao;
    char conteudo[30];
    
    /*        
    ______            __             __            __        ______                _       __                   
   / ____/___  ____  / /__________  / /__     ____/ /__     / ____/___ _____ ___  (_)___  / /_  ____  ___  _____
  / /   / __ \/ __ \/ __/ ___/ __ \/ / _ \   / __  / _ \   / /   / __ `/ __ `__ \/ / __ \/ __ \/ __ \/ _ \/ ___/
 / /___/ /_/ / / / / /_/ /  / /_/ / /  __/  / /_/ /  __/  / /___/ /_/ / / / / / / / / / / / / / /_/ /  __(__  ) 
 \____/\____/_/ /_/\__/_/   \____/_/\___/   \__,_/\___/   \____/\__,_/_/ /_/ /_/_/_/ /_/_/ /_/\____/\___/____/  
                                                                                                                
    */

    do {
        printf("\n==================================================================\n");
        printf("\tCONTROLE DE CAMINHOES - SISTEMA DE FILA DEQUE\n");
        printf("==================================================================\n");
        printf("[1] Adicionar caminhao com carga normal\n");
        printf("[2] Adicionar caminhao com carga urgente\n");
        printf("[3] Descarregar caminhao\n");
        printf("[4] Remover caminhao do final da fila\n");
        printf("[5] Exibir fila de caminhoes\n");
        printf("[0] Sair\n");
        puts("");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("\nAdicionando caminhao normal...\n");
                printf("Informe o conteudo da carga: ");
                scanf("%s", conteudo);
                adicionarNormal(deque, conteudo);
                break;
            case 2:
                printf("\nAdicionando caminhao urgente...\n");
                printf("Informe o conteudo da carga: ");
                scanf("%s", conteudo);
                adicionarUrgente(deque, conteudo);
                break;
            case 3:
                descarregar(deque);
                break;
            case 4:
                removerFinal(deque);
                break;
            case 5:
                exibirFila(deque);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("OPCAO INVALIDA!!!\n");
        }
        
    } while (opcao != 0);

    return 0;
}
