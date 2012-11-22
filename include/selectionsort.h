#ifndef _SELECTION_SORT_H
#define _SELECTION_SORT_H

#include <stdio.h>

void selection_sort(int vet[], int TAM){

	int aux, menor, i, j;

	for(i=0;i<(TAM-1);i++){
		menor = i;

		for(j=i+1;j<TAM;j++){
			if(vet[j] < vet[menor]){
				menor = j;
			}
		}
		if(i != menor){
			aux = vet[i];
			vet[i] = vet[menor];
			vet[menor] = aux;
		}
	}
}

#endif
