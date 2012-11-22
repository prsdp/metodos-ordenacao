#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.h"
#include "utils.h"

void usage() {
    printf("Usage:\n\n");
    printf("--method <type>           tipe de ordenação.\n");
    printf("--array-size <size>       tamanho do vetor a ser gerado.\n");
    printf("--help                    lista as opções do programa.\n\n");
}

int main (int argc, char *argv[]) {

    int size = -1;
    int type;

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
            } else {
                printf("Método inválido!\n");
                printf("Use o -help para ver as opções.\n");
                exit(EXIT_FAILURE);
            }
        }

        if (strcmp(argv[argc], "--array-size") == 0) {
            size = atoi(argv[argc + 1]);
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

    int array[size];
    random_array(array, size, 100);

    switch (type) {
        case 0:
            printf("*** BUBBLE SORT ***");
            printf("\nUnsorted: ");
            print_array(array, size);
            bubble_sort(array, size);
            printf("\nSorted: ");
            print_array(array, size);
            printf("\n");
            break;
        case 1:
            printf("*** INSERTION SORT ***");
            printf("\nUnsorted: ");
            print_array(array, size);
            insertion_sort(array, size);
            printf("\nSorted: ");
            print_array(array, size);
            printf("\n");
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
    }

    return 0;
}
