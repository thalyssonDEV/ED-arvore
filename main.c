#include "avl_tree.h"

void showMenu() {
    printf("\n==============================================\n");
    printf("        ÁRVORE AVL - MENU PRINCIPAL\n");
    printf("==============================================\n");
    printf("1. Inserir valor na árvore\n");
    printf("2. Remover valor da árvore\n");
    printf("3. Imprimir árvore em in-ordem\n");
    printf("4. Imprimir fatores de balanceamento\n");
    printf("5. Imprimir altura da árvore\n");
    printf("6. Imprimir estrutura da árvore\n");
    printf("7. Demonstrar CASO 1 - Rotação Simples (Inclusão)\n");
    printf("8. Demonstrar CASO 1 - Rotação Simples (Remoção)\n");
    printf("9. Demonstrar CASO 2 - Rotação Dupla (Inclusão)\n");
    printf("10. Demonstrar CASO 2 - Rotação Dupla (Remoção)\n");
    printf("0. Sair\n");
    printf("==============================================\n");
    printf("Escolha uma opção: ");
}

int main() {
    Node* root = NULL;
    int choice, value;
    
    printf("==============================================\n");
    printf("    IMPLEMENTAÇÃO DE ÁRVORE AVL EM C\n");
    printf("==============================================\n");
    printf("Desenvolvido para demonstrar todas as operações\n");
    printf("de uma Árvore Binária de Busca Balanceada (AVL)\n");
    printf("==============================================\n");
    
    while (1) {
        showMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\nDigite o valor a ser inserido: ");
                scanf("%d", &value);
                printf("\n--- INSERÇÃO DO VALOR %d ---\n", value);
                root = insert(root, value);
                printf("Valor %d inserido com sucesso!\n", value);
                break;
                
            case 2:
                if (root == NULL) {
                    printf("\nÁrvore está vazia!\n");
                    break;
                }
                printf("\nDigite o valor a ser removido: ");
                scanf("%d", &value);
                printf("\n--- REMOÇÃO DO VALOR %d ---\n", value);
                root = deleteNode(root, value);
                printf("Remoção concluída!\n");
                break;
                
            case 3:
                printf("\n--- IMPRESSÃO EM IN-ORDEM ---\n");
                if (root == NULL) {
                    printf("Árvore está vazia!\n");
                } else {
                    printf("Árvore em in-ordem: ");
                    printInOrder(root);
                    printf("\n");
                }
                break;
                
            case 4:
                printf("\n--- FATORES DE BALANCEAMENTO ---\n");
                if (root == NULL) {
                    printf("Árvore está vazia!\n");
                } else {
                    printBalanceFactors(root);
                }
                break;
                
            case 5:
                printf("\n--- ALTURA DA ÁRVORE ---\n");
                printf("Altura da árvore: %d\n", calculateTreeHeight(root));
                break;
                
            case 6:
                printf("\n--- ESTRUTURA DA ÁRVORE ---\n");
                if (root == NULL) {
                    printf("Árvore está vazia!\n");
                } else {
                    printf("Estrutura da árvore (formato: valor(altura,fator_balanceamento)):\n");
                    printTreeStructure(root, 0);
                }
                break;
                
            case 7:
                demonstrateCaso1Inclusao();
                break;
                
            case 8:
                demonstrateCaso1Remocao();
                break;
                
            case 9:
                demonstrateCaso2Inclusao();
                break;
                
            case 10:
                demonstrateCaso2Remocao();
                break;
                
            case 0:
                printf("\nEncerrando o programa...\n");
                printf("Obrigado por usar o programa de Árvore AVL!\n");
                exit(0);
                
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
        
        printf("\nPressione Enter para continuar...");
        getchar(); // Limpa o buffer
        getchar(); // Aguarda Enter
    }
    
    return 0;
}
