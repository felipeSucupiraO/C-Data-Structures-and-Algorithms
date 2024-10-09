#include <stdio.h>

void trocarElementos(int *a, int *b) {
    int auxiliar;
    auxiliar = *a;
    *a = *b;
    *b = auxiliar;
}

void selectionSort(int *vetor, int tamanhoVetor) {
    int i, j, min;
    for (i = 0; i < tamanhoVetor; i++) {
        min = i;
        for (j = i; j < tamanhoVetor; j++) {
            if (vetor[j] < vetor[min]) {
                min = j;
            }
        }

        if (vetor[i] != vetor[min]) {
            trocarElementos(&vetor[i], &vetor[min]);
        }
    }
}

int main() {
    return 0;
}