// Programa que implementa uma pilha

#include<stdio.h>
#include<stdlib.h>

// Declaracao da estrutura do no

struct no{
	int numero;
	struct no*proximo;
};

// Funcao que insere um no na pilha
struct no*push(struct no*cabeca, int numero){
	struct no*novoNo = (struct no*)malloc(sizeof(struct no)); // aloca memoria para o novo no
	novoNo->numero = numero; // atribui o valor ao novo no
	novoNo->proximo = cabeca; // aponta o proximo no para o topo da pilha
	cabeca= novoNo; // atualiza a cabeca 
	return cabeca;
}

// Remover um no da pilha
struct no*pop(struct no*cabeca){
	if(cabeca==NULL){
		printf("Pilha vazia! Não há nada para remover.\n");
		return NULL;
	}
	struct no *temp = cabeca; // Guarda a referência ao nó que será removido
    printf("Elemento removido: %d\n", cabeca->numero); // Exibe o valor removido
    cabeca = cabeca->proximo; // Atualiza o topo da pilha
    free(temp); // Libera a memória do nó removido
    return cabeca; // Retorna o novo topo da pilha
}

// Função que retorna o topo da pilha sem remover o elemento (Peek)
int peek(struct no *cabeca) {
    if (cabeca == NULL) {
        printf("Pilha vazia! Não há elementos no topo.\n");
        return -1; // Retorna -1 se a pilha estiver vazia
    }
    return cabeca->numero; // Retorna o valor no topo da pilha
}
// Funcao principal de execucao do programa
int main() {
    struct no *cabeca = NULL; // Inicializa a pilha como vazia
    int i = 0;

    // Inserir 10 elementos na pilha
    for (i = 0; i < 10; i++) {
        cabeca = push(cabeca, i); // Adiciona elementos de 0 a 9 na pilha
    }

    // Exibe o topo da pilha antes de remover elementos
    printf("Topo da pilha antes de qualquer remoção: %d\n", peek(cabeca));

    // Remover 10 elementos da pilha
    for (i = 0; i < 10; i++) {
        cabeca = pop(cabeca); // Remove um elemento da pilha a cada iteração
    }

    // Tenta acessar o topo de uma pilha vazia
    printf("Topo da pilha após todas as remoções: %d\n", peek(cabeca));

    return 0;
}

