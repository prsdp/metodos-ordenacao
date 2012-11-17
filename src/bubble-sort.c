#include <stdio.h>
#include "sorting.h"

int main (int argc, char **argv) {

    int i;
    int array[] = {7, 2, 3, 9, 1, 4, 5, 8, 0, 6};

    printf("Unsorted: ");

    for (i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }

    bubble_sort(array, 10);

    printf("\nSorted: ");

    for (i = 0; i < 10; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}
