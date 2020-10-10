//================================================
//================================================
// Naive Solution
// naiveNchoosek.c
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
int naive_NchooseK(int n, int k) {
    if (k > n)
        return 0;
    if (k == n || k == 0)
        return 1;
    if (k == 1)
        return n;

    return naive_NchooseK(n-1, k-1) + naive_NchooseK(n-1, k);
}
