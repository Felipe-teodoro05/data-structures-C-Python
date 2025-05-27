// Programa que implementa uma arvore AVL

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Declaração da estrutura do no

struct no{
	int numero;
	int altura;
	struct no*esquerda;
	struct no*direita;
};

//Função que recupera a altura de um no

int getalturano(struct no*raiz){
	int retorno=0;
	
	if (raiz!=NULL){
		retorno = raiz->altura;
	}
	
	return retorno;
}

//Função que descobre a altura maior entre dois numeros

int getmax(int a, int b){
	return (a>b) ? a : b;// Famoso if(?) e else(:)
}


// Função que calcula o balanco da arvore

int getbalanco (struct no*raiz){
	int retorno =0;
	if (raiz!= NULL){
		retorno = (getalturano(raiz->esquerda) - getalturano(raiz->direita));
	}
	return retorno;
}

// Função que executa uma rotação à esquerda

struct no*rotacaoesquerda(struct no *raiz){
	struct no *novaraiz = raiz->direita;
	struct no*temp = novaraiz->esquerda;
	novaraiz->esquerda= raiz;
	raiz->direita= temp;
	
	raiz->altura = (getmax(getalturano(raiz->esquerda),getalturano(raiz->direita))+1);
	
	novaraiz->altura = (getmax(getalturano(novaraiz->esquerda), getalturano(novaraiz->direita))+1);
	
	return novaraiz;
}

// Função que executa uma rotação à direita

struct no*rotacaodireita(struct no *raiz){
	struct no *novaraiz = raiz->esquerda;
	struct no*temp = novaraiz->direita;
	novaraiz->direita= raiz;
	raiz->esquerda= temp;
	
	raiz->altura = (getmax(getalturano(raiz->esquerda),getalturano(raiz->direita))+1);
	
	novaraiz->altura = (getmax(getalturano(novaraiz->esquerda), getalturano(novaraiz->direita))+1);
	
	return novaraiz;
}

//Função que insere um no na arvore

struct no*inserir(struct no*raiz, int numero){
	if(raiz==NULL){
		raiz=(struct no*) malloc(sizeof(struct no));
		raiz->numero =numero;
		raiz->altura=1;
		raiz->esquerda=NULL;
		raiz->direita=NULL;
	} else if(raiz->numero>numero){
		raiz-> esquerda = inserir(raiz-> esquerda,numero);
	} else{
		raiz-> direita = inserir(raiz->direita, numero);
	}
	
	raiz-> altura = (1+ getmax(getalturano(raiz->esquerda), getalturano(raiz->direita)));

	int balanco = getbalanco(raiz);
	
	// Já ta inclinado para a esquerda e vou inserir de novo na esquerda
	if(balanco>1 && numero<raiz->esquerda->numero){
		raiz= rotacaodireita(raiz);
	}
	
	// Já está inclinado para a direita e vou inserir na direita
	if (balanco<-1 && numero>raiz->direita->numero){
		raiz= rotacaoesquerda(raiz);
	}
	
	//Inclinado à esquerda e inserção à direita
	if(balanco>1 && numero>raiz->esquerda->numero){
		raiz->esquerda = rotacaoesquerda(raiz->esquerda);
		raiz = rotacaodireita(raiz);
		
	}
	
	//Inclinado à direita e inserção à esquerda
	if(balanco<-1 && numero<raiz->direita->numero){
		raiz->direita = rotacaodireita(raiz->direita);
		raiz = rotacaoesquerda(raiz);
		
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



// Função principal de execução do programa
int main(){
	struct no*raiz = NULL;
	int i= 0;
	
	for (i=0; i<1000; i++){
		raiz = inserir(raiz,i);
		imprimir(raiz,"");
		printf("===============\n");
		
	}
}

