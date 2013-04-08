#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "sorting.h"
#include "utils.h"

void usage() {
    printf("\nUsage:\t sorting --method <type> --array-size <size> --range <max-range>\n\n");
    printf("--method <type>           tipo de ordenação.\n");
    printf("--array-size <size>       [opcional] tamanho do vetor a ser gerado, default é 10.000\n");
    printf("--range <max-range>       [opcional] intervalo dos valores aleatórios, default é 65.535\n");
    printf("--help                    lista as opções do programa.\n\n");
    printf("Tipos de métodos válidos:\n");
    printf("bubble, insertion, selection, quick, heap, count e merge.\n");
}

int main (int argc, char *argv[]) {

    int size = 10000;
    uint8_t type = -1;
    uint16_t max_range = 65535;

    if (argc == 1) {
    	usage();
	    exit(EXIT_FAILURE);
    }

    while (argc--) {

        if (strcmp(argv[argc], "--method") == 0) {
            if (strcmp(argv[argc + 1], "bubble") == 0) {
                type = 0;
            } else if (strcmp(argv[argc + 1], "insertion") == 0) {
                type = 1;
            } else if (strcmp(argv[argc + 1], "selection") == 0) {
                type = 2;
            } else if (strcmp(argv[argc + 1], "quick") == 0) {
                type = 3;
            } else if (strcmp(argv[argc + 1], "heap") == 0) {
                type = 4;
            } else if (strcmp(argv[argc + 1], "count") == 0) {
                type = 5;
            } else if (strcmp(argv[argc + 1], "merge") == 0) {
                type = 6;
            } else {
                printf("Método inválido!\n");
                printf("Use o --help para ver as opções.\n");
                exit(EXIT_FAILURE);
            }
        }

        if (strcmp(argv[argc], "--array-size") == 0) {
            size = atoi(argv[argc + 1]);
        }

        if (strcmp(argv[argc], "--range") == 0) {
            max_range = (uint16_t) atoi(argv[argc + 1]);
        }

        if (strcmp(argv[argc], "--help") == 0) {
            usage();
            exit(EXIT_SUCCESS);
        }
    }

    if (size <= 0) {
        printf("O tamanho do vetor é inválido.\n");
        exit(EXIT_FAILURE);
    }

    if (max_range <= 0) {
    	printf("A faixa de valores do vetor é inválida.\n");
        exit(EXIT_FAILURE);
    }

    if (type == -1) {
    	usage();
        exit(EXIT_FAILURE);
    }

    int *array = malloc(sizeof(int) * size);
    random_array(array, size, max_range);

    switch (type) {
        case 0:
            printf("*** BUBBLE SORT ***");
            bubble_sort(array, size);
            printf("\n");
            break;
        case 1:
            printf("*** INSERTION SORT ***");
            insertion_sort(array, size);
            printf("\n");
            break;
        case 2:
	        printf("*** SELECTION SORT ***");
	        selection_sort(array, size);
	        printf("\n");
            break;
        case 3:
	        printf("*** QUICK SORT ***");
	        quick_sort(array, 0, size);
	        printf("\n");
            break;
        case 4:
            printf("*** HEAP SORT ***");
            heap_sort(array, size);
            printf("\n");
            break;
        case 5:
            printf("*** COUNT SORT ***");
            count_sort(array, size, max(array,size));
            printf("\n");
            break;
        case 6:
            printf("*** MERGE SORT ***");
            merge_sort(array, size);
            printf("\n");
            break;
        default:
            break;
    }

    return 0;
}
