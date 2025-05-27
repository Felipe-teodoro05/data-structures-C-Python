//Transposição de matrizes

#include <stdio.h>

//Declarar variáveis

int matriz [2][3];
int transposta [3][2];
int i;
int j;

//Função principal de execução

int main() {
	for (i = 0; i < 2; i++) { 		//Linha
		for (j = 0; j < 3; j++) {	//Coluna
			printf("matriz [%d][%d] =  ",i , j);
			scanf("%d", &matriz [i] [j] );

		}
	}
	
	//Transposição propriamente dita
	for (i = 0; i < 2; i++) { 		//Linha
		for (j = 0; j < 3; j++) {	//Coluna
		transposta[j][i] = matriz[i][j];
		}
	}

	//Impressão da matriz original
	for (i = 0; i < 2; i++) { 		//Linha
		for (j = 0; j < 3; j++) {	//Coluna
			printf(" %d\t", matriz[i][j]);
		}
		printf("\n");
	}


	//Impressão da matriz transposta
	for (i = 0; i<3; i++) {
		for (j = 0; j<2;j++) {
			printf("%d\t", transposta[i][j]);
		}
		
	printf("\n");	
	}
	
}
