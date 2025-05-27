// Bubble sort

#include<stdio.h>

// FUncao principal 

int main(){
	// Declaracao de variaveis
	int vetor[10];
	int i;
	int troquei;
	
	// Preencher vetor
	for(i=0; i<10; i++){
		printf("Vetor[%d]=", i);
		scanf("%d",&vetor[i]);
	}
	
	// Ordenacao 
	troquei = 1;
	while(troquei){
		troquei=0;
		
		for(i=0; i<9; i++){
			if(vetor[i]> vetor[i+1]){
				int temp = vetor[i];
				vetor[i]= vetor[i+1];
				vetor[i+1] = temp; 
				
				troquei =1;
			}
		}
	}
	
	// Impressao do vetor ordenado
	for(i=0;i<10;i++){
		printf("%d\n", vetor[i]);
	}	
	
	
	
	
	
}

