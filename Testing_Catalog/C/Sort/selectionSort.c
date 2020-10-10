//================================================
//================================================
// Slection Sort Algorigthm
// selectionSort.c
//
// Isaac A.B. Yep
//
// Time Complexity: O(n*Log2(n))
//
// Space Compleixty:
//
//================================================
//================================================
#include "main.h"

// utility
void swap(int* array, int L, int R) {
    int temp = array[L];
    array[L] = array[R];
    array[R] = temp;

    return;
}

// algorithm
void selection_sort(int* array, int size) {
    //parameters
    int sortedInd = 0;
    int smallestInd = 0;

    //find smallest
    while (sortedInd < size - 1) {
        smallestInd = sortedInd;

        for (int i = sortedInd; i < size; ++i)
            if (array[i] < array[smallestInd])
                smallestInd = i;

        swap(array, sortedInd, smallestInd);
        sortedInd++; 
    }

    return;
}

