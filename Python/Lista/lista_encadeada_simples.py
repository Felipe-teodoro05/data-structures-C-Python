# Definindo Nó
class No:
    def __init__(self, valor):
        self.valor = valor
        self.proximo = None

# Definindo Lista Encadeada Simples
class ListaEncadeadaSimples:
    def __init__(self):
        """Inicializa uma lista encadeada simples vazia."""
        self.cabeca = None
    
    def vazia(self):
        return self.cabeca is None

    def inserir_final(self,valor):
        novo_no = No(valor)

        # Se alista estiver vazia, o novo nó se torna a cabeça
        if self.vazia():
            self.cabeca = novo_no
            return
        # Se não, percorrer a lista até o final
        ultimo_no = self.cabeca
        while ultimo_no.proximo:
            ultimo_no = ultimo_no.proximo
        
        # O último nó aponta para o novo nó
        ultimo_no.proximo = novo_no
    
    def inserir_inicio(self, valor):
        novo_no = No(valor)
        # O novo nó aponta para a cabeça atual
        novo_no.proximo = self.cabeca
        # A cabeça agora é o novo nó
        self.cabeca = novo_no
    
    def remover(self,chave):
        no_atual = self.cabeca

        # Caso 1: A cabeça é o nó a ser removido
        if no_atual and no_atual.valor == chave:
            self.cabeca = no_atual.proximo
            no_atual = None # Liberando memória
            return

        # Caso 2: Percorrer a lista para encontrar o nó a ser removido (Meio ou Fim)
        no_anterior = None
        while no_atual and no_atual.valor != chave:
            no_anterior = no_atual
            no_atual = no_atual.proximo
        
        # Se o nó a ser removido não foi encontrado
        if no_atual is None:
            print(f"Nó com valor {chave} não encontrado.")
            return
        
        # Remove o nó religando o ponteiro do anterior ao próximo do atual
        no_anterior.proximo = no_atual.proximo
        no_atual = None

    def buscar(self, chave):
        # Buscar um valor na lista
        no_atual = self.cabeca
        while no_atual:
            if no_atual.valor == chave:
                return True
            no_atual = no_atual.proximo
        return False
    
    def __str__(self):
        # Representação da lista como string
        if self.vazia():
            return "Lista vazia"
        valores = []
        no_atual = self.cabeca
        while no_atual:
            valores.append(str(no_atual.valor))
            no_atual = no_atual.proximo
        return " -> ".join(valores)

if __name__ == "__main__":
    # Utilização e teste da lista encadeada simples
    lista = ListaEncadeadaSimples()

    # Inserindo elementos
    lista.inserir_final(10)
    print(lista) 
    lista.inserir_final(20)
    print(lista) 
    lista.inserir_final(30)
    print(lista) 

    # Inserindo no início
    lista.inserir_inicio(5)

    # Buscando elementos
    print(f"O valor 20 está na lista? {lista.buscar(20)}")  
    print(f"O valor 100 está na lista? {lista.buscar(100)}")

    # Removendo elementos
    lista.remover(20)
    print(lista)

    # Deletando o primeiro elemento
    lista.remover(5)
    print(lista)

    # Tentando remover um elemento que não existe
    lista.remover(100)  

    # Deletando o último elemento
    lista.remover(30)