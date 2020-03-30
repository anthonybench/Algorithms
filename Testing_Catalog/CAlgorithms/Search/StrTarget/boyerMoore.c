//================================================
//================================================
// BOYER-MOORE SEARCH
// boyerMoore.c
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
int boyer_moore(char* text, char* pattern) {
    //edge case
    if (!text || !pattern)
        return -1;

    //parameters
    const int MAX = 128;
    int n = strlen(text);
    int m = strlen(pattern);

    //number arrays
    int nums[MAX];
    int patternNums[m];
    for (int i = 0; i < m-1; ++i)
        patternNums[i] = m - i - 1;
    patternNums[m-1] = m;
    for (int i = 0; i < MAX; ++i)
        nums[i] = m;
    for (int i = 0; i < m; ++i)
        nums[(int)pattern[i]] = patternNums[i];

    //loop
    int marker = m - 1;
    while (marker < n) {
        int j = 0;
        while (pattern[m - j - 1] == text[marker - j]) {
            if (j == m-1)
                return marker - m + 1;
            ++j;
        }
        if (nums[(int)text[marker]] > (n - 1 - marker))
            marker = (n - 1 - marker);
        else
            marker += nums[(int)text[marker]];
    }

    return -1;
}

