// Lista duplamente encadeada

#include<stdio.h>
#include<stdlib.h>

// Declarar a estrutura do no

struct no{
	int numero;
	struct no*anterior;
	struct no*proximo;
}

// Funcao que insere um no na lista

struct no*inserir(struct no*cabeca, int numero){
	// Criar novo no
	struct no*novoNo = (struct no*) malloc(sizeof(struct no));
	novoNo -> numero=numero;
	novoNo -> anterior=NULL;
	novoNo -> proximo=NULL;

	// Apontamento para encadeamento da lista
	novoNo -> proximo= cabeca;
	if(cabeca==NULL){
		cabeca->anterior = novoNo;
	}
	
	// Atualizacao da cabeca
	cabeca = novoNo;
	return cabeca;
}

// Funcao que imprime a lista 
// Void quer dizer que a funcao nao retorna nada
void imprimir(struct no*cabeca){
	struct no*ponteiro = cabeca;
}


























