#include <stdio.h>


void insertionSort(int arr[], int n) {
    int i, chave, j;
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;

    
        while (j >= 0 && arr[j] > chave) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = chave;
    }
}


void imprimirArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d\n", arr[i]);
    printf("\n\n");
}

int main() {
   
    int conjunto[] = {64, 25, 12, 22, 11, 9};
    int tamanho = sizeof(conjunto) / sizeof(conjunto[0]);

 
    insertionSort(conjunto, tamanho);


    printf("Insertion Sort array Ordenado:\n ");
    imprimirArray(conjunto, tamanho);

    return 0;
}