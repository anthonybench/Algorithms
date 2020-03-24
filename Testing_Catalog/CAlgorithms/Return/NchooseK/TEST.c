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
    int res1, res2, res3;
    const int N = 32; // SWITCH //
    const int K = 13; // SWITCH //
    const int Ndim = N + 1;
    const int Kdim = K + 1;

    // hash tables
    int** hashT_1 = (int**)malloc(sizeof(int*)*(N+1));
    for (int i = 0; i <= N; ++i)
        hashT_1[i] = (int*)malloc(sizeof(int)*(K+1));
    int** hashT_2 = (int**)malloc(sizeof(int*)*(N+1));
    for (int i = 0; i <= N; ++i)
        hashT_2[i] = (int*)malloc(sizeof(int)*(K+1));
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= K; ++j) {
            hashT_1[i][j] = -1;
            hashT_2[i][j] = -1;
        }
    }

    // display input
    printf("Given %d things, how many ways can you choose %d of them?\n", N, K);
    border('S');

    // NAIVE SOLUTION
    t = clock();
    res1 = naive_NchooseK(N, K);
    t = clock() - t;
    double timer = (double)t/CLOCKS_PER_SEC;
    space(1);
    printf("Naive Solution Returned: %d\n", res1);
    printf("Naive Time: %fs\n", timer);
    space(1);
    border('M');

    // MEMOIZED SOLUTION
    t = clock();
    res2 = memoized_NchooseK(N, K, (int**)hashT_1);
    t = clock() - t;
    timer = (double)t/CLOCKS_PER_SEC;
    space(1);
    printf("Memoized Solution Returned: %d\n", res2);
    printf("Memoized Time: %fs\n", timer);
    space(1);
    border('M');

    // TABULAR SOLUTION
    t = clock();
    res3 = tabular_NchooseK(N, K, (int**)hashT_2);
    t = clock() - t;
    timer = (double)t/CLOCKS_PER_SEC;
    space(1);
    printf("Tabular Solution Returned: %d\n", res3);
    printf("Tabular Time: %fs\n", timer);
    space(1);

    // close
    border('D');
    space(3);
    for (int i = 0; i <= N; i++) {
        free(hashT_1[i]);
        free(hashT_2[i]);
    }
    free(hashT_1); free(hashT_2);
    return 0;
}
