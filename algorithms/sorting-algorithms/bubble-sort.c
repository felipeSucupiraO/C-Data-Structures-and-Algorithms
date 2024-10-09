#include <stdio.h>

void trocarElementos(int *a, int *b) {
    int auxiliar;
    auxiliar = *a;
    *a = *b;
    *b = auxiliar;
}

void bubbleSort(int *vetor, int tamanhoVetor) {
    int i, j, auxiliar;

    for (i = tamanhoVetor - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                trocarElementos(&vetor[j], &vetor[j + 1]);
            }
        }
    }
}

int main() {
    return 0;
}