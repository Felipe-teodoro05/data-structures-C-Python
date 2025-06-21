"""
Implementação de uma Estrutura de Dados de Lista Duplamente Encadeada em Python.

Este arquivo contém a definição da classe 'No' e da classe 'DoubleList',
que permite a criação e manipulação de listas duplamente encadeadas,
oferecendo operações eficientes de inserção e remoção nas extremidades.
"""
# Criação da classe do No (Valor, Anterior, Proximo)
# Criação de uma classe DoubleList, que conterá os métodos init, inserção início, no final, remoção e busca.
# Operação com complexidade O(1) para inserção e remoção no início e no final da lista

class No:
    """Representa um único nó em uma Lista Duplamente Encadeada."""
    def __init__(self, dado):
        """
        Inicializa um nó.

        Args:
            dado: O valor a ser armazenado no nó.
        """
        self.valor = dado
        self.anterior = None
        self.proximo = None

class DoubleList:
    """
    Representa uma Lista Duplamente Encadeada e seus métodos de manipulação.

    Attributes:
        cabeca (No): O primeiro nó da lista.
        cauda (No): O último nó da lista.
    """
    def __init__(self):
        """Inicializa uma lista duplamente encadeada vazia."""
        self.cabeca = None
        self.cauda = None
    
    def inserir_inicio(self, valor):
        """
        Insere um novo nó no início da lista.
        Complexidade: O(1)
        """
        novo_no = No(valor)
        # Lista vazia
        if self.cabeca is None:
            self.cabeca = novo_no
            self.cauda = novo_no
        # Lista não vazia
        else:
            novo_no.proximo = self.cabeca
            self.cabeca.anterior = novo_no
            self.cabeca = novo_no
    
    def inserir_final(self, valor):
        """
        Insere um novo nó no final da lista.   
        Complexidade: O(1)
        """
        
        novo_no = No(valor)

        # Lista vazia
        if self.cabeca is None:
            self.cabeca = novo_no
            self.cauda = novo_no
        
        # Lista não vazia
        else:
            novo_no.anterior = self.cauda
            self.cauda.proximo = novo_no
            self.cauda = novo_no
    
    def remover(self, valor):
        """
        Remove o nó com o valor especificado da lista, contém todos os possíveis casos.
        Complexidade: O(n) devido à busca
        """
        # Lista vazia
        if self.cabeca is None:
            print("A lista está vazia.")
            return
        
        # Percorrer a lista para encontrar o nó a ser removido
        temp = self.cabeca
        while temp is not None and temp.valor != valor:
            temp = temp.proximo
            # Após isso, ou encontramos o nó ou chegamos ao final da lista

        # Caso em que o nó não foi encontrado
        if temp is None:
            print(f"Nó com valor {valor} não encontrado.")
            return
        
        # List a só com um nó
        if self.cabeca == self.cauda:
            self.cabeca = None
            self.cauda = None
            return
        
        # O nó a ser removido é a cabeça
        elif temp == self.cabeca:
            self.cabeca = temp.proximo
            self.cabeca.anterior = None
            
        
        # O nó a ser removido é a cauda
        elif temp == self.cauda:
            self.cauda = temp.anterior
            self.cauda.proximo= None

        # O no a ser removido está no meio da lista
        else:
            temp.anterior.proximo = temp.proximo
            temp.proximo.anterior = temp.anterior
    
    def buscar(self, valor):
        """
        Busca um valor na lista.
        Complexidade: O(n)
        
        Returns:
            bool: True se o valor for encontrado, caso contrário, False.
        """
        temp = self.cabeca
        while temp is not None:
            if temp.valor == valor:
                return True
            temp = temp.proximo
        return False
    
    def __str__(self):
        """Representa a lista como uma string, mostrando os valores dos nós."""
        if self.cabeca is None:
            return "Lista vazia"
        
        temp = self.cabeca
        valores = []
        while temp is not None:
            valores.append(str(temp.valor))
            temp = temp.proximo
        return "<->".join(valores)

# Exemplo de uso
if __name__ == "__main__":
    lista_teste = DoubleList()
    print(f"1. Lista recém-criada: {lista_teste}")

    print("\n--- TESTANDO INSERÇÕES ---")
    lista_teste.inserir_final(10)
    print(f"Inseriu 10 no final: {lista_teste}")
    lista_teste.inserir_final(20)
    print(f"Inseriu 20 no final: {lista_teste}")
    lista_teste.inserir_inicio(5)
    print(f"Inseriu 5 no início: {lista_teste}")

    print("\n--- TESTANDO BUSCA ---")
    print(f"Buscando o valor 20 (deve ser True): {lista_teste.buscar(20)}")
    print(f"Buscando o valor 99 (deve ser False): {lista_teste.buscar(99)}")

    print("\n--- TESTANDO REMOÇÕES ---")
    # Agora, os testes mais importantes
    lista_teste.inserir_final(30)
    print(f"Estado antes da remoção: {lista_teste}") # Deve ser 5 <=> 10 <=> 20 <=> 30

    # Teste 1: Remover do meio
    print("\nRemovendo o 10 (meio)...")
    lista_teste.remover(10)
    print(f"Resultado: {lista_teste}") # Deve ser 5 <=> 20 <=> 30

    # Teste 2: Remover a cauda 
    print("\nRemovendo o 30 (cauda)...")
    lista_teste.remover(30)
    print(f"Resultado: {lista_teste}") # Deve ser 5 <=> 20

    # Teste 3: Remover a cabeça 
    print("\nRemovendo o 5 (cabeça)...")
    lista_teste.remover(5)
    print(f"Resultado: {lista_teste}") # Deve ser 20

    # Teste 4: Tentar remover algo que não existe
    print("\nTentando remover 99...")
    lista_teste.remover(99)
    print(f"Resultado: {lista_teste}") # Deve ser 20

    # Teste 5: Remover o último nó
    print("\nRemovendo o 20 (último nó)...")
    lista_teste.remover(20)
    print(f"Resultado: {lista_teste}") # Deve ser Lista Vazia

    print("\n--- FIM DOS TESTES ---")