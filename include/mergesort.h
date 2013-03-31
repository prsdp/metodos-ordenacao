#ifndef _MERGE_SORT_H
#define _MERGE_SORT_H

#include <stdlib.h> 

void merge(int array[], int l, int m, int r){
    
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    
    int *L = (int *)malloc(sizeof(int)*n1);
    int *R = (int *)malloc(sizeof(int)*n2);
 
  
    for(i = 0; i < n1; i++){
        L[i] = array[l + i];
    }
    for(j = 0; j <= n2; j++){
        R[j] = array[m + 1+ j];
	}
    
    i = 0;
    j = 0;
    k = l;
    
    while (i < n1 && j < n2){
        if (L[i] <= R[j]){
            array[k] = L[i];
            i++;
        }else{
            array[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1){
        array[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2){
        array[k] = R[j];
        j++;
        k++;
    }
}
 
void merge_sort(int array[], int l, int r){
    
    if (l < r){
        int m = (l+r)/2;
        
        merge_sort(array, l, m);
        merge_sort(array, m+1, r);
        merge(array, l, m, r);
    }
}

#endif
