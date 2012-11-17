#include <stdio.h>
#include "insertionsort.h"

#define TAM 10

int main(int argc, char **argv){
	
	int vet[TAM] = {6,5,2,9,7,1,92,8,0,11};
	int i;
	
	printf("VETOR: ");
	
	for(i=0;i<TAM;i++){
		printf("%d  ",vet[i]);
	}
	
	insertion_sort(vet,TAM);
	
	printf("\nORDENADO: ");

    for (i = 0; i < TAM; i++) {
        printf("%d  ", vet[i]);
    }

    printf("\n");
	
	return 0;
}

