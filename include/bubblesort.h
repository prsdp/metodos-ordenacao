#ifndef _BUBBLE_SORT_H
#define _BUBBLE_SORT_H

void bubble_sort(int array[], int length) {

    int i, j, swap;

    for (i = 0; i < length; i++) {
        for (j = i+1; j < length; j++) {
            if (array[i] > array[j]) {
                swap = array[i];
                array[i] = array[j];
                array[j] = swap;
            }
        }
    }
}

#endif
