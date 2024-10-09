#include <stdio.h>

void trocarElementos(int *a, int *b) {
    int auxiliar;
    auxiliar = *a;
    *a = *b;
    *b = auxiliar;
}

int particionar(int *vetor, int inicial, int final) {
    int pivo = vetor[final];
    int i = inicial - 1;
    for (int j = inicial; j <= final - 1; j++) {
        if (vetor[j] <= pivo) {
            i++;
            trocarElementos(&vetor[i], &vetor[j]);
        }
    }

    trocarElementos(&vetor[i + 1], &vetor[final]);
    return i + 1;
}

void quickSort(int *vetor, int inicial, int final) {
    int meio;

    if (inicial < final) {
        meio = particionar(vetor, inicial, final);

        quickSort(vetor, inicial, meio - 1);
        quickSort(vetor, meio + 1, final);
    }
}

int main() {
    return 0;
}