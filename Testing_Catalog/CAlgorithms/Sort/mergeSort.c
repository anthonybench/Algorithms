//================================================
//================================================
// Merge Sort Algorigthm
// mergeSort.c
//
// Time Complexity: O(n*Log2(n))
//
// Space Complexity: 
//
//================================================
//================================================
#include "main.h"

// utility
void merge(int* merged, int* arrayL, int* arrayR, int sizeL, int sizeR)
{
    // parameters
    int i = 0;
    int j = 0;

    // zipper
    while ((i < sizeL) && (j < sizeR)) {
        if (arrayL[i] <= arrayR[j]) {
            merged[i+j] = arrayL[i];
            ++i;
        } else {
            merged[i+j] = arrayR[j];
            ++j;
        }
    }
    while (i < sizeL) {
        merged[i+j] = arrayL[i];
        ++i;
    }
    while (j < sizeR) {
        merged[i+j] = arrayR[j];
        ++j;
    }

    return;
}

// algorithm
void merge_sort(int* array, int size)
{
    //check for base case, else calculate midpoint
    if (size < 2)
        return;
    int mid = size / 2;

    //create left and right arrays
    int arrayL[mid];
    int arrayR[size - mid];
    for (int i = 0; i < mid; ++i)
        arrayL[i] = array[i];
    int c = 0;
    for (int i = mid; i < size; ++i) {
        arrayR[c] = array[i];
        ++c;
    }

    //keep splitting up the arrays
    merge_sort(arrayL, mid);
    merge_sort(arrayR, size - mid);

    //zipper subarrays to replace array
    merge(array, arrayL, arrayR, mid, size - mid);
    
    return;
}

