// Programa que implementa uma árvore de busca//

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Declaração da estrutura do no
struct no{
	int numero;
	struct no*direita;
	struct no*esquerda;
};

// Inserir um no na arvore
 struct no*inserir(struct no*raiz, int numero){
 	//Caso facil: arvore vazia
 	if(raiz==NULL){
 		raiz= (struct no *) malloc(sizeof(struct no));
 		raiz->numero=numero;
 		raiz-> esquerda= NULL;
 		raiz-> direita=NULL;
 		return raiz;
	 }
 	
 	//Caso dificil: arvore não esta vazia
 	if(raiz-> numero > numero){
 		raiz->esquerda = inserir(raiz->esquerda, numero);
	 }else{
	 	raiz-> direita= inserir(raiz->direita, numero);
	 }
	 return raiz;
 }

//Função que busca um no na arvore
void buscar(struct no*raiz, int numero){
	//Caso mt facil: arvore vazia
	if(raiz==NULL){
		printf("Se fudeu seu corno\n");
		return;
	}
	
	//Caso facil: raiz é o numero
	if(raiz->numero==numero){
		printf("Achei esse krai");
		return;
	}
	
	//Caso dificil: não esta na raiz
	if(raiz->numero>numero){
		buscar(raiz->esquerda,numero);
	} else{
		buscar(raiz->direita, numero);
	}
}

//Função que navega a arvore em ordem

void navegaremordem(struct no*raiz){
	if(raiz==NULL){
		return;
	}
	
	navegaremordem(raiz->esquerda);
	printf("%d,", raiz->numero);
	navegaremordem(raiz->direita);
}

//Função principal do programa

int main(){
	//declarar variáveis
	struct no*raiz=NULL;
	int busca=0;
	int i =0;
	
	//inicialização da aleatoridade
	time_t krai;
	srand(time(&krai));
	
	//Criacao da arvore
	int tamanho =1000000;
	for(i=0; i<tamanho;i++){
		raiz= inserir(raiz, (rand()%tamanho));
	}
	
	//Buscas
	while(busca!=-1){
		printf("Digite o numero a ser buscado ou Digite menos 1 para sair ");
		scanf("%d", &busca);
		buscar(raiz,busca);
	}
	
	//Navegação em ordem
	navegaremordem(raiz);
}