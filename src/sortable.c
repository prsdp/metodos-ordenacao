#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>
#include <math.h>
#include "sorting.h"
#include "utils.h"

void usage() {
    printf("\nUsage:\t sorting --method <type> --array-size <size> --range <max-range>\n\n");
    printf("--method <type>           tipo de ordenação.\n");
    printf("--array-size <size>       [opcional] tamanho do vetor a ser gerado, default é 10.000\n");
    printf("--range <max-range>       [opcional] intervalo dos valores aleatórios, default é 65.535\n");
    printf("--quantity <value>        [opcional] quantidade de vetores a serem criados, default é 1\n");
    printf("--print-array             [opcional] imprime o vetor ordenado ao final da operação, apenas se --quantity for igual a 1\n");
    printf("--help                    lista as opções do programa.\n\n");
    printf("Tipos de métodos válidos:\n");
    printf("bubble, insertion, selection, quick, heap, count e merge.\n");
}

void alakazam(int quantity, uint8_t type, int size, uint16_t max_range, uint8_t print_flag) {
    int i;
    float sum;
    time_t start, end;
    time(&start);

    switch (type) {
        case 0:
            printf("*** BUBBLE SORT ***\n");
            for (i = 1; i <= quantity; i++) {
                int *array = malloc(sizeof(int) * size);
                random_array(array, size, max_range);
                bubble_sort(array, size);
                if (quantity == 1 && print_flag) {
                    print_array(array, size);
                }
                sum += leakage(array, size);
                free(array);
            }
            break;
        case 1:
            printf("*** INSERTION SORT ***\n");
            for (i = 1; i <= quantity; i++) {
                int *array = malloc(sizeof(int) * size);
                random_array(array, size, max_range);
                insertion_sort(array, size);
                if (quantity == 1 && print_flag) {
                    print_array(array, size);
                }
                sum += leakage(array, size);
                free(array);
            }
            break;
        case 2:
	        printf("*** SELECTION SORT ***\n");
            for (i = 1; i <= quantity; i++) {
                int *array = malloc(sizeof(int) * size);
                random_array(array, size, max_range);
                selection_sort(array, size);
                if (quantity == 1 && print_flag) {
                    print_array(array, size);
                }
                sum += leakage(array, size);
                free(array);
            }
            break;
        case 3:
	        printf("*** QUICK SORT ***\n");
            for (i = 1; i <= quantity; i++) {
                int *array = malloc(sizeof(int) * size);
                random_array(array, size, max_range);
                quick_sort(array, 0, size);
                if (quantity == 1 && print_flag) {
                    print_array(array, size);
                }
                sum += leakage(array, size);
                free(array);
            }
            break;
        case 4:
            printf("*** HEAP SORT ***\n");
            for (i = 1; i <= quantity; i++) {
                int *array = malloc(sizeof(int) * size);
                random_array(array, size, max_range);
                heap_sort(array, size);
                if (quantity == 1 && print_flag) {
                    print_array(array, size);
                }
                sum += leakage(array, size);
                free(array);
            }
            break;
        case 5:
            printf("*** COUNT SORT ***\n");
            for (i = 1; i <= quantity; i++) {
                int *array = malloc(sizeof(int) * size);
                random_array(array, size, max_range);
                count_sort(array, size, max(array, size));
                if (quantity == 1 && print_flag) {
                    print_array(array, size);
                }
                sum += leakage(array, size);
                free(array);
            }
            break;
        case 6:
            printf("*** MERGE SORT ***\n");
            for (i = 1; i <= quantity; i++) {
                int *array = malloc(sizeof(int) * size);
                random_array(array, size, max_range);
                merge_sort(array, size);
                if (quantity == 1 && print_flag) {
                    print_array(array, size);
                }
                sum += leakage(array, size);
                free(array);
            }
            break;
        default:
            break;
    }

    time(&end);
    create_file();
    write_file(size, difftime(end, start), sum);

}

int main (int argc, char *argv[]) {

    int size = 10000;
    int quantity_flag = 1;
    uint8_t print_flag = 0;
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

        if (strcmp(argv[argc], "--quantity") == 0) {
            quantity_flag = atoi(argv[argc + 1]);
        }

        if (strcmp(argv[argc], "--print-array") == 0) {
            print_flag = 1;
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

    alakazam(quantity_flag, type, size, max_range, print_flag);
    printf("\n");

    return 0;
}
