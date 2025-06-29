#include "avl_tree.h"

// Programa para executar apenas os casos específicos solicitados
int main() {
    printf("=======================================================\n");
    printf("  DEMONSTRAÇÃO DOS CASOS ESPECÍFICOS - ÁRVORE AVL\n");
    printf("=======================================================\n");
    printf("Este programa demonstra os 4 casos solicitados:\n");
    printf("1. Caso 1 - Rotação Simples (Inclusão)\n");
    printf("2. Caso 1 - Rotação Simples (Remoção)\n");
    printf("3. Caso 2 - Rotação Dupla (Inclusão)\n");
    printf("4. Caso 2 - Rotação Dupla (Remoção)\n");
    printf("=======================================================\n");

    // Executar todas as demonstrações
    demonstrateCaso1Inclusao();
    
    printf("\n\nPressione Enter para continuar para o próximo caso...");
    getchar();
    
    demonstrateCaso1Remocao();
    
    printf("\n\nPressione Enter para continuar para o próximo caso...");
    getchar();
    
    demonstrateCaso2Inclusao();
    
    printf("\n\nPressione Enter para continuar para o próximo caso...");
    getchar();
    
    demonstrateCaso2Remocao();
    
    printf("\n\n=======================================================\n");
    printf("         DEMONSTRAÇÃO COMPLETA FINALIZADA\n");
    printf("=======================================================\n");
    printf("Todos os 4 casos foram demonstrados com sucesso!\n");
    printf("Você pode compilar e executar 'main.c' para o menu completo.\n");
    
    return 0;
}
