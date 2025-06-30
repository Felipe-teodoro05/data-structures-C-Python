# Criação do algoritmo Bubble Sort

def bubble_sort(lista):
    """Ordena uma lista usando bubble sort."""
    # Definindo o tamanho da lista
    n = len(lista)

    # Loop para percorrer todos os elementos da lista
    for i in range(n-1):
        # Verificar se houve troca
        trocou = False
        # Loop interno para as comparações, com o alcance diminuindo
        for j in range(n-1-i):
            # Se o elemento atual for maior que o próximo, trocamos
            if lista[j]> lista[j+1]:
                lista[j], lista[j+1] = lista[j+1], lista[j]
                trocou = True
        # Se não houve troca, a lista já está ordenada
        if not trocou:
            break

if __name__ == "__main__":
    # Testando o algoritmo Bubble Sort
    lista_teste = [64, 34, 25, 12, 22, 11, 90]
    print(f"Lista original: {lista_teste}")
    
    bubble_sort(lista_teste)
    
    print(f"Lista ordenada: {lista_teste}")
    
    # Testando com uma lista já ordenada
    lista_ordenada = [1, 2, 3, 4, 5]
    bubble_sort(lista_ordenada)
    print(f"Lista já ordenada: {lista_ordenada}")
    
    # Testando com uma lista vazia
    lista_vazia = []
    bubble_sort(lista_vazia)
    print(f"Lista vazia: {lista_vazia}")