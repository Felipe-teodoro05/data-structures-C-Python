// Lista com encadeamento simples

#include<stdio.h>
#include<stdlib.h>

// Declaração da estrutura do nó
// Ponteiro vai apontar para o próximo número
struct no{
	int numero;
	struct no*proximo; //* serve para indicar que é um ponteiro
};

// Inserir um nó na lista
// Necessário dizer o tipo antes
struct no*inserir(struct no*cabeca, int numero){
	// Criando o novo nó
	struct no*novoNo = (struct no*) malloc(sizeof(struct no));
	
	novoNo-> numero=numero;
	// Definindo que vai apontar para o NULL pois vai ser o último nó
	novoNo->proximo = NULL;
	
	// Inserção propriamente dita
	if(cabeca==NULL){
		// Lista vazia
		cabeca = novoNo;
	}else{
		// Lista não está vazia
		//Declarar ponteiro temporário
		struct no*ponteiro= cabeca;
		
		//Navegação do ponteiro temporário até o último no da lista
		while(ponteiro->proximo!=NULL){
			ponteiro = ponteiro->proximo;
		}
		// Apontamento do último no da lista para o novo no
		ponteiro-> proximo = novoNo;
	}
	return cabeca;
}

//Função que imprime os nos da lista
void imprimir(struct no*cabeca){
	struct no*ponteiro = cabeca;
	
	while(ponteiro!=NULL){
		printf("%d\n", ponteiro->numero);
		ponteiro = ponteiro->proximo;
	
	}
}

// Função para deletar um nó da lista
struct no *deletar(struct no*cabeca, int numero){
	struct no*temp = cabeca, *prev=NULL;
	
	// Se o nó que for deeletado é o primeiro da lista
	if(temp!=NULL && temp-> numero==numero){
		// O segundo no passa a ser a nova cabeca
		cabeca = temp->proximo;
		free(temp);
		return cabeca;
	}
	
	// Buscar o nó a ser deletado
    while (temp != NULL && temp->numero != numero) {
        prev = temp;
        temp = temp->proximo;
	}
	
	// Se o número não for encontrado, retorna a lista sem alterações
    if (temp == NULL) {
        return cabeca;
    }

    // Remover o nó da lista
    prev->proximo = temp->proximo; // Pular o no a ser removido
    free(temp);

    return cabeca;
}
//Função principal
int main(){
	struct no*cabeca = NULL;
	
	cabeca = inserir(cabeca,1);
	cabeca = inserir(cabeca,2);
	cabeca = inserir(cabeca,3);
	cabeca = inserir(cabeca,4);
	
	printf("Lista encadeada antes da remoção: \n");
	imprimir(cabeca);
	
	// removendo um no
	cabeca = deletar(cabeca, 3);
	
	printf("Lista após remover o 3\n");
	imprimir(cabeca);
}
