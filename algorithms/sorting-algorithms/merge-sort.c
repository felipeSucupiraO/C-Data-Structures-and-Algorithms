#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *alocarVetor(int tamanho) {
    int *vetor = NULL;
    while (vetor == NULL) {
        vetor = (int*)malloc(tamanho * sizeof(int));
    }
    return vetor;
}

void merge(int *vetor, int inicial, int meio, int final) {
    int tamanhoEsquerda = meio - inicial + 1;
    int tamanhoDireita = final - meio;
    
    int *vetorDireita = alocarVetor(tamanhoDireita);
    int *vetorEsquerda = alocarVetor(tamanhoEsquerda);

    for (int i = 0; i < tamanhoEsquerda; i++) {
        vetorEsquerda[i] = vetor[inicial + i];
    }
    for (int i = 0; i < tamanhoDireita; i++) {
        vetorDireita[i] = vetor[meio + 1 + i];
    }

    int i = 0, j = 0, k = inicial;
    while (i < tamanhoEsquerda && j < tamanhoDireita) {
        if (vetorEsquerda[i] <= vetorDireita[j]) {
            vetor[k] = vetorEsquerda[i];
            i++;
        } else if (vetorEsquerda[i] > vetorDireita[j]) {
            vetor[k] = vetorDireita[j];
            j++;
        }
        k++;
    }

    while (i < tamanhoEsquerda) {
        vetor[k] = vetorEsquerda[i];
        k++;
        i++;
    }

    while (j < tamanhoDireita) {
        vetor[k] = vetorDireita[j];
        k++;
        j++;
    }

    free(vetorDireita);
    free(vetorEsquerda);
}

void mergeSort(int *vetor, int inicial, int final, int tamanhoVetor) {
    int meio;

    if (inicial < final) {
        meio = floor((inicial + final)/2.0);
        mergeSort(vetor, inicial, meio, tamanhoVetor);
        mergeSort(vetor, meio + 1, final, tamanhoVetor);
        merge(vetor, inicial, meio, final);
    }
}

int main() {
    return 0;
}