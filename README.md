# 📚 Projeto de Estudo: Estruturas de Dados e Algoritmos em C (e futuramente Python) 🚀

Bem-vindo(a) ao meu repositório de implementações de Estruturas de Dados e Algoritmos! Este projeto serve como um registro pessoal de estudo e prática, contendo exemplos de diversas estruturas e algoritmos fundamentais, implementados em C e, futuramente, em Python. O objetivo é consolidar o aprendizado e ter um material de consulta claro e prático.

## 🌟 Sobre o Projeto

Este repositório é dedicado a demonstrar a implementação e o funcionamento de estruturas de dados clássicas e algoritmos importantes. Cada conceito é (ou será) implementado em:

* **C (`/C`)**: Para uma compreensão mais profunda do funcionamento interno, gerenciamento de memória e performance. Ideal para entender os "bastidores".
* **Python (`/Python`)**: Para uma abordagem de mais alto nível, focada na facilidade de uso e aplicação com a sintaxe expressiva do Python (planejado).

## 📁 Estrutura de Pastas

O repositório está organizado da seguinte maneira para facilitar a navegação, refletindo os tópicos de estudo:

.
├── C/                            # Contém todas as implementações em C
│   ├── Árvores/                  # Implementações de diferentes tipos de árvores
│   │   ├── Arvore_Binaria.cpp
│   │   ├── Arvore_AVL.cpp
|   |   ├── Arvore_Busc.cpp   
│   │   └── Arvore_RN.cpp
│   ├── Busca/                    # Algoritmos de busca
│   │   ├── busca_sequencial.cpp
│   │   └── busca_binaria.cpp     # (Pode requerer dados ordenados)
│   ├── Filas/                    # Implementações de filas (Queue)
│   │   ├── fila_simples.cpp
│   │   └── Deque.cpp
│   ├── Grafos/                   # Implementações de grafos e seus algoritmos
│   │   └── Grafo.cpp
│   ├── Intro/                    # Códigos introdutórios, exemplos básicos de C ou conceitos gerais
│   │   ├── Multi_Matriz.cpp
|   |   ├── Transpor_Matriz.cpp   
│   │   └── Vetores.cpp
│   ├── Listas/                   # Implementações de diferentes tipos de listas
│   │   ├── lista duplamente encadeada.cpp
│   │   ├── lista encadeamento simples.cpp
│   ├── Ordenação/                # Algoritmos de ordenação
│   │   ├── bubble_Sort.c
│   │   ├── Insertion_Sort.c
│   │   └── Ordenação Direta.cpp
│   └── Pilhas/                   # Implementações de pilhas (Stack)
│       ├── Pilha.cpp
├── Python/                       # Contém todas as implementações em Python (Em breve!)
│   └── ...
├── .gitignore                    # Especifica arquivos e pastas ignorados pelo Git
└── README.md                     # Este arquivo que você está lendo :)


## 🛠️ Estruturas de Dados e Algoritmos (Conteúdo em `/C++`)

Abaixo está o status atual das implementações e tópicos abordados na pasta `C++/`.

### `C++/Listas/`
* [ ] Lista Sequencial (Array)
* [x] Lista Encadeada Simples (`lista_encadeamento_simples.cpp`)
* [x] Lista Duplamente Encadeada (`lista_duplamente_encadeada.cpp`)
* [ ] Lista Circular (Simples/Dupla)

### `C++/Pilhas/` (Stack)
* [x] Pilha (Implementação Genérica em `Pilha.cpp` - *especificar se baseada em array ou lista, ou ambas*)
    * [ ] Implementação com Array
    * [ ] Implementação com Lista Encadeada

### `C++/Filas/` (Queue)
* [x] Fila Simples (`fila_simples.cpp` - *especificar se baseada em array ou lista*)
* [x] Deque (Double-Ended Queue) (`Deque.cpp`)
* [ ] Fila de Prioridade (Heap)

### `C++/Árvores/`
* [x] Árvore Binária (`Arvore_Binaria.cpp`)
* [x] Árvore Binária de Busca (BST) (`Arvore_Busc.cpp`)
* [x] Árvore AVL (`Arvore_AVL.cpp`)
* [x] Árvore Rubro-Negra (Red-Black Tree) (`Arvore_RN.cpp`)
* [ ] Árvore B / B+
* [ ] Heap (Min-Heap, Max-Heap)

### `C++/Grafos/`
* [x] Implementação de Grafo (`Grafo.cpp` - *especificar representação: Matriz ou Lista de Adjacência*)
    * [ ] Representação por Matriz de Adjacência
    * [ ] Representação por Lista de Adjacência
* **Algoritmos:**
    * [ ] Busca em Largura (BFS)
    * [ ] Busca em Profundidade (DFS)
    * [ ] Dijkstra (Caminho Mínimo)
    * [ ] Kruskal / Prim (Árvore Geradora Mínima)

### `C++/Busca/` (Algoritmos de Busca)
* [x] Busca Sequencial (Linear) (`busca_sequencial.cpp`)
* [x] Busca Binária (para dados ordenados) (`busca_binaria.cpp`)
* [ ] Busca Ternária
* [ ] Busca por Interpolação

### `C++/Ordenação/` (Algoritmos de Ordenação)
* **Algoritmos Básicos:**
    * [x] Bubble Sort (`bubble_Sort.cpp`)
    * [ ] Selection Sort
    * [x] Insertion Sort (`Insertion_Sort.cpp`)
    * [x] Método de Ordenação Direta (`Ordenação Direta.cpp`)
* **Algoritmos Eficientes (N log N):**
    * [ ] Merge Sort
    * [ ] Quick Sort
    * [ ] Heap Sort
* **Algoritmos Lineares (Casos Específicos):**
    * [ ] Counting Sort
    * [ ] Radix Sort
    * [ ] Bucket Sort

### `C++/Intro/` (Conteúdo de Apoio e Exemplos)
* [x] Operações com Vetores (`Vetores.cpp`)
* [x] Multiplicação de Matrizes (`Multi_Matriz.cpp`)
* [x] Transposição de Matrizes (`Transpor_Matriz.cpp`)
* [ ] Outros conceitos fundamentais de C++

## ⚙️ Como Usar e Compilar (Exemplo Genérico para C++)

1.  **Clone o repositório:**
    ```bash
    git clone [https://github.com/Felipe-teodoro05/data-structures-C-Python.git](https://github.com/Felipe-teodoro05/data-structures-C-Python.git)
    cd NOME-DO-REPOSITORIO/C++/NomeDaPastaDoTopico
    ```
    
2.  **Compile os arquivos:**
    Você precisará de um compilador C++ (como G++ ou Clang++).
    Exemplo para compilar um arquivo `.cpp` (que pode ter uma função `main` para teste):
    ```bash
    g++ -Wall -Wextra -std=c++17 nome_do_arquivo.cpp -o executavel_teste
    ```
    Ou, se você tiver múltiplos arquivos (ex: um `.cpp` com a implementação e outro com o `main`):
    ```bash
    g++ -Wall -Wextra -std=c++17 implementacao.cpp main_teste.cpp -o executavel_teste
    ```
    * `-Wall -Wextra`: Ativa a maioria dos avisos úteis do compilador.
    * `-std=c++17`: Define o padrão da linguagem C++ (ajuste para c++11, c++14, c++20 se preferir/necessário).
    * `-o executavel_teste`: Define o nome do arquivo de saída.

    Se você tiver um `Makefile` ou usar um sistema de build como CMake, siga as instruções específicas do projeto.

3.  **Execute o programa de exemplo:**
    ```bash
    ./executavel_teste
    ```

## 🐍 Implementações em Python (Pasta `/Python`)

*(Planejado para o futuro)*
* [ ] Lista Encadeada Simples
* [ ] Pilha
* [ ] Fila
* [ ] Árvore Binária de Busca (BST)
* [ ] Tabela Hash
* [ ] Grafo


## 🤝 Contribuições (Opcional)

Embora este seja um repositório de estudo pessoal, se você tiver sugestões, correções ou melhorias, sinta-se à vontade para abrir uma "Issue" ou, se desejar, um "Pull Request".

1.  Faça um **Fork** deste repositório.
2.  Crie uma nova **Branch**: `git checkout -b feature/SuaMelhoriaIncrivel`
3.  Faça suas alterações e **Commits**: `git commit -m "Adiciona: SuaMelhoriaIncrivel"`
4.  Faça o **Push** para a sua Branch: `git push origin feature/SuaMelhoriaIncrivel`
5.  Abra um **Pull Request**.

---

Criado com dedicação por **Felipe Teodoro Bandeira**.

➡️ Conecte-se comigo: [Seu LinkedIn](https://www.linkedin.com/in/felipe-teodoro-bandeira/) | [Seu GitHub](https://github.com/Felipe-teodoro05)
```

---
