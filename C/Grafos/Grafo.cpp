// Programa que implementa um grafo

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define QTDVERTICES 6

//FUnção que cria um grafo

void criar(int grafo[QTDVERTICES][QTDVERTICES], int sorteio){
	int i;
	int j;
	
	//Inicialização do grafo
	for(i=0; i<QTDVERTICES; i++){
		for(j=0; j<QTDVERTICES; j++){
			grafo[i][j]=0;
		}
	}
	//Criacao propriamente dita
	for(i=0; i<(QTDVERTICES-1); i++){
		for (j=(i+1); j<QTDVERTICES; j++){
			int adjacencia = ((rand()%5)==0);
			
			if(!sorteio){
				printf("Digite <1> se %d e vizinho de  %d ", i, j);
				scanf("%d", &adjacencia);
			}
			
			grafo[i][j]= adjacencia;
			grafo[j][i]= adjacencia;
		}
	}
}

//Função que imprime o grafo

void imprimir(int grafo[QTDVERTICES][QTDVERTICES]){
	int i;
	int j;
	
	printf("Vertice\tVizinhanca\n");
	for (i=0; i< QTDVERTICES; i++){
		printf("%d\t", i);
		for (j=0; j<QTDVERTICES; j++){
			if (grafo[i][j]){
				printf("%d, ", j);
			}
		}
		printf("\n");
	}
}

//Funcao principal de execucao do programa

int main(){
	int grafo[QTDVERTICES][QTDVERTICES];
	
	time_t t;
	srand(time(&t));
	
	
	criar(grafo,1);// Para ser manual = 0, sorteio =1
	
	imprimir(grafo);
}



