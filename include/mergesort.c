#include <stdlib.h>
#include "mergesort.h"

void merge(int array[], int r) {

    int q,i,j,k;
    int* tmp;

    tmp = (int*)malloc(sizeof(int)*r);

    if(tmp == NULL) {
        exit(1);
    }

    q = r/2;

    i = 0;
    j = q;
    k = 0;

    while (i < q && j < r) {
        if (array[i] < array[j]) {
            tmp[k] = array[i];
            i=i+1;
        } else {
            tmp[k] = array[j];
            ++j;
        }
        ++k;
    }

    if (i == q) {
        while (j < r) {
            tmp[k] = array[j];
            ++j;
            ++k;
        }
    } else {
        while (i < q) {
            tmp[k] = array[i];
            ++i;
            ++k;
        }
    }

    for (i = 0; i < r; i++) {
        array[i] = tmp[i];
    }
    
    free(tmp);
}

void merge_sort(int array[], int r) {

    int q;
 
    if (r > 1) {
        q = r/2;
        merge_sort(array, q);
        merge_sort(array + q, r-q);
        merge(array,r);
    }
}
