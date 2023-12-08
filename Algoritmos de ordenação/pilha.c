#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Pilha {
    struct Node* topo;
};

void inicializarPilha(struct Pilha* pilha) {
    pilha->topo = NULL;
}


void empilhar(struct Pilha* pilha, int valor) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->data = valor;
    novoNo->next = pilha->topo;
    pilha->topo = novoNo;
}


int desempilhar(struct Pilha* pilha) {
    if (pilha->topo == NULL) {
        printf("A pilha está vazia.\n");
        return -1; 
    }

    struct Node* temp = pilha->topo;
    int valor = temp->data;
    pilha->topo = temp->next;
    free(temp);

    return valor;
}

void imprimirPilha(struct Pilha* pilha) {
    printf("Elementos da Pilha:\n");
    while (pilha->topo != NULL) {
        printf("%d\n", desempilhar(pilha));
    }
}

int main() {
   
    int conjunto_pilha[] = {64, 25, 12, 22, 11, 9};
    int tamanho_conjunto = sizeof(conjunto_pilha) / sizeof(conjunto_pilha[0]);

  
    struct Pilha pilha;
    inicializarPilha(&pilha);

    
    for (int i = 0; i < tamanho_conjunto; i++) {
        empilhar(&pilha, conjunto_pilha[i]);
    }

   
    imprimirPilha(&pilha);

    return 0;
}