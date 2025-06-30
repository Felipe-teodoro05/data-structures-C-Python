# Criação do algoritmo Bubble Sort com análise de sua complexidade
# Vamos entender melhor o motivo da sua complexidade ser O(n²).

def bubble_sort_analise(lista):
    """Ordena uma lista usando bubble sort."""
    # Definindo o tamanho da lista
    n = len(lista)

    comparacoes = 0

    # Loop para percorrer todos os elementos da lista
    for i in range(n-1):
        # Verificar se houve troca
        trocou = False
        # Loop interno para as comparações, com o alcance diminuindo
        for j in range(n-1-i):
            comparacoes += 1
            # Se o elemento atual for maior que o próximo, trocamos
            if lista[j]> lista[j+1]:
                lista[j], lista[j+1] = lista[j+1], lista[j]
                trocou = True
        # Se não houve troca, a lista já está ordenada
        if not trocou:
            break
    return comparacoes

if __name__ == "__main__":
    # Testando o algoritmo Bubble Sort com análise de comparações
    lista_teste = [64, 34, 25, 12, 22, 11, 90]
    print(f"Lista original: {lista_teste}")
    
    num_comparacoes = bubble_sort_analise(lista_teste)
    
    print(f"Lista ordenada: {lista_teste}")
    print(f"Número de comparações: {num_comparacoes}")
    print("-" * 20)

    # Testando com uma lista já ordenada (otimização deve funcionar)
    lista_ordenada = [1, 2, 3, 4, 5, 6, 7]
    print(f"Lista já ordenada: {lista_ordenada}")
    num_comparacoes_otimizado = bubble_sort_analise(lista_ordenada)
    print(f"Lista ordenada (não muda): {lista_ordenada}")
    print(f"Número de comparações (otimizado): {num_comparacoes_otimizado}\n\n")

    # Aqui vamos analisar a complexidade do algoritmo Bubble Sort
    # --- Cenário 1: Lista com 8 elementos ---
    n_pequeno = 8
    # list(range(n, 0, -1)) cria uma lista em ordem inversa, ex: [8, 7, 6...]
    lista_pequena = list(range(n_pequeno, 0, -1))
    
    print(f"--- ANÁLISE PRÁTICA COM n = {n_pequeno} ---")
    print(f"Lista de teste (invertida): {lista_pequena}")
    
    # Usamos uma cópia para que a lista original não seja alterada para algum futuro teste com essa mesma lista
    #[:] é para criar uma cópia idêntica, mas separada, da lista
    comparacoes_pequena = bubble_sort_analise(lista_pequena[:]) 
    print(f"Número de comparações para n={n_pequeno}: {comparacoes_pequena}")
    print("-" * 40)

    # --- Cenário 2: Lista com 16 elementos (o dobro) ---
    n_dobro = 16
    lista_dobro = list(range(n_dobro, 0, -1))
    
    print(f"--- ANÁLISE PRÁTICA COM n = {n_dobro} ---")
    print(f"Lista de teste (invertida): {lista_dobro}")
    
    comparacoes_dobro = bubble_sort_analise(lista_dobro[:])
    print(f"Número de comparações para n={n_dobro}: {comparacoes_dobro}")
    print("-" * 40)
    
    # --- Conclusão da Análise ---
    if comparacoes_pequena > 0:
        aumento = comparacoes_dobro / comparacoes_pequena
        print("\n--- CONCLUSÃO ---")
        print(f"Ao dobrar o tamanho da lista de {n_pequeno} para {n_dobro} (aumento de 2x),")
        print(f"o número de comparações aumentou de {comparacoes_pequena} para {comparacoes_dobro} (aumento de {aumento:.2f}x).")