// Programa que implementa uma fila simples

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Estrutura

typedef struct{
	int itens[MAX];
	int inicio;
	int fim;
	int tamanho;
}Fila;

// Funcao que inicializa a fila
void inicializar(Fila *fila){
	fila->inicio = 0;
	fila->fim = -1;
	fila -> tamanho = 0;
}

// Ver se a fila tá vazia
int vazio(Fila *fila){
	return fila->tamanho ==0;
}

// Verifica se a fila ta cheia
int cheia(Fila *fila){
	return fila->tamanho==MAX;
}

// Inserir elemento no final da fila
void enqueue(Fila *fila, int elemento){
	if(cheia(fila)){
		printf("Erro: Fila cheia!\n");
		return;
	}
	fila->fim = (fila->fim+1) % MAX; // incrementa o índice circularmente
	fila->itens[fila->fim] = elemento;
	fila->tamanho++;
	printf("Elemento %d inserido na fila\n", elemento);
}

//Remover um elemento no início da fila
int dequeue(Fila *fila){
	if(vazio(fila)){
		printf("Erro: Fila vazia!\n");
        return -1; 
	}
	int elementoremovido = fila->itens[fila->inicio];
	fila->inicio = (fila->inicio +1) % MAX;
	fila->tamanho--;
	return elementoremovido;
}

// Consultar elemento no início da fila
int peek(Fila *fila){
	if (vazio(fila)){
		printf("Erro: Fila vazia!\n");
        return -1;
	}
	return fila->itens[fila->inicio];
}

// Exibir todos os elementos
void exibir(Fila *fila){
	if(vazio(fila)){
		printf("Fila vazia!\n");
        return;
	}
	printf("Fila: ");
    for (int i = 0; i < fila->tamanho; i++) {
        printf("%d ", fila->itens[(fila->inicio + i) % MAX]);
    }
    printf("\n");
}

// Funcao principal de execucao do programa
int main(){
	Fila fila;
	inicializar(&fila);
	
	enqueue(&fila,10);
	enqueue(&fila,20);
	enqueue(&fila,30);
	
	exibir(&fila);
	
	printf("Elemento removido %d\n", dequeue(&fila));
	exibir(&fila);
	
	printf("Elemento no início da fila: %d\n", peek(&fila));

    enqueue(&fila, 40);
    exibir(&fila); 
}















