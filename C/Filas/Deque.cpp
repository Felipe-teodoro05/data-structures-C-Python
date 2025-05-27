#include <stdio.h>
#include <stdlib.h>

// Declaração da estrutura do nó
struct no {
    int numero;
    struct no* proximo;
};

// Declaração da estrutura do deque
struct deque {
    struct no* filanormal;
    struct no* filapreferencial;
};

// Protótipos das funções
struct no* entrar(struct no* fila, int numero);
struct no* sair(struct no* fila);
int atender(struct deque* cabeca, int atendimento);

// Função que insere um nó na fila
struct no* entrar(struct no* fila, int numero) {
    // Criação do novo nó
    struct no* novoNo = (struct no*)malloc(sizeof(struct no));
    novoNo->numero = numero;
    novoNo->proximo = fila;

    // Atualização da fila
    fila = novoNo;

    // Retorno da fila atualizada
    return fila;
}

// Função que retira um nó da fila
struct no* sair(struct no* fila) {
    if (fila == NULL) {
        return NULL;
    }
    // Caso fácil: só 1 nó na fila
    if (fila->proximo == NULL) {
        printf("%d\n", fila->numero);
        free(fila);  // Libera a memória do nó
        return NULL;
    }

    // Caso difícil: mais de 1 nó
    struct no* ponteiro = fila;
    while (ponteiro->proximo->proximo != NULL) {
        ponteiro = ponteiro->proximo;
    }

    printf("%d\n", ponteiro->proximo->numero);
    free(ponteiro->proximo);
    ponteiro->proximo = NULL;

    return fila;
}

// Função que realiza o atendimento
int atender(struct deque* cabeca, int atendimento) {
    if (cabeca == NULL) {
        printf("Erro: estrutura deque não inicializada.\n");
        return atendimento;
    }

    if (cabeca->filapreferencial != NULL && atendimento < 3) {
        cabeca->filapreferencial = sair(cabeca->filapreferencial);
        if (cabeca->filanormal != NULL) {
            atendimento++;
        }
    } else if (cabeca->filanormal != NULL) {
        cabeca->filanormal = sair(cabeca->filanormal);
        atendimento = 0;
    } else {
        printf("Filas vazias\n");
    }
    return atendimento;
}

// Função principal de execução do programa
int main() {
    // Declarar variáveis
    struct deque cabeca = {NULL, NULL};
    int atendimento = 0;
    int i = 0;

    // Caso fila vazia
    atendimento = atender(&cabeca, atendimento);

    // Caso somente normal
    for (i = 0; i < 5; i++) {
        cabeca.filanormal = entrar(cabeca.filanormal, i);
    }
    for (i = 0; i < 6; i++) {
        atendimento = atender(&cabeca, atendimento);
    }

    // Preferencial
    for (i = 0; i < 5; i++) {
        cabeca.filapreferencial = entrar(cabeca.filapreferencial, i);
    }
    for (i = 0; i < 6; i++) {
        atendimento = atender(&cabeca, atendimento);
    }

    // Misturado
    for (i = 0; i < 10; i++) {
        cabeca.filanormal = entrar(cabeca.filanormal, i);
    }
    for (i = 100; i < 110; i++) {
        cabeca.filapreferencial = entrar(cabeca.filapreferencial, i);
    }
    for (i = 0; i < 2; i++) {
        atendimento = atender(&cabeca, atendimento);
    }

    return 0;
}