// Insertion sort

#include<stdio.h>

void insertion(int arr[], int n){
	int i, key, j;
	
	// Percorre a lista comecando pelo 2 elemento
	
	for(i =1; i<n; i++){
		key = arr[i]; // Elemento a ser inserido
		j =i -1;
		
		// Move os elementos maiores qye key para uma posicao a frente
		// Continua ate encontrar o lugar correto para key
		while(j>=0 && arr[j]> key){
			arr[j+1] = arr[j]; // Desloca o elemento maior para a direita
			j = j-1; // Vai para o próximo elemento a esquerda
		}
		
		// Colocando o key na posicao correta
		arr[j+1] = key;
	}
}

void imprimir(int arr[], int n){
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// Funcao principal de execucao do programa
int main(){
	int arr[] = {5,2,9,1,5,6};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	printf("Array antes da ordenacao:\n");
    imprimir(arr, n);

    insertion(arr, n);

    printf("Array após a ordenacao:\n");
    imprimir(arr, n);
    
    return 0;
}

