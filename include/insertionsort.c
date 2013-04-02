#include "insertionsort.h"

void insertion_sort(int vet[], int TAM) {

	int i, j, aux;

	for(i = 1; i < TAM; i++){

	j = i;

		while((vet[j] < vet[j-1])&&(j!=0)) {

			aux = vet[j];
			vet[j] = vet[j-1];
			vet[j-1] = aux;
			j--;
		}
	}
}
