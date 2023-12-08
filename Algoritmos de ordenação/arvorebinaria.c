#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da árvore binária
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Função para criar um novo nó
struct TreeNode* criarNo(int valor) {
    struct TreeNode* novoNo = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    novoNo->data = valor;
    novoNo->left = novoNo->right = NULL;
    return novoNo;
}

// Função para inserir um nó na árvore binária
struct TreeNode* inserir(struct TreeNode* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->data) {
        raiz->left = inserir(raiz->left, valor);
    } else if (valor > raiz->data) {
        raiz->right = inserir(raiz->right, valor);
    }

    return raiz;
}

// Função para calcular a profundidade da árvore binária
int profundidade(struct TreeNode* raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int profundidadeEsquerda = profundidade(raiz->left);
    int profundidadeDireita = profundidade(raiz->right);

    return (profundidadeEsquerda > profundidadeDireita ? profundidadeEsquerda : profundidadeDireita) + 1;
}

// Função para encontrar os nós folhas da árvore binária
void nosFolhas(struct TreeNode* raiz) {
    if (raiz == NULL) {
        return;
    }

    if (raiz->left == NULL && raiz->right == NULL) {
        printf("%d ", raiz->data);
    }

    nosFolhas(raiz->left);
    nosFolhas(raiz->right);
}

int main() {
    // Conjunto de dados
    int conjunto_arvore_binaria[] = {200, 450, 123, 52, 133, 321, 422, 523, 36, 64};
    int tamanho_conjunto = sizeof(conjunto_arvore_binaria) / sizeof(conjunto_arvore_binaria[0]);

    // Criar e inicializar a raiz da árvore
    struct TreeNode* raiz = NULL;

    // Inserir elementos na árvore binária
    for (int i = 0; i < tamanho_conjunto; i++) {
        raiz = inserir(raiz, conjunto_arvore_binaria[i]);
    }

    // Respostas às perguntas
    int profundidade_arvore = profundidade(raiz);
    printf("Profundidade da Árvore Binária:\n %d\n", profundidade_arvore);

     printf("\n");


    printf("Nós folhas da Árvore Binária:\n ");
    nosFolhas(raiz);
    printf("\n");

    return 0;
}