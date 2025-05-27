//Programa que implementa uma arvore binaria

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Estrutura do no

struct no{
	int numero;
	struct no* esquerda;
	struct no* direita;
};

//Função que insere um no na arvore

struct no* inserir(struct no*raiz, int numero){
	//Caso facil: arvore vazia
	if(raiz==NULL){
		raiz= (struct no*) malloc(sizeof(struct no));
		raiz->numero=numero;
		raiz->esquerda=NULL;
		raiz->direita=NULL;
		return raiz;
	}
	
	//Caso dificil
	int sorteio = (rand()%2);
	if (sorteio==0){
		raiz->esquerda= inserir(raiz->esquerda,numero);
	}else{
		raiz->direita= inserir(raiz->direita, numero);
	}
	return raiz;
}
	
//função que navega a arvore pre ordem 
void navegarpreordem(struct no*raiz){
	if(raiz==NULL){
		return;
	}
	
	printf("%d, ", raiz->numero);
	navegarpreordem(raiz->esquerda);
	navegarpreordem(raiz->direita);
}

//função que navega arvore em ordem
void navegaremordem(struct no*raiz){
	if(raiz==NULL){
		return;
	}
	
	navegaremordem(raiz->esquerda);
	printf("%d, ", raiz->numero);
	navegaremordem(raiz->direita);
}

//função que navega arvore em pos ordem
void navegarposordem(struct no*raiz){
	if(raiz==NULL){
		return;
	}
	
	navegarposordem(raiz->esquerda);
	navegarposordem(raiz->direita);
	printf("%d, ", raiz->numero);
}

//Função principal de execução do programa

int main (){
	//declaracao de variaveis
	struct no*raiz=NULL;
	int i = 0;
	
	//inicialização da aleatoriedade
	time_t krai;
	srand(time(&krai));
	
	//criacao da arvore
	for (i=0; i<10; i++){
		raiz = inserir(raiz,i);
	}
	
	//navegacao
	printf("\nPre ordem\t");
	navegarpreordem(raiz);
	
	printf("\nEm ordem\t");
	navegaremordem(raiz);
	
	printf("\nPos ordem\t");
	navegarposordem(raiz);
}