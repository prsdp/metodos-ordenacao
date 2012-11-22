#include <stdio.h>
#include "sorting.h"
#include "utils.h"

int main (int argc, char **argv) {

    int array[30];

    // gerando um array com elementos aleatórios
    // através da função random_array
    random_array(array, 30, 300);

    printf("Unsorted: ");
    print_array(array, 30);

    quick_sort(array, 0, 30);

    printf("\nSorted: ");
    print_array(array, 30);

    printf("\n");

    return 0;
}
