#include <stdio.h>

void insertionSort(int *vetor, int tamanhoVetor) {
    int i, j = 1;
    int auxiliar;

    while (j < tamanhoVetor) {
        i = j - 1;
        auxiliar = vetor[j];
        while (i >= 0 && vetor[i] > auxiliar) {
            vetor[i + 1] = vetor[i];
            i--;
        }
        vetor[i + 1] = auxiliar;
        j++;
    }
}

int main() {
    int vetor[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    insertionSort(vetor, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}