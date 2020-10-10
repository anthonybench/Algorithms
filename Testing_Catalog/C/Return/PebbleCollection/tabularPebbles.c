//================================================
//================================================
// Tabular Solution
// tabularPebbles.c
//
// Isaac A.B Yep
//
// Time Complexity:
//
// Space Complexity:
//
//================================================
//================================================
#include "main.h"

// wrapper
int tabular_pebbles(char** grid, int** hashT, int R, int C) {
    return tabular(grid, hashT, R, C, 0, 0);
}

// algorithm
int tabular(char** grid, int** hashT, int R, int C, int r, int c) {

    int a = 0; int b = 0;
    for (int k = 0; k < R*C; ++k) {
        b = k % C;
        if (k % C == 0 && k != 0)
            ++a;

        if (grid[a][b] == 'x') {
            if (a == 0 && b == 0)
                hashT[a][b] = 1;
            else if (a == 0 && b != 0)
                hashT[a][b] = 1 + hashT[a][b-1];
            else if (a != 0 && b == 0)
                hashT[a][b] = 1 + hashT[a-1][b];
            else
                hashT[a][b] = 1 + max(hashT[a][b-1], hashT[a-1][b]);
        }
        else {
            if (a == 0 && b == 0)
                hashT[a][b] = 0;
            else if (a == 0 && b != 0)
                hashT[a][b] = hashT[a][b-1];
            else if (a != 0 && b == 0)
                hashT[a][b] = hashT[a-1][b];
            else
                hashT[a][b] = max(hashT[a][b-1], hashT[a-1][b]);
        }
    }

    return hashT[a][b];
}
