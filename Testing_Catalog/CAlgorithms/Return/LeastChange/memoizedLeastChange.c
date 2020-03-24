//================================================
//================================================
// Memoized Solution
// memoizedLeastChange.C
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

int memoized_least_change(int n, int* hashT) {
    if (n == 0)
        return 0;
    if (n < 0)
        return 100000;

    int a, b, c, min;
    if (n - 1 < 0)
        a = 100000;
    else if (hashT[n - 1] != -1)
        a = hashT[n - 1];
    else {
        a = memoized_least_change(n - 1, hashT);
        hashT[n - 1] = a;
    }
    if (n - 3 < 0)
        b = 100000;
    else if (hashT[n - 3] != -1)
        b = hashT[n - 3];
    else {
        b = memoized_least_change(n - 3, hashT);
        hashT[n - 3] = b;
    }
    if (n - 4 < 0)
        c = 100000;
    else if (hashT[n - 4] != -1)
        c = hashT[n - 4];
    else {
        c = memoized_least_change(n - 4, hashT);
        hashT[n - 4] = c;
    }
    
    min = c;
    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return 1 + min;
}

