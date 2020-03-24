//================================================
//================================================
// Naive Solution
// naiveFibonacci.c
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

int naive_fibonacci(int n) {
    if (n == 1 || n == 2)
        return 1;
    return naive_fibonacci(n - 1) + naive_fibonacci(n - 2);
}

