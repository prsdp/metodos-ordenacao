#include <stdio.h>
#include "mergesort.h"
#include "utils.h"

int main (int argc, char **argv) {

    int array[10];

    // gerando um array com elementos aleatórios
    // através da função random_array
    random_array(array, 10, 100);

    printf("Unsorted: ");
    print_array(array, 10);

    merge_sort(array, 10);

    printf("\nSorted: ");
    print_array(array, 10);

    printf("\n");

    return 0;
}
