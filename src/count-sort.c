#include <stdio.h>
#include "countsort.h"
#include "utils.h"

#define TAM 8

int main(int argc, char **argv){
	
	int array1[TAM] = {6,5,3,7,1,2,0,4};
	
	printf("VETOR: ");
	print_array(array1,TAM);	
	printf("\nORDENADO: ");
	count_sort(array1,TAM,max(array1,TAM));
    //print_array(array1,TAM);
    printf("\n");
	
	return 0;
}

