# Nova descoberta: valores ASCII são números inteiros que representam caracteres, para saber basta utilizar a função ord(para saber o número da letra) e chr(para saber a letra do número).
# Para cuidar de colisões, vamos usar Encadeamento Separado, implementada com uma lista Python para cada posição
# Atributos: size (tamanho da tabela), tabela (lista de listas para armazenar os valores).
# métodos: __init__, _hash, put, get e remove

class HashTable:
    """Implementa uma Tabela Hash com tratamento de colisões usando listas encadeadadas"""
    def __init__(self, size):
        self.size = size
        self.tabela = [[]for _ in range(size)]
    
    def _hash(self, key):
        """Calcula o índice da tabela hash para uma chave"""
        return hash(key) % self.size 
    
    def put(self, key, value):
        """Insere um par chave-valor na tabela hash"""
        # Calcula o índice da tabela hash para a chave
        indice = self._hash(key)
        # Encontrar o bucket correspondente
        bucket = self.tabela[indice]
        
        # Verifica se a chave já existe no bucket
        for i, (key_existente, value_existente) in enumerate(bucket):
            if key_existente == key:
                # Atualiza o valor se a chave já existir
                bucket[i] = (key, value)
                return
        # Se a chave não existir, adiciona o novo par chave-valor
        bucket.append((key,value))
    
    def get(self,key):
        """Obtém o valor associado a uma chave na tabela hash"""
        # Calcula o índice da tabela hash para a chave
        indice = self._hash(key)
        # Encontrar o bucket correspondente
        bucket = self.tabela[indice]

        # Procura a chave no bucket
        for key_existente, value_existente in bucket:
            if key_existente == key:
                return value_existente
        # Retorna None se a chave não for encontrada
        return None

    def remove(self, key):
        """Remove um par chave-valor da tabela hash"""
        # Calcula o índice da tabela hash para a chave
        indice = self._hash(key)
        # Encontrar o bucket correspondente
        bucket = self.tabela[indice]

        # Procura a chave no bucket
        for i, (key_existente, value_existente) in enumerate(bucket):
            if key_existente ==key:
                # Remove o par chave-valor se a chave for encontrada
                del bucket[i]
                return True
        # Retorna False se a chave não for encontrada
        return False

# Bloco de execução principal para testes completos
if __name__ == "__main__":
    print("--- INICIANDO TESTES COMPLETOS DA TABELA HASH ---")
    
    # Criaremos uma tabela de tamanho 5 para facilitar a visualização de colisões
    tabela = HashTable(size=5)
    
    # --- 1. Testando o método put() ---
    print("\n[FASE 1: Testando put()]")
    tabela.put("maçã", 10)
    tabela.put("banana", 20)
    tabela.put("uva", 30)
    print("Tabela após inserções iniciais:")
    print(tabela.tabela)

    print("\nForçando uma colisão...")
    # Em uma tabela de tamanho 5, as chaves 12 e 17 colidem no índice 2.
    # (12 % 5 = 2) e (17 % 5 = 2)
    tabela.put(12, "sou o doze")
    tabela.put(17, "sou o dezessete")
    print("Tabela após forçar colisão:")
    print(tabela.tabela)

    print("\nAtualizando um valor existente...")
    tabela.put("maçã", 99)
    print("Tabela após atualizar 'maçã':")
    print(tabela.tabela)
    
    # --- 2. Testando o método get() ---
    print("\n[FASE 2: Testando get()]")
    print(f"Valor para 'maçã' (esperado: 99): {tabela.get('maçã')}")
    print(f"Valor para 'banana' (esperado: 20): {tabela.get('banana')}")
    # Testando busca em um bucket com colisão
    print(f"Valor para 17 (esperado: 'sou o dezessete'): {tabela.get(17)}")
    print(f"Valor para 12 (esperado: 'sou o doze'): {tabela.get(12)}")
    # Testando busca por chave inexistente
    print(f"Valor para 'pera' (esperado: None): {tabela.get('pera')}")

    # --- 3. Testando o método remove() ---
    print("\n[FASE 3: Testando remove()]")
    print("\nRemovendo uma chave de um bucket com colisão (chave 12)...")
    resultado_remocao = tabela.remove(12)
    print(f"Remoção bem-sucedida? (Esperado: True): {resultado_remocao}")
    print("Tabela após remover 12:")
    print(tabela.tabela)
    print(f"Buscando por 12 novamente (esperado: None): {tabela.get(12)}")

    print("\nRemovendo uma chave que está sozinha em um bucket ('banana')...")
    resultado_remocao = tabela.remove("banana")
    print(f"Remoção bem-sucedida? (Esperado: True): {resultado_remocao}")
    print("Tabela após remover 'banana':")
    print(tabela.tabela)

    print("\nTentando remover uma chave que não existe ('abacaxi')...")
    resultado_remocao = tabela.remove("abacaxi")
    print(f"Remoção bem-sucedida? (Esperado: False): {resultado_remocao}")
    print("Tabela após tentar remover 'abacaxi':")
    print(tabela.tabela)
    
    print("\n--- FIM DOS TESTES ---")