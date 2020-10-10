//================================================
//================================================
// Memoized Solution
// memoizedFibonacci.c
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

int memoized_fibonacci(int n, int* hashT) {
    if (n == 1 || n == 2)
        return 1;

    if (hashT[n] != -1)
        return hashT[n];

    int a = memoized_fibonacci(n - 1, hashT);
    int b = memoized_fibonacci(n - 2, hashT);
    hashT[n] = a + b;

    return hashT[n];
}

