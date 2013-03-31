#include <stdio.h>
#include "sorting.h"
#include "utils.h"

int main (int argc, char **argv) {

    int array[] = {7, 2, 3, 9, 1, 4, 5, 8, 0, 6};

    printf("Unsorted: ");
    print_array(array, 10);

    merge_sort(array, 0, 10-1);

    printf("\nSorted: ");
    print_array(array, 10);

    printf("\n");

    return 0;
}
