# Árvore AVL em C

Este projeto implementa uma estrutura de dados do tipo **Árvore AVL** (Árvore Binária de Busca Balanceada) em linguagem C, com todas as operações fundamentais e demonstrações específicas dos casos de rotação.

## 📋 Funcionalidades Implementadas

### Operações Principais:
- ✅ **Inserção** de valores na árvore
- ✅ **Remoção** de valores da árvore
- ✅ **Impressão em in-ordem** da árvore
- ✅ **Cálculo e impressão dos fatores de balanceamento** de todos os nós
- ✅ **Cálculo da altura** da árvore
- ✅ **Visualização da estrutura** da árvore

### Demonstrações Específicas:
- ✅ **Caso 1**: Rotação Simples (para direita/esquerda)
  - Exemplo com inclusão de nó
  - Exemplo com remoção de nó
- ✅ **Caso 2**: Rotação Dupla (direita-esquerda/esquerda-direita)
  - Exemplo com inclusão de nó
  - Exemplo com remoção de nó

## 🛠️ Compilação e Execução

### Usando CMake (Recomendado):
```bash
# Configurar o projeto
cmake -B build

# Compilar o projeto
cmake --build build

# Executar demonstração dos 4 casos específicos
cmake --build build --target run_demo

# Executar menu interativo completo
cmake --build build --target run_interactive

# Executar ambos sequencialmente
cmake --build build --target run_all

# Limpar arquivos de build
cmake --build build --target clean_all
```

### Execução direta dos executáveis:
```bash
# Após compilar com CMake
./build/bin/demo_casos      # Demonstração dos casos
./build/bin/avl_tree        # Menu interativo
```

### Compilação manual:
```bash
gcc -Wall -Wextra -std=c99 -g main.c avl_tree.c -o avl_tree
```

## 📁 Estrutura do Projeto

```
ellane_trabaio/
├── CMakeLists.txt          # Configuração do CMake
├── avl_tree.h              # Cabeçalho com declarações das funções
├── avl_tree.c              # Implementação das funções da árvore AVL
├── main.c                  # Programa principal com menu interativo
├── demo_casos.c            # Programa de demonstração dos casos específicos
├── README.md               # Este arquivo
├── CONCEITOS_TEORICOS.md   # Material para apresentação
└── INSTRUCOES.md           # Guia de execução
```

## 🎯 Como Usar

1. **Compile o programa** usando `make` ou `gcc`
2. **Execute** o programa com `./avl_tree`
3. **Use o menu interativo** para:
   - Inserir e remover valores
   - Visualizar a árvore e seus fatores de balanceamento
   - Executar as demonstrações específicas dos casos de rotação

## 📊 Casos de Rotação Demonstrados

### Caso 1: Rotação Simples
- **LL (Left-Left)**: Rotação simples para direita
- **RR (Right-Right)**: Rotação simples para esquerda

### Caso 2: Rotação Dupla
- **LR (Left-Right)**: Rotação dupla (esquerda no filho, direita na raiz)
- **RL (Right-Left)**: Rotação dupla (direita no filho, esquerda na raiz)

## 🔍 Exemplos de Saída

O programa mostra:
- A estrutura visual da árvore
- Os fatores de balanceamento de cada nó
- As rotações sendo executadas em tempo real
- A sequência de operações para cada caso específico

## 📝 Características Técnicas

- **Linguagem**: C (padrão C99)
- **Estrutura**: Árvore binária auto-balanceada
- **Complexidade**: O(log n) para inserção, remoção e busca
- **Memória**: Alocação dinâmica para os nós
- **Balanceamento**: Automático após cada inserção/remoção

## 🎥 Demonstrações Incluídas

O programa inclui 4 demonstrações automáticas:
1. **Caso 1 - Inclusão**: Sequência que gera rotação simples
2. **Caso 1 - Remoção**: Remoção que causa rotação simples
3. **Caso 2 - Inclusão**: Sequência que gera rotação dupla
4. **Caso 2 - Remoção**: Remoção que causa rotação dupla

Cada demonstração mostra passo a passo como a árvore se comporta e quais rotações são executadas.

## 🏗️ Estrutura dos Nós

```c
typedef struct Node {
    int data;           // Valor armazenado
    struct Node* left;  // Ponteiro para filho esquerdo
    struct Node* right; // Ponteiro para filho direito
    int height;         // Altura do nó
} Node;
```

## 📋 Requisitos do Sistema

- Compilador GCC ou similar
- Sistema operacional Windows, Linux ou macOS
- Make (opcional, para usar o Makefile)

---

**Desenvolvido para fins educacionais** - Implementação completa de Árvore AVL com todas as operações e casos de rotação demonstrados.
