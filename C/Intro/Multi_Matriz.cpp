//////////////////////////////////////////////////////
///Programa que Implementa Multiplicação de Matrizes///
//////////////////////////////////////////////////////

#include <stdio.h>

/////////////////////////////
///Declaração de Variaveis///
/////////////////////////////

int operando1 [2][3];
int operando2 [3][2];
int resultado [2][2];
int i;
int j;
int k;

/////////////////////
///Função Principal//
/////////////////////

int main() {
    ///Preenchimento do Primeiro Operando

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 3; j++) {
            printf("operando1[%d, %d] = ", i, j);
            scanf("%d", &operando1[i][j]);
        }
    }

    ///Preenchimento do Segundo Operando

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            printf("operando2[%d, %d] = ", i, j);
            scanf("%d", &operando2[i][j]);
        }
    }

    ///Multiplicação
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            for (k = 0; k < 3; k++) {
                resultado[i][j] += (operando1[i][k] *
                                    operando2[k][j]);
            }
        }
    }

    // Impressão do Resultado
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t", resultado[i][j]);
        }
        printf("\n");
    }

}


