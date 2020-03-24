//================================================
//================================================
// Main Program
// TEST.C
//================================================
//================================================
#include "main.h"

int main()
{
    // open
    space(3);
    border('D');

    // parameters
    InitRandom();
    clock_t t;
    const int N = 33; // SWITCH //
    int hashT_1[N + 1], hashT_2[N + 1];
    hashT_1[0] = 0; hashT_2[0] = 0;
    hashT_2[1] = 1; hashT_2[2] = 2; hashT_2[3] = 1; hashT_2[4] = 1;
    for (int i = 1; i < N + 1; ++i) {
        hashT_1[i] = -1;
        if (i > 4)
            hashT_2[i] = -1;
    }
    int res1, res2, res3;

    // display input
    printf("Base-unit-currency Input: %d\n", N);
    printf("Currency Units: 1-coin | 3-coin | 4-coin\n");
    border('S');

    // NAIVE SOLUTION
    t = clock();
    res1 = naive_least_change(N);
    t = clock() - t;
    double timer = (double)t/CLOCKS_PER_SEC;
    space(1);
    printf("Naive Solution Returned: %d\n", res1);
    printf("Naive Time: %f\n", timer);
    space(1);
    border('M');

    // MEMOIZED SOLUTION
    t = clock();
    res2 = memoized_least_change(N, hashT_1);
    t = clock() - t;
    timer = (double)t/CLOCKS_PER_SEC;
    space(1);
    printf("Memoized Solution Returned: %d\n", res2);
    printf("Memoized Time: %f\n", timer);
    space(1);
    border('M');

    // TABULAR SOLUTION
    t = clock();
    res3 = tabular_least_change(N, hashT_2);
    t = clock() - t;
    timer = (double)t/CLOCKS_PER_SEC;
    space(1);
    printf("Tabular Solution Returned: %d\n", res3);
    printf("Tabular Time: %f\n", timer);
    space(1);

    // close
    border('D');
    space(3);
    return 0;
}

