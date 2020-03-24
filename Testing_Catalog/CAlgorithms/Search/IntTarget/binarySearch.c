//================================================
//================================================
// Binary Search
// binarySearch.c
//
// Isaac A.B. Yep
//
// Time Complexity:
//
// Space Complexity:
//
//================================================
//================================================
#include "main.h"

// algorithm
int binary_search(int* array, int size, int target)
{
    int low = 0;
    int high = size - 1;
    int mid = (low + high) / 2;

    while (low <= high)
    {
        if (array[mid] == target)
            return mid;
        else if (array[mid] < target)
        {
            low = mid + 1;
            mid = (low + high) / 2;
        }
        else if (array[mid] > target)
        {
            high = mid - 1;
            mid = (low + high) / 2;
        }
    }
    return -1;
}

