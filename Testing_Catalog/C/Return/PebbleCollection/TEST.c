//================================================
//================================================
// Main Program
// TEST.C
//================================================
//================================================
#include "main.h"

int main() {
    // open
    space(3);
    border('D');

    // parameters
    InitRandom();
    clock_t t;
    const int R = 10; // SWITCH //
    const int C = 10; // SWITCH //

    // hash tables
    int** hashT_1 = (int**)malloc(sizeof(int*)*R);
    for (int i = 0; i < R; ++i)
        hashT_1[i] = (int*)malloc(sizeof(int)*C);
    int** hashT_2 = (int**)malloc(sizeof(int*)*R);
    for (int i = 0; i < R; ++i)
        hashT_2[i] = (int*)malloc(sizeof(int)*C);
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            hashT_1[i][j] = -1;
            hashT_2[i][j] = -1;
        }
    }

    // pebble grid
    char** grid = (char**)malloc(sizeof(char*)*R);
    for (int i = 0; i < R; ++i)
        grid[i] = (char*)malloc(sizeof(char)*C);
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            grid[i][j] = 'O';
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            if (GetRandom(0,2) == 1)
                grid[i][j] = 'x';
    int res1, res2, res3;

    // display input
    for (int i = 0; i < R; ++i) { // SWITCH (X4) //
        for (int j = 0; j < C; ++j)
            printf("%c ", grid[i][j]);
        printf("\n");
    }
    border('S');

    // NAIVE SOLUTION
    t = clock();
    res1 = naive_pebbles((char**)grid, R, C);
    t = clock() - t;
    double timer = (double)t/CLOCKS_PER_SEC;
    space(1);
    printf("Naive Solution Returned: %d\n", res1);
    printf("Naive Time: %fs\n", timer);
    space(1);
    border('M');

    // MEMOIZED SOLUTION
    t = clock();
    res2 = memoized_pebbles((char**)grid, (int**)hashT_1, R, C);
    t = clock() - t;
    timer = (double)t/CLOCKS_PER_SEC;
    space(1);
    printf("Memoized Solution Returned: %d\n", res2);
    printf("Memoized Time: %fs\n", timer);
    space(1);
    border('M');

    // TABULAR SOLUTION
    t = clock();
    res3 = tabular_pebbles((char**)grid, (int**)hashT_2, R, C);
    t = clock() - t;
    timer = (double)t/CLOCKS_PER_SEC;
    space(1);
    printf("Tabular Solution Returned: %d\n", res3);
    printf("Tabular Time: %fs\n", timer);
    space(1);

    // close
    border('D');
    space(3);
    for (int i = 0; i < R; ++i) {
        free(hashT_1[i]);
        free(hashT_2[i]);
        free(grid[i]);
    }
    free(hashT_1); free(hashT_2);
    free(grid);
    return 0;
}

