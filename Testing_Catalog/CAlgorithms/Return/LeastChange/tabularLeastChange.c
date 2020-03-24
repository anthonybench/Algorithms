//================================================
//================================================
// Tabular Solution
// tabularLeastChange.C
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
int tabular_least_change(int n, int* hashT) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (n == 3)
        return 1;
    if (n == 4)
        return 1;

    for (int k = 5; k <= n; k++)
        hashT[k] = min(1 + hashT[k-1], 1 + hashT[k-3], 1 + hashT[k-4]);

    return hashT[n];
}

