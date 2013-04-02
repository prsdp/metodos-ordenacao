#include <stdio.h>
#include "bubblesort.h"
#include "utils.h"

int main (int argc, char **argv) {

    int array[20];

    // gerando um array com elementos aleatórios
    // através da função random_array
    random_array(array, 20, 100);

    printf("Unsorted: ");
    print_array(array, 20);

    bubble_sort(array, 20);

    printf("\nSorted: ");
    print_array(array, 20);

    printf("\n");

    return 0;
}
