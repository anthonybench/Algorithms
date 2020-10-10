//================================================
//================================================
// Naive Solution
// naiveLeastChange.C
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

// utility
int min(int a, int b, int c) {
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;
    else
        return c;
}

// solution
int naive_least_change(int n) {
    if (n == 0)
        return 0;
    if (n < 0)
        return 100000;
    
    return 1 + min(naive_least_change(n - 4), naive_least_change(n - 3), naive_least_change(n - 1));
}

