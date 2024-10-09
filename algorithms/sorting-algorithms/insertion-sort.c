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
    return 0;
}