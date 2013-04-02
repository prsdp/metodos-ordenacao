#include "quicksort.h"

void swap(int *a, int *b) {

    int t=*a; *a=*b; *b=t;

}

void quick_sort(int array[], int left, int right) {

    if (right > left + 1) {
        int pivot = array[left];
        int i = left + 1;
        int j = right;

        while (i < j) {
            if (array[i] <= pivot)
                i++;
            else
                swap(&array[i], &array[--j]);
        }

        swap(&array[--i], &array[left]);
        quick_sort(array, left, i);
        quick_sort(array, j, right);
    }
}
