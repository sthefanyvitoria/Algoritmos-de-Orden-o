#include <stdio.h>


void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n-1; i++) {
       
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}


void imprimirArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d\n ", arr[i]);
    printf("\n");
}

int main() {
    
    int conjunto[] = {64, 25, 12, 22, 11, 9};
    int tamanho = sizeof(conjunto) / sizeof(conjunto[0]);

    selectionSort(conjunto, tamanho);


    printf("Selection Sort Array Ordenado: ");
    imprimirArray(conjunto, tamanho);

    return 0;
}