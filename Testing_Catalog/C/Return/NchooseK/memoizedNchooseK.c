//================================================
//================================================
// Memoized Solution
// memoizedNchoosek.c
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
int memoized_NchooseK(int n, int k, int**hashT) {
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
    if (k == 1)
        return n;

    if (hashT[n][k] != -1)
        return hashT[n][k];

    int res = memoized_NchooseK(n-1, k-1, hashT) + memoized_NchooseK(n-1, k, hashT);
    hashT[n][k] = res;
    return res;
}
