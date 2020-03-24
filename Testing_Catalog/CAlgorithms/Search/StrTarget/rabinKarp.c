//================================================
//================================================
// Rabin-Karp
// rabinKarp.c
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
int stringHash(char* input, int start, int end, int modVal)
{
    int res = 0;

    for (int i = start; i < end; ++i)
        res += (int)input[i];

    return (res % modVal);
}

// algorithm
int rabin_karp(char* text, char* pattern)
{
    //parameters
    int modVal = 181; // SWITCH //
    int n = strlen(text);
    int m = strlen(pattern);
    int marker = m - 1;
    int patternVal = stringHash(pattern, 0, m, modVal);
    int textVal = stringHash(text, 0, m, modVal);
    //nudge pattern
    while (marker <= n - 1) {
        //if hash's equal
        if (patternVal == textVal) {
            for (int i = 0; i < m; ++i) {
                if (pattern[i] != (text[marker - m + i + 1]))
                    break;
                if ((i == m-1) && (pattern[i] == text[marker - m + i + 1]))
                    return marker - m + 1;
            }
        }
        int left = (int)text[marker - m + 1] % modVal;
        int right = (int)text[marker + 1] % modVal;
        textVal = (textVal - left + right) % modVal;
        ++marker;
        }
    return -1;
}

