# Um Deque é uma generalização de filas e pilhas. 
# É uma "fila de duas pontas", onde você pode adicionar e remover elementos tanto do início quanto do final da estrutura.

from collections import deque

class Deque:
    """
    Implementação completa de um Deque (Double-Ended Queue)
    utilizando a classe 'collections.deque' nativa do Python.
    Oferece operações eficientes (O(1)) em ambas as extremidades.
    """
    def __init__(self):
        """Inicializa um deque vazio."""
        self._items = deque()
        print("Deque (com collections.deque) criado!")

    def is_empty(self) -> bool:
        """Verifica se o deque está vazio."""
        return not self._items

    # --- Operações na FRENTE (Início) ---
    def add_front(self, item):
        """Adiciona um item no início (frente) do deque."""
        self._items.appendleft(item)
        print(f"<- add_front: {item} foi adicionado. Deque: {list(self._items)}")

    def remove_front(self):
        """Remove e retorna o item do início (frente) do deque."""
        if self.is_empty():
            raise IndexError("remove_front(): O deque está vazio.")
        item_removido = self._items.popleft()
        print(f"-> remove_front: {item_removido} foi removido. Deque: {list(self._items)}")
        return item_removido

    def peek_front(self):
        """Retorna o item do início (frente) sem removê-lo."""
        if self.is_empty():
            raise IndexError("peek_front(): O deque está vazio.")
        return self._items[0]

    # --- Operações na TRASEIRA (Fim) ---
    def add_rear(self, item):
        """Adiciona um item no final (traseira) do deque."""
        self._items.append(item)
        print(f"add_rear ->: {item} foi adicionado. Deque: {list(self._items)}")

    def remove_rear(self):
        """Remove e retorna o item do final (traseira) do deque."""
        if self.is_empty():
            raise IndexError("remove_rear(): O deque está vazio.")
        item_removido = self._items.pop()
        print(f"remove_rear <-: {item_removido} foi removido. Deque: {list(self._items)}")
        return item_removido

    def peek_rear(self):
        """Retorna o item do final (traseira) sem removê-lo."""
        if self.is_empty():
            raise IndexError("peek_rear(): O deque está vazio.")
        return self._items[-1]

    def size(self) -> int:
        """Retorna o número de itens no deque."""
        return len(self._items)

    def __str__(self) -> str:
        """Retorna uma representação do deque como string."""
        return f"FRENTE -> {str(list(self._items))} -> TRASEIRA"

# CTestando o Deque

d = Deque()
print(d)
print("-" * 30)

# Comportamento de Fila (adiciona no fim, remove do início)
print("Usando como Fila (FIFO):")
d.add_rear(10)
d.add_rear(20)
d.remove_front() # Remove o 10
print("-" * 30)

# Comportamento de Pilha (adiciona no fim, remove do fim)
print("Usando como Pilha (LIFO):")
d.add_rear(30)
d.remove_rear() # Remove o 30
print("-" * 30)

# Comportamento exclusivo de Deque
print("Operações nas duas pontas:")
d.add_front(99) # Adiciona 99 na frente
d.add_rear(88)  # Adiciona 88 atrás
print(f"\nEstado final: {d}")
print(f"Olhando a frente (peek_front): {d.peek_front()}")
print(f"Olhando a traseira (peek_rear): {d.peek_rear()}")