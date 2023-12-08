#include <stdio.h>


void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
            
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


void imprimirArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {

    int conjunto[] = {64, 25, 12, 22, 11, 9};
    int tamanho = sizeof(conjunto) / sizeof(conjunto[0]);

    bubbleSort(conjunto, tamanho);

    printf("Array Ordenado: ");
    imprimirArray(conjunto, tamanho);

    return 0;
}