//================================================
//================================================
// Memoized Solution
// memoizedPebbles.c
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
int memoized_pebbles(char** grid, int** hashT, int R, int C) {
    return memoized(grid, hashT, R, C, 0, 0);
}

// algorithm
int memoized(char** grid, int** hashT, int R, int C, int r, int c) {
    if (r >= R || c >= C)
        return 0;

    int down, right;
    
    if (r < R-1) {
        if (hashT[r+1][c] != -1)
            down = hashT[r+1][c];
        else {
            down = memoized(grid, hashT, R, C, r+1, c);
            hashT[r+1][c] = down;
        }
    }
    else
        down = 0;
    
    if (c < C-1) {
        if (hashT[r][c+1] != -1)
            right = hashT[r][c+1];
        else {
            right = memoized(grid, hashT, R, C, r, c+1);
            hashT[r][c+1] = right;
        }
    }
    else
        right = 0;

    if (grid[r][c] == 'x')
        return max(1 + down, 1 + right);
    return max(down, right);
}
