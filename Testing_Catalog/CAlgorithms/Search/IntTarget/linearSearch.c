//================================================
//================================================
// Linear Search
// linearSearch.c
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
int linear_search(int* array, int size, int target)
{
    for (int i = 0; i < size; ++i)
        if (array[i] == target)
            return i;
    return -1;
}

