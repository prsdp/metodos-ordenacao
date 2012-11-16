#include <stdio.h>
#define TAM 10

int main (int argc, char **argv) {

    int vet[] = {2, 5, 3, 10, 4, 11, 1, 0, 32, 9};
    int aux, i, j;

    printf("UNSORTED VET: ");

    for (i = 0; i < TAM; i++) {
        printf("%d ", vet[i]);
    }

    printf("\n");

    for (i = 0; i < TAM; i++) {
        for (j = i+1; j < TAM; j++) {
            if (vet[i] > vet[j]) {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }

    printf("SORTED VET: ");

    for (i = 0; i < TAM; i++) {
        printf("%d ", vet[i]);
    }

    printf("\n");


    return 0;
}
