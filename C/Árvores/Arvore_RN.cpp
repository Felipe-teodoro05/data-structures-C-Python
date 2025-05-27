// Programa que implementa uma árvore rubro negra//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Declaracao da estrutura do no

struct no{
	int numero;
	int cor; // 1 vermelho 0 preto
	struct no*esquerda;
	struct no*direita;
};

// função que indica se o nó é vermelho 

int vermelho(struct no*raiz){
	if(raiz==NULL){
		return 0;
	}
	
	return raiz->cor;
}

//Função para rotação pra esquerda

struct no*rotacionaresq(struct no*raizvelha){
	struct no*raiznova= raizvelha->direita;
	raizvelha->direita = raiznova->esquerda;
	raiznova-> esquerda = raizvelha;
	
	//Ajuste da cor
	raiznova->cor = raizvelha->cor;
	raizvelha-> cor=1;
	
	return raiznova;
}

//Função para rotação pra direita

struct no*rotacionardir(struct no*raizvelha){
	struct no*raiznova= raizvelha->esquerda;
	raizvelha->esquerda = raiznova->direita;
	raiznova-> direita= raizvelha;
	
	//Ajuste da cor
	raiznova->cor = raizvelha->cor;
	raizvelha-> cor=1;
	
	return raiznova;
}

void subirvermelho(struct no*raiz){
	raiz->cor=1;
	raiz->esquerda-> cor=0;
	raiz->direita->cor=0;
	
}

//Função que insere um no na arvore

struct no*inserir(struct no*raiz,int numero){
	//Caso facil
	if(raiz==NULL){
		raiz= (struct no*) malloc(sizeof(struct no));
		raiz->numero = numero;
		raiz->cor = 1;
		raiz->esquerda=NULL;
		raiz->direita=NULL;
	}else if(raiz->numero>numero){
		raiz-> esquerda = inserir(raiz->esquerda,numero);
	}else{
		raiz->direita = inserir(raiz ->direita,numero);
	}
	
	//Ajuste da arvore
	if(!vermelho(raiz->esquerda)&& vermelho(raiz->direita)){
		raiz= rotacionaresq(raiz);
	}
	
	if(vermelho(raiz->esquerda)&& vermelho(raiz->esquerda->esquerda)){
		raiz= rotacionardir(raiz);
	}
	
	
	if(vermelho(raiz->esquerda)&& vermelho(raiz->direita)){
		subirvermelho(raiz);
	}
	return raiz;
}

//Funcao que imprime a arvore
void imprimir(struct no*raiz,char * indentacao){
	if(raiz==NULL){
		return;
	}
	printf("%s%d\n", indentacao, raiz->numero);
	
	char*novaindentacao= (char*) malloc(1024*sizeof(char));
	strcpy(novaindentacao,indentacao);
	strcat(novaindentacao, "---");
	
	imprimir(raiz->esquerda,novaindentacao);
	imprimir(raiz->direita,novaindentacao);
}

// Função principal

int main(){
	struct no*raiz =NULL;
	int i=0;
	
	for(i=0; i<10000; i++){
		raiz= inserir(raiz,i);
	}
	
	imprimir(raiz,"");
}