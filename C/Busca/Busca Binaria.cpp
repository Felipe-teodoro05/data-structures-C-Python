// Codigo de busca binaria

#include<stdio.h>

// Funcao principal

int main(){
	int vetor[100000];
	int i;
	int busca;
	int achei;
	
	for(i=0; i<100000; i++){
		vetor[i]=i;
	}
	
	// Perguntar valor a ser buscado
	printf("Digite o valor a ser buscado: ");
	scanf("%d",&busca);
	
	// Busca binaria propriamente dita
	int inicio=0;
	int fim = 99999;
	while(fim>inicio){
		int meio = ((inicio+fim)/2);
		
		if(vetor[meio]==busca){
			achei = meio;
			break;
		}else if(vetor[meio]> busca){
			fim = meio-1;
		}else{
			inicio= meio+1;
		}
	}
	
	if (achei==-1){
		printf("Nao achei");
	}else{
		printf("Achei na posicao %d", achei);
	}
}























