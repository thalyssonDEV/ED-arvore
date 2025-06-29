# 🎥 ROTEIRO PARA VÍDEO - ÁRVORE AVL (15 minutos)

## 📋 CHECKLIST PRÉ-GRAVAÇÃO
- [ ] Projeto compilado com CMake
- [ ] Executáveis funcionando (demo_casos.exe e avl_tree.exe)
- [ ] Slides/material teórico preparado
- [ ] Terminal/IDE configurado para apresentação

---

## 🎬 ROTEIRO DETALHADO

### **[0:00 - 2:00] INTRODUÇÃO (2 min)**
```
📱 O QUE FALAR:
- Apresentação do projeto: "Implementação completa de Árvore AVL em C"
- Importância: BST comum pode virar lista O(n), AVL garante O(log n)
- Características: Auto-balanceamento automático após inserção/remoção
```

**🖥️ O QUE MOSTRAR:**
- Estrutura do projeto no explorador de arquivos
- Código fonte (avl_tree.h, avl_tree.c)

---

### **[2:00 - 5:00] CONCEITOS FUNDAMENTAIS (3 min)**
```
📱 CONCEITOS CHAVE:
- Fator de Balanceamento: FB = altura_esquerda - altura_direita
- Propriedade AVL: |FB| ≤ 1 para todos os nós
- Quando |FB| > 1 → Precisa rotação!
```

**🖥️ O QUE MOSTRAR:**
- Arquivo `CONCEITOS_TEORICOS.md`
- Slides com exemplos visuais:
  ```
  Balanceada:     Desbalanceada:
      20              30 (FB=+2)
     /  \            /
    10   30         20 (FB=+1) 
                   /
                  10
  ```

---

### **[5:00 - 9:00] CASO 1: ROTAÇÕES SIMPLES (4 min)**

#### **5:00-6:30: Rotação Simples - INCLUSÃO**
```
📱 EXPLICAR:
"Vamos ver o Caso 1: Rotação Simples para inclusão
Inserindo 30, 20, 10 - isso causa um caso LL"
```

**🖥️ EXECUTAR:**
```bash
cmake --build build --target run_demo
```

**🗣️ NARRAR enquanto executa:**
- "Inserindo 30... árvore OK"
- "Inserindo 20... ainda balanceada"
- "Inserindo 10... DESBALANCEADA! FB=+2"
- "Sistema detecta caso LL → Rotação simples DIREITA"
- "Resultado: 20 vira raiz, 10 e 30 filhos"

#### **6:30-7:30: Rotação Simples - REMOÇÃO**
```
📱 EXPLICAR:
"Agora Caso 1 para remoção - construímos árvore e removemos nó específico"
```

**🗣️ NARRAR:**
- "Árvore inicial balanceada"
- "Removendo nó 5... causa desbalanceamento"
- "Sistema aplica rotação simples automática"

---

### **[9:00 - 13:00] CASO 2: ROTAÇÕES DUPLAS (4 min)**

#### **9:00-10:30: Rotação Dupla - INCLUSÃO**
```
📱 EXPLICAR:
"Caso 2: Rotação Dupla - mais complexa
Inserindo 30, 10, 20 - causa caso LR"
```

**🗣️ NARRAR:**
- "Caso LR: filho esquerdo tem filho direito pesado"
- "Precisa 2 rotações: primeiro esquerda no nó 10, depois direita no 30"
- "Resultado final: 20 vira raiz"

#### **10:30-12:00: Rotação Dupla - REMOÇÃO**
```
📱 EXPLICAR:
"Remoção que causa rotação dupla - situação mais complexa"
```

**🗣️ NARRAR:**
- "Removendo múltiplos nós causa desbalanceamento complexo"
- "Sistema detecta e aplica rotação dupla automaticamente"

---

### **[13:00 - 15:00] DEMONSTRAÇÃO INTERATIVA (2 min)**

**🖥️ EXECUTAR:**
```bash
cmake --build build --target run_interactive
```

**🗣️ DEMONSTRAR:**
1. Inserir alguns valores manualmente
2. Mostrar fatores de balanceamento
3. Mostrar estrutura da árvore
4. Imprimir em in-ordem
5. Calcular altura

```
📱 VALORES SUGERIDOS PARA INSERIR:
50, 30, 70, 20, 40, 60, 80, 10
(Cria árvore interessante com várias rotações)
```

---

## 🎯 COMANDOS PARA EXECUTAR NO VÍDEO

### Preparação:
```bash
cd ellane_trabaio
cmake -B build -G "MinGW Makefiles"
cmake --build build
```

### Durante o vídeo:
```bash
# Para demonstração automática dos 4 casos
cmake --build build --target run_demo

# Para menu interativo
cmake --build build --target run_interactive
```

---

## 💡 DICAS PARA GRAVAÇÃO

### ✅ DO:
- **Fale devagar e claro**
- **Pause entre seções** para respirar
- **Mostre o código** relevante enquanto explica
- **Use zoom** para destacar partes importantes
- **Teste os comandos** antes de gravar

### ❌ NÃO:
- Não se apresse
- Não pule as explicações teóricas
- Não execute comandos sem explicar
- Não grave com erros de compilação

---

## 📊 ESTRUTURA VISUAL SUGERIDA

```
[Tela dividida]
- Lado esquerdo: Terminal com execução
- Lado direito: Código fonte ou slides

[Momentos de código]
- Zoom nas funções de rotação
- Destaque nos fatores de balanceamento
- Estrutura Node bem visível
```

---

## 🎤 FRASES CHAVE PARA USAR

- *"A árvore AVL mantém automaticamente o balanceamento..."*
- *"Quando o fator de balanceamento excede 1, precisamos de rotação..."*
- *"Veja como o sistema detecta automaticamente o tipo de rotação..."*
- *"Este é um caso LL, que requer rotação simples para direita..."*
- *"A rotação dupla acontece em dois passos..."*
- *"O resultado final é uma árvore perfeitamente balanceada..."*

---

## ✅ VERIFICAÇÃO FINAL

Antes de gravar, confirme:
- [ ] `cmake --build build --target run_demo` funciona
- [ ] `cmake --build build --target run_interactive` funciona  
- [ ] Todos os 4 casos são demonstrados corretamente
- [ ] Menu interativo responde a todas as opções
- [ ] Código fonte está limpo e legível
- [ ] Material teórico está organizado

---

**🎬 SEU PROJETO ESTÁ 100% PRONTO PARA GRAVAÇÃO!**
