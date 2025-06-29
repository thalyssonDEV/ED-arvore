#include "avl_tree.h"

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Função para obter a altura de um nó
int getHeight(Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Função para obter o fator de balanceamento de um nó
int getBalance(Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Função auxiliar para retornar o máximo entre dois inteiros
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Rotação simples para direita
Node* rightRotate(Node* y) {
    printf("Executando rotação simples para DIREITA\n");
    Node* x = y->left;
    Node* T2 = x->right;

    // Realizando a rotação
    x->right = y;
    y->left = T2;

    // Atualizando as alturas
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    // Retornando a nova raiz
    return x;
}

// Rotação simples para esquerda
Node* leftRotate(Node* x) {
    printf("Executando rotação simples para ESQUERDA\n");
    Node* y = x->right;
    Node* T2 = y->left;

    // Realizando a rotação
    y->left = x;
    x->right = T2;

    // Atualizando as alturas
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    // Retornando a nova raiz
    return y;
}

// Função para inserir um nó na árvore AVL
Node* insert(Node* node, int data) {
    // 1. Inserção normal da BST
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else // Dados iguais não são permitidos
        return node;

    // 2. Atualizar a altura do nó ancestral
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // 3. Obter o fator de balanceamento
    int balance = getBalance(node);

    // 4. Se o nó se tornar desbalanceado, há 4 casos

    // Caso Esquerda-Esquerda (LL)
    if (balance > 1 && data < node->left->data) {
        printf("Caso LL detectado - rotação simples para direita necessária\n");
        return rightRotate(node);
    }

    // Caso Direita-Direita (RR)
    if (balance < -1 && data > node->right->data) {
        printf("Caso RR detectado - rotação simples para esquerda necessária\n");
        return leftRotate(node);
    }

    // Caso Esquerda-Direita (LR)
    if (balance > 1 && data > node->left->data) {
        printf("Caso LR detectado - rotação dupla necessária\n");
        printf("Primeiro: rotação simples para esquerda no filho esquerdo\n");
        node->left = leftRotate(node->left);
        printf("Depois: rotação simples para direita na raiz\n");
        return rightRotate(node);
    }

    // Caso Direita-Esquerda (RL)
    if (balance < -1 && data < node->right->data) {
        printf("Caso RL detectado - rotação dupla necessária\n");
        printf("Primeiro: rotação simples para direita no filho direito\n");
        node->right = rightRotate(node->right);
        printf("Depois: rotação simples para esquerda na raiz\n");
        return leftRotate(node);
    }

    // Retorna o nó (não modificado)
    return node;
}

// Função para encontrar o nó com valor mínimo
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

// Função para remover um nó da árvore AVL
Node* deleteNode(Node* root, int data) {
    // 1. Remoção normal da BST
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        // Nó a ser removido encontrado
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
        } else {
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    // 2. Atualizar altura do nó atual
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    // 3. Obter o fator de balanceamento
    int balance = getBalance(root);

    // 4. Se desbalanceado, há 4 casos

    // Caso Esquerda-Esquerda (LL)
    if (balance > 1 && getBalance(root->left) >= 0) {
        printf("Após remoção: Caso LL detectado - rotação simples para direita necessária\n");
        return rightRotate(root);
    }

    // Caso Esquerda-Direita (LR)
    if (balance > 1 && getBalance(root->left) < 0) {
        printf("Após remoção: Caso LR detectado - rotação dupla necessária\n");
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Caso Direita-Direita (RR)
    if (balance < -1 && getBalance(root->right) <= 0) {
        printf("Após remoção: Caso RR detectado - rotação simples para esquerda necessária\n");
        return leftRotate(root);
    }

    // Caso Direita-Esquerda (RL)
    if (balance < -1 && getBalance(root->right) > 0) {
        printf("Após remoção: Caso RL detectado - rotação dupla necessária\n");
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Função para imprimir a árvore em in-ordem
void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}

// Função para imprimir os fatores de balanceamento
void printBalanceFactors(Node* root) {
    if (root != NULL) {
        printBalanceFactors(root->left);
        printf("Nó %d: FB = %d\n", root->data, getBalance(root));
        printBalanceFactors(root->right);
    }
}

// Função para calcular a altura da árvore
int calculateTreeHeight(Node* root) {
    if (root == NULL)
        return -1;
    return root->height - 1;
}

// Função para imprimir a estrutura da árvore
void printTreeStructure(Node* root, int space) {
    if (root == NULL)
        return;

    space += 10;

    printTreeStructure(root->right, space);

    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d(h:%d,fb:%d)\n", root->data, root->height, getBalance(root));

    printTreeStructure(root->left, space);
}

// Demonstrações dos casos específicos

// CASO 1: Rotação simples - INCLUSÃO
void demonstrateCaso1Inclusao() {
    printf("\n==================================================\n");
    printf("CASO 1: ROTAÇÃO SIMPLES - EXEMPLO DE INCLUSÃO\n");
    printf("==================================================\n");
    
    Node* root = NULL;
    
    printf("\n--- Inserindo sequência que causa rotação simples ---\n");
    printf("Inserindo valores: 30, 20, 10 (causa rotação LL)\n\n");
    
    root = insert(root, 30);
    printf("Após inserir 30:\n");
    printTreeStructure(root, 0);
    
    root = insert(root, 20);
    printf("\nApós inserir 20:\n");
    printTreeStructure(root, 0);
    
    root = insert(root, 10);
    printf("\nApós inserir 10 (rotação será executada):\n");
    printTreeStructure(root, 0);
    
    printf("\nÁrvore final em in-ordem: ");
    printInOrder(root);
    printf("\n");
    
    printf("\nFatores de balanceamento:\n");
    printBalanceFactors(root);
    
    printf("\nAltura da árvore: %d\n", calculateTreeHeight(root));
}

// CASO 1: Rotação simples - REMOÇÃO
void demonstrateCaso1Remocao() {
    printf("\n==================================================\n");
    printf("CASO 1: ROTAÇÃO SIMPLES - EXEMPLO DE REMOÇÃO\n");
    printf("==================================================\n");
    
    Node* root = NULL;
    
    // Construindo árvore inicial
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);
    
    printf("Árvore inicial:\n");
    printTreeStructure(root, 0);
    
    printf("\n--- Removendo nó que causa desbalanceamento ---\n");
    printf("Removendo o nó 5 (causará rotação simples):\n\n");
    
    root = deleteNode(root, 5);
    
    printf("\nÁrvore após remoção:\n");
    printTreeStructure(root, 0);
    
    printf("\nÁrvore em in-ordem: ");
    printInOrder(root);
    printf("\n");
    
    printf("\nFatores de balanceamento:\n");
    printBalanceFactors(root);
    
    printf("\nAltura da árvore: %d\n", calculateTreeHeight(root));
}

// CASO 2: Rotação dupla - INCLUSÃO
void demonstrateCaso2Inclusao() {
    printf("\n==================================================\n");
    printf("CASO 2: ROTAÇÃO DUPLA - EXEMPLO DE INCLUSÃO\n");
    printf("==================================================\n");
    
    Node* root = NULL;
    
    printf("\n--- Inserindo sequência que causa rotação dupla ---\n");
    printf("Inserindo valores: 30, 10, 20 (causa rotação LR)\n\n");
    
    root = insert(root, 30);
    printf("Após inserir 30:\n");
    printTreeStructure(root, 0);
    
    root = insert(root, 10);
    printf("\nApós inserir 10:\n");
    printTreeStructure(root, 0);
    
    root = insert(root, 20);
    printf("\nApós inserir 20 (rotação dupla será executada):\n");
    printTreeStructure(root, 0);
    
    printf("\nÁrvore final em in-ordem: ");
    printInOrder(root);
    printf("\n");
    
    printf("\nFatores de balanceamento:\n");
    printBalanceFactors(root);
    
    printf("\nAltura da árvore: %d\n", calculateTreeHeight(root));
}

// CASO 2: Rotação dupla - REMOÇÃO
void demonstrateCaso2Remocao() {
    printf("\n==================================================\n");
    printf("CASO 2: ROTAÇÃO DUPLA - EXEMPLO DE REMOÇÃO\n");
    printf("==================================================\n");
    
    Node* root = NULL;
    
    // Construindo árvore que resultará em rotação dupla após remoção
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 10);
    root = insert(root, 35);
    root = insert(root, 45);
    
    printf("Árvore inicial:\n");
    printTreeStructure(root, 0);
    
    printf("\n--- Removendo nós que causam desbalanceamento ---\n");
    printf("Removendo nós 10, 20 (causará rotação dupla):\n\n");
    
    root = deleteNode(root, 10);
    root = deleteNode(root, 20);
    
    printf("\nÁrvore após remoções:\n");
    printTreeStructure(root, 0);
    
    printf("\nÁrvore em in-ordem: ");
    printInOrder(root);
    printf("\n");
    
    printf("\nFatores de balanceamento:\n");
    printBalanceFactors(root);
    
    printf("\nAltura da árvore: %d\n", calculateTreeHeight(root));
}
