#include <stdio.h>
#include "heapsort.h"
#include "utils.h"

int main (int argc, char **argv) {

    int array[50];

    // gerando um array com elementos aleatórios
    // através da função random_array
    random_array(array, 50, 10);

    printf("Unsorted: ");
    print_array(array, 50);

    heap_sort(array, 50);

    printf("\nSorted: ");
    print_array(array, 50);

    printf("\n");

    return 0;
}
