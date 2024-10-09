#include <stdio.h>
#include <stdlib.h>

int *alocarVetor(int tamanho) {
    int *vetor = NULL;
    while (vetor == NULL) {
        vetor = (int*)malloc(tamanho * sizeof(int));
    }
    return vetor;
}

void countingSort(int *vetorInput, int tamanhoVetor, int maiorNum) {
    int *vetorContagem = alocarVetor(maiorNum + 1);
    for (int i = 0; i <= maiorNum; i++) {
        vetorContagem[i] = 0;
    }

    for (int i = 0; i < tamanhoVetor; i++) {
        vetorContagem[vetorInput[i]]++;
    }

    for (int i = 1; i <= maiorNum; i++) {
        vetorContagem[i] += vetorContagem[i - 1]; 
    }

    int *vetorResultado = alocarVetor(tamanhoVetor);
    for (int i = tamanhoVetor - 1; i >= 0; i--) {
        vetorResultado[vetorContagem[vetorInput[i]] - 1] = vetorInput[i];
        vetorContagem[vetorInput[i]]--;
    }

    for (int i = 0; i < tamanhoVetor; i++) {
        vetorInput[i] = vetorResultado[i];
    }

    free(vetorContagem);
    free(vetorResultado);
}

int main() {
    int vetor[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    countingSort(vetor, 10, 9);
    for (int i = 0; i < 10; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}