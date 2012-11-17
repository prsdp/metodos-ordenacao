#ifndef _HEAP_SORT_H
#define _HEAP_SORT_H

void heap_swap(int *a, int *b) {

    int t=*a; *a=*b; *b=t;

}

void sift_down(int array[], int start, int end) {

    int root = start;

    while (root*2+1 < end) {
        int child = 2*root + 1;

        if ((child + 1 < end) && array[child] < array[child+1]) {
            child += 1;
        }
        if (array[root] < array[child]) {
            heap_swap(&array[child],  &array[root]);
            root = child;
        }
        else
            return;
    }
}

void heap_sort(int array[], int size) {

    int start, end;

    for (start = (size-2)/2; start >= 0; start--) {
        sift_down(array, start, size);
    }

    for (end = size-1; end > 0; end--) {
        heap_swap(&array[end], &array[0]);
        sift_down(array, 0, end);
    }

}

#endif
