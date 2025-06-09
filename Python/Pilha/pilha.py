# Definir a classe
class Pilha:
    def __init__(self):
        """Inicializando pilha vazia"""
        self._itens = []
    
    def is_empty(self):
        """Verifica se a pilha está vazia"""
        return not self._itens

    def push(self, item):
        """Adiciona um item ao topo da pilha"""
        self._itens.append(item)

    def pop(self):
        """Remove e retorna o item do topo da pilha"""
        if self.is_empty():
            raise IndexError("pop from empty stack")
        return self._itens.pop()

    def peek(self):
        """"Retorna o item do topo da pilha sem removê-lo"""
        if self.is_empty():
            raise IndexError("peek from empty stack")
        return self._itens[-1]
    
    def size(self):
        """Retorna o número de itens na pilha"""
        return len(self._itens)

    def __str__(self):
        """Representação da pilha como string"""
        return str(self._itens)
    
    ## Teste da classe Pilha

# Criar pilha
pilha = Pilha()
print("Pilha criada:", pilha, "Vazia:", pilha.is_empty())

# Adicionar itens
pilha.push(1)
pilha.push(2)
pilha.push(3)
print("Pilha após push:", pilha, "Vazia:", pilha.is_empty())
print(f"Tamanho da pilha: {pilha.size()}")

# Verificar o topo da pilha
print("Topo da pilha:", pilha.peek())

# Remover itens
item_removido = pilha.pop()
print(f"\nItem removido (pop): {item_removido}")
print(f"Pilha após o pop: {pilha}")
print(f"Novo item no topo: {pilha.peek()}")

# Tentando remover de uma pilha vazia (isso vai gerar um erro)
print("\nEsvaziando a pilha...")
pilha.pop()
pilha.pop()
print(f"Pilha final: {pilha}")

try:
    pilha.pop()
except IndexError as e:
    print(f"Ocorreu um erro esperado: {e}")