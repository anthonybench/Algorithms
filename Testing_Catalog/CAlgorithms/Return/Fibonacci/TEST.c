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
    int n = 45; // SWITCH //
    int hashT_1[n + 1], hashT_2[n + 1];
    hashT_1[0] = 0; hashT_2[0] = 0;
    hashT_1[1] = 1; hashT_2[1] = 1;
    hashT_1[2] = 1; hashT_2[2] = 1;
    for (int i = 3; i < n + 1; ++i) {
        hashT_1[i] = -1; hashT_2[i] = -1;
    }

    int res1, res2, res3;

    // display input
    printf("Fibonacci Number to Find: %d\n", n);
    printf("(starting [1, 1, 2, ...])\n");
    border('S');

    // NAIVE SOLUTION
    t = clock();
    res1 = naive_fibonacci(n);
    t = clock() - t;
    double timer = (double)t/CLOCKS_PER_SEC;
    space(1);
    printf("Naive Solution Returned: %d\n", res1);
    printf("Naive Time: %fs\n", timer);
    space(1);
    border('M');

    // MEMOIZED SOLUTION
    t = clock();
    res2 = memoized_fibonacci(n, hashT_1);
    t = clock() - t;
    timer = (double)t/CLOCKS_PER_SEC;
    space(1);
    printf("Memoized Solution Returned: %d\n", res2);
    printf("Memoized Time: %fs\n", timer);
    space(1);
    border('M');

    // TABULAR SOLUTION
    t = clock();
    res3 = tabular_fibonacci(n, hashT_2);
    t = clock() - t;
    timer = (double)t/CLOCKS_PER_SEC;
    space(1);
    printf("Tabular Solution Returned: %d\n", res3);
    printf("Tabular Time: %fs\n", timer);
    space(1);

    // close
    border('D');
    space(3);
    return 0;
}

