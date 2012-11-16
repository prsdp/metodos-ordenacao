#include <stdio.h>

#ifndef _INSERTION_SORT_H
#define _INSERTION_SORT_H

void insertion_sort(int vet[], int TAM){
	
	int aux, i, j;
	
	for(i=0;i<TAM;i++){
		for(j=i+1;j<TAM;j++){
			if(vet[i] > vet[j]){
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			}
		}
	}
	
	printf("INSERTION SORT: ");
	
	for(i=0;i<TAM;i++){
		printf("%d  ",vet[i]);
	}
		
}
#endif
