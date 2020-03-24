//================================================
//================================================
// Tabular Solution
// tabularFibonacci.c
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

int tabular_fibonacci(int n, int* hashT) {
    if (n == 1 || n == 2)
        return 1;
    for (int  k = 3; k <= n; k++)
        hashT[k] = hashT[k - 1] + hashT[k - 2];
    return hashT[n];
}

