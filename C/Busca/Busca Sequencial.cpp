#include <stdio.h>

// Função de busca sequencial
int buscaSequencial(int arr[], int tamanho, int valor) {
    for (int i = 0; i < tamanho; i++) {
        if (arr[i] == valor) {
            return i; // Retorna a posição do elemento encontrado
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

// Função principal
int main() {
    int numeros[] = {10, 20, 30, 40, 50};
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    int valor = 60;

    int resultado = buscaSequencial(numeros, tamanho, valor);

    if (resultado != -1) {
        printf("achei essa porra na posicao: %d\n", resultado);
    } else {
        printf("Nao encontrei esse krai\n");
    }

    return 0;
}
