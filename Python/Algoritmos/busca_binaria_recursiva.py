# Função que o usuário chamará para realizar a busca binária
def busca_binaria(lista_ordenada, alvo):        
    """Função principal (wrapper) para iniciar a busca binária recursiva."""
    tamanho_lista = len(lista_ordenada)
    # Usando a função recursiva para buscar o alvo com limites iniciais (0 e último índice)
    return busca_binaria_recursiva(lista_ordenada, alvo, 0,tamanho_lista - 1)

# Função privada que fará o trabalho de busca binária recursiva
def busca_binaria_recursiva(lista_ordenada, alvo, left, right):
    """Realiza uma busca binária recursiva em uma lista ordenada para encontrar o alvo e seu índice."""
    # Caso base: se o intervalo for inválido ou o alvo não estiver presente
    if left > right:
        return -1
    
    # Calcula o ponto médio
    mid = (left + right) // 2

    # Verifica se o elemento do meio é o alvo
    if lista_ordenada[mid] == alvo:
        return mid
    # Se o alvo é menor que o elemento do meio, busca na metade esquerda
    elif lista_ordenada[mid] > alvo:
        return busca_binaria_recursiva(lista_ordenada, alvo, left,   mid - 1)
    
    # Se o alvo é maior que o elemento do meio, busca na metade direita
    else:
        return busca_binaria_recursiva(lista_ordenada, alvo, mid + 1, right)