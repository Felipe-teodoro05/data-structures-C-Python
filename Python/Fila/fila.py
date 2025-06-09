# uma Fila segue a regra FIFO (First-In, First-Out). A implementação mais direta e intuitiva em Python usa uma lista (list).
# No entanto, é crucial entender a ineficiência dessa abordagem. Remover o primeiro elemento de uma lista (.pop(0)) é uma operação lenta (complexidade O(n)),
# pois todos os elementos restantes precisam ser deslocados para a esquerda para preencher o espaço. Para filas pequenas, não faz diferença, mas para milhares de itens, o impacto no desempenho é enorme

class FilaSimples:
    """
    Implementação de uma Fila utilizando uma lista Python.
    Esta abordagem é INEFFICIENTE para a operação de desenfileirar (dequeue)
    em listas grandes, mas é muito clara para aprender o conceito FIFO.
    """
    def __init__(self):
        """Inicializa uma fila vazia."""
        self._items = []
        print("Fila Simples (com list) criada!")

    def is_empty(self) -> bool:
        """Verifica se a fila está vazia."""
        return not self._items

    def enqueue(self, item):
        """Adiciona um item ao FINAL da fila (operação eficiente)."""
        self._items.append(item)
        print(f"-> Enqueue: {item} foi adicionado. Fila: {self._items}")

    def dequeue(self):
        """
        Remove e retorna o item do INÍCIO da fila.
        Lança um IndexError se a fila estiver vazia.
        !!! ATENÇÃO: Operação ineficiente (O(n)) em listas. !!!
        """
        if self.is_empty():
            raise IndexError("dequeue(): A fila está vazia.")
        
        item_removido = self._items.pop(0)
        print(f"<- Dequeue: {item_removido} foi removido. Fila: {self._items}")
        return item_removido

    def peek(self):
        """Retorna o item do início da fila sem removê-lo."""
        if self.is_empty():
            raise IndexError("peek(): A fila está vazia.")
        return self._items[0]

    def size(self) -> int:
        """Retorna o número de itens na fila."""
        return len(self._items)

    def __str__(self) -> str:
        """Retorna uma representação da fila como string."""
        # Mostra o início e o fim para clareza
        return f"INÍCIO -> {str(self._items)} -> FIM"
    
    # Testando a implementação da FilaSimples
fs = FilaSimples()
print(fs)
print("-" * 20)

fs.enqueue('A') # A entra
fs.enqueue('B') # B entra depois de A
fs.enqueue('C') # C entra por último

print("-" * 20)
print(f"Fila atual completa: {fs}")
print(f"Quem é o primeiro da fila (peek)? {fs.peek()}")
print(f"Tamanho da fila: {fs.size()}")
print("-" * 20)

# O primeiro a sair deve ser 'A'
fs.dequeue()

# O primeiro a sair agora deve ser 'B'
fs.dequeue()

print("-" * 20)
print(f"Fila final: {fs}")