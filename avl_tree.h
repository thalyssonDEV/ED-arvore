#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura do no da arvore AVL
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

// Declaracao das funcoes
Node* createNode(int data);
int getHeight(Node* node);
int getBalance(Node* node);
int max(int a, int b);
Node* rightRotate(Node* y);
Node* leftRotate(Node* x);
Node* insert(Node* node, int data);
Node* minValueNode(Node* node);
Node* deleteNode(Node* node, int data);
void printInOrder(Node* root);
void printBalanceFactors(Node* root);
int calculateTreeHeight(Node* root);
void printTreeStructure(Node* root, int space);

// Funcoes para demonstrar casos especificos
void demonstrateCaso1Inclusao(void);
void demonstrateCaso1Remocao(void);
void demonstrateCaso2Inclusao(void);
void demonstrateCaso2Remocao(void);

#endif
