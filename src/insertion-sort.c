#include <stdio.h>
#include "insertionsort.h"
#include "utils.h"

#define TAM 10

int main(int argc, char **argv){

	int vet[TAM] = {6,5,2,9,7,1,92,8,0,11};

	printf("VETOR: ");
    print_array(vet, TAM);

	insertion_sort(vet,TAM);

	printf("\nORDENADO: ");
    print_array(vet, TAM);

    printf("\n");

	return 0;
}

