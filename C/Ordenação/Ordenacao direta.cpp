// Ordenação direta

#include<stdio.h>

// Funcao principal de execucao do programa

int main(){
	// Declarar variaveis
	int vetor[10];
	int i;
	int j;
	
	// Preencher o vetor
	for (i=0; i<10;i++){
		printf("Digite o valor da posicao %d do veotr: ",i);
		scanf("%d", &vetor[i]);
	}
	
	//Ordenacao
	for(i=0; i<9; i++){
		for(j=(i+1); j<10; j++){ // Do próximo ao ultimo
			if(vetor[i]>vetor[j]){
				int temp = vetor[i];
				vetor[i]= vetor[j];
				vetor[j]= temp;
			}
		}
	}
	//Impressão do vetor ordenado
	for(i=0; i<10; i++){
		printf("%d\n", vetor[i]);
	}
	
	
}

