//================================================
//================================================
// Brute Force Search
// bruteForce.c
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
int brute_force(char* text, char* pattern)
{
    int marker = 0;
    int n = strlen(text);
    int m = strlen(pattern);

    while (marker + m <= n) {
        for (int i = 0; i < m; ++i) {
            if (text[i+marker] != pattern[i])
                break;
            if ((text[i+marker] == pattern[i]) && (i == m-1))
                return marker;
        }
        ++marker;
    }
    return -1;
}

