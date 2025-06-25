# Vou ter alguns ponteiros como left, right, mid 
# Lista precisa estar ordenada obrigatoriamente
# def busca_binaria(lista_ordenada, alvo)
# OBS: preciso garantir que minha condição seja while left <= right, pois se for while left < right, o último elemento não será verificado

def busca_binaria(lista_ordenada, alvo):
    """Realiza uma busca binária em uma lista ordenada para encontrar o alvo e seu índice."""
    left = 0
    right = len(lista_ordenada) - 1

    # Fazer loop para ver se o alvo está na lista
    while left <= right:
        mid = (left+ right) //2

        # Verifica se o elemento do meio é o alvo
        if lista_ordenada[mid] == alvo:
            return mid
        
        # Se o elemento do meio for menor que o alvo, move o ponteiro esquerdo
        elif lista_ordenada[mid] < alvo:
            left = mid + 1

        # Se o elemento do meio for maior que o alvo, move o ponteiro direito
        else:
            right = mid - 1
    
    # Se o alvo não for encontrado, retorna -1
    return -1

if __name__ == "__main__":
    lista_teste = [2, 5, 8, 12, 16, 23, 38, 56, 72, 91]
    print(9//2) 

    print(f"Testando com a lista: {lista_teste}\n")

    # Alvo está presente no meio
    alvo1 = 16
    indice1 = busca_binaria(lista_teste, alvo1)
    print(f"Buscando por {alvo1}... Resultado: índice {indice1} (Esperado: 4)")

    # Alvo não está presente
    alvo2 = 15
    indice2 = busca_binaria(lista_teste, alvo2)
    print(f"Buscando por {alvo2}... Resultado: {indice2} (Esperado: -1)")

    # Alvo é o primeiro elemento
    alvo3 = 2
    indice3 = busca_binaria(lista_teste, alvo3)
    print(f"Buscando por {alvo3}... Resultado: índice {indice3} (Esperado: 0)")

    # Alvo é o último elemento
    alvo4 = 91
    indice4 = busca_binaria(lista_teste, alvo4)
    print(f"Buscando por {alvo4}... Resultado: índice {indice4} (Esperado: 9)")
    
    # Lista vazia
    lista_vazia = []
    alvo5 = 5
    indice5 = busca_binaria(lista_vazia, alvo5)
    print(f"Buscando por {alvo5} em lista vazia... Resultado: {indice5} (Esperado: -1)")
