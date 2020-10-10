//================================================
//================================================
// Naive Solution
// naivePebbles.c
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

// utility
int max(int a, int b) {
    if (a >= b)
        return a;
    return b;
}

// wrapper
int naive_pebbles(char** grid, int R, int C) {
    return naive(grid, R, C, 0, 0);
}

// algorithm
int naive(char** grid, int R, int C, int r, int c) {
    if (r >= R || c >= C)
        return 0;
    
    int down = naive(grid, R, C, r+1, c);
    int right = naive(grid, R, C, r, c+1);

    if (grid[r][c] == 'x')
        return max(1 + down, 1 + right);

    return max(down, right);
}
