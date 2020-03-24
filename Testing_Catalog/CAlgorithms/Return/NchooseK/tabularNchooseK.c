//================================================
//================================================
// Tabular Solution
// tabularNchoosek.c
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
int tabular_NchooseK(int n, int k, int** hashT) {

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            if (j > i)
                hashT[i][j] = 0;
            else if (j == 0 || k == n)
                hashT[i][j] = 1;
            else if (j == 1)
                hashT[i][j] = i;
            else
                hashT[i][j] = hashT[i-1][j-1] + hashT[i-1][j];
        }
    }

    return hashT[n][k];
}
