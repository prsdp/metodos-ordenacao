#include <stdio.h>
#include "sorting.h"
#include "utils.h"

int main (int argc, char **argv) {

    int array1[20];
    int array2[10];
    int array3[15];

    // gerando arrays com elementos aleatórios
    // através da função random_array_with_range
    random_array_with_range(array1, 20, 10, 80);
    random_array_with_range(array2, 10, 100, 200);
    random_array_with_range(array3, 15, 11, 31);

    printf("*** BUBBLE SORT ***");
    printf("\nUnsorted: ");
    print_array(array1, 20);
    bubble_sort(array1, 20);
    printf("\nSorted: ");
    print_array(array1, 20);
    printf("\n\n");

    printf("*** HEAP SORT ***");
    printf("\nUnsorted: ");
    print_array(array2, 10);
    heap_sort(array2, 10);
    printf("\nSorted: ");
    print_array(array2, 10);
    printf("\n\n");

    printf("*** QUICK SORT ***");
    printf("\nUnsorted: ");
    print_array(array3, 15);
    quick_sort(array3, 0, 15);
    printf("\nSorted: ");
    print_array(array3, 15);
    printf("\n\n");

    return 0;
}
