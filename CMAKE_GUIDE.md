# 🛠️ GUIA CMAKE - ÁRVORE AVL

## Configuração e Compilação

### 1. Configurar o projeto
```bash
cmake -B build
```

### 2. Compilar o projeto completo
```bash
cmake --build build
```

## 🎯 Targets Disponíveis

### Execução dos Programas
```bash
# Executar demonstração dos 4 casos específicos
cmake --build build --target run_demo

# Executar menu interativo completo
cmake --build build --target run_interactive

# Executar ambos sequencialmente (primeiro demo, depois interativo)
cmake --build build --target run_all
```

### Limpeza
```bash
# Limpar arquivos de build
cmake --build build --target clean_all

# Ou remover pasta build completamente
rm -rf build          # Linux/Mac
Remove-Item -Recurse build  # PowerShell
```

## 📁 Estrutura Gerada

Após compilar, a estrutura fica:
```
ellane_trabaio/
├── build/
│   ├── bin/
│   │   ├── avl_tree.exe      # Menu interativo
│   │   └── demo_casos.exe    # Demonstração dos casos
│   └── ...outros arquivos cmake...
├── CMakeLists.txt
├── avl_tree.h
├── avl_tree.c
├── main.c
└── demo_casos.c
```

## 🚀 Execução Direta

Após compilar, você pode executar diretamente:
```bash
# Windows
.\build\bin\demo_casos.exe
.\build\bin\avl_tree.exe

# Linux/Mac
./build/bin/demo_casos
./build/bin/avl_tree
```

## ⚙️ Configurações do CMake

O projeto foi configurado com:
- **Padrão C**: C99
- **Flags de compilação**: `-Wall -Wextra -Wpedantic`
- **Build type padrão**: Release (otimizado)
- **Compatibilidade**: Windows, Linux, macOS

### Alterar Build Type
```bash
# Debug (com símbolos de debug)
cmake -B build -DCMAKE_BUILD_TYPE=Debug

# Release (otimizado)
cmake -B build -DCMAKE_BUILD_TYPE=Release
```

### Usar Compilador Específico
```bash
# GCC/MinGW
cmake -B build -G "MinGW Makefiles"

# Visual Studio (Windows)
cmake -B build -G "Visual Studio 17 2022"

# Ninja (mais rápido)
cmake -B build -G "Ninja"
```

## 🎮 Comandos Rápidos

```bash
# Setup completo (configurar + compilar + executar demo)
cmake -B build && cmake --build build && cmake --build build --target run_demo

# Rebuild completo
rm -rf build && cmake -B build && cmake --build build

# Compilar e executar interativo
cmake --build build && cmake --build build --target run_interactive
```

## 🐛 Troubleshooting

### Erro de compilador não encontrado:
```bash
# Instalar build tools necessários
# Windows: Instalar Visual Studio Build Tools ou MinGW
# Linux: sudo apt install build-essential cmake
# macOS: xcode-select --install
```

### Limpar cache do CMake:
```bash
rm -rf build
cmake -B build
```

### Forçar recompilação:
```bash
cmake --build build --clean-first
```

## 📊 Informações do Build

Durante a configuração, o CMake exibe:
- Versão do projeto
- Compilador usado
- Padrão C
- Build type
- Instruções de uso

## 🎯 Vantagens do CMake

✅ **Multiplataforma**: Funciona em Windows, Linux, macOS
✅ **Flexível**: Suporta diferentes compiladores
✅ **Profissional**: Padrão da indústria
✅ **Targets customizados**: Facilita execução
✅ **Gerenciamento de dependências**: Estruturado
✅ **Build otimizado**: Recompila apenas o necessário

---

**O CMake oferece uma solução robusta e profissional para compilação do projeto!**
