#include <stdlib.h>
#include<stdio.h>
#include <stdbool.h>

// comparison function for qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool canMakeArithmeticProgression(int* arr, int arrSize) {
    if (arrSize <= 2) return true;

    // sort the array
    qsort(arr, arrSize, sizeof(int), compare);

    int diff = arr[1] - arr[0];

    for (int i = 2; i < arrSize; i++) {
        if (arr[i] - arr[i - 1] != diff) {
            return false;
        }
    }

    return true;
}
