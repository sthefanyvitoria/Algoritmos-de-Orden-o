#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
struct Node {
    int data;
    struct Node* next;
};

// Estrutura da Fila
struct Fila {
    struct Node* frente;
    struct Node* tras;
};

// Função para inicializar a fila
void inicializarFila(struct Fila* fila) {
    fila->frente = fila->tras = NULL;
}

// Função para enfileirar um elemento
void enfileirar(struct Fila* fila, int valor) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->data = valor;
    novoNo->next = NULL;

    if (fila->tras == NULL) {
        fila->frente = fila->tras = novoNo;
        return;
    }

    fila->tras->next = novoNo;
    fila->tras = novoNo;
}

// Função para desenfileirar um elemento
int desenfileirar(struct Fila* fila) {
    if (fila->frente == NULL) {
        printf("A fila está vazia.\n");
        return -1; // Valor de erro
    }

    struct Node* temp = fila->frente;
    int valor = temp->data;
    fila->frente = temp->next;

    if (fila->frente == NULL) {
        fila->tras = NULL;
    }

    free(temp);

    return valor;
}

// Função para imprimir os elementos da fila
void imprimirFila(struct Fila* fila) {
    printf("Elementos da Fila:\n");
    while (fila->frente != NULL) {
        printf("%d\n", desenfileirar(fila));
    }
}

int main() {
    // Conjunto de dados
    int conjunto_fila[] = {64, 25, 12, 22, 11, 9};
    int tamanho_conjunto = sizeof(conjunto_fila) / sizeof(conjunto_fila[0]);

    // Criar e inicializar a fila
    struct Fila fila;
    inicializarFila(&fila);

    // Enfileirar os elementos do conjunto
    for (int i = 0; i < tamanho_conjunto; i++) {
        enfileirar(&fila, conjunto_fila[i]);
    }

    // Imprimir os elementos da fila
    imprimirFila(&fila);
