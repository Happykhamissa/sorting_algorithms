#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bitonicMerge(int *array, int low, int count, int dir) {
    if (count > 1) {
        int k = count / 2;
        int i;
        
        for (i = low; i < low + k; ++i) {
            if ((array[i] > array[i + k]) == dir) {
                swap(&array[i], &array[i + k]);
                printf("Swap: %d %d\n", array[i], array[i + k]);
            }
        }
        bitonicMerge(array, low, k, dir);
        bitonicMerge(array, low + k, k, dir);
    }
}

void bitonicSort(int *array, int low, int count, int dir) {
    if (count > 1) {
        int k = count / 2;
        bitonicSort(array, low, k, 1);
        bitonicSort(array, low + k, k, 0);
        bitonicMerge(array, low, count, dir);
    }
}

void bitonic_sort(int *array, size_t size) {
    bitonicSort(array, 0, size, 1);
}
