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
    int res1, res2, res3;
    const int MAX = 2000000; // SWITCH //
    const int LEN = 3; // SWITCH //
    const int IND = MAX - LEN; // SWITCH //
    char text[MAX+1], pattern[LEN+1];
    for (int i = 0; i < MAX; ++i)
        text[i] = (char)GetRandom(33, 126);
    text[MAX] = '\0';
    int Counter = 0;
    for (int i = IND; i < IND+LEN; ++i) {
        pattern[Counter] = text[IND+Counter];
        ++Counter;
    }
    pattern[LEN] = '\0';

    // display input
    /*printf("Text: "); // SWITCH (x3) //
    for (int i = 0; i < MAX; ++i)
        printf("%c", text[i]);*/
    printf("\nText Size: %d\n\n", MAX);
    /*printf("Pattern: ");
    for (int i = 0; i < LEN; ++i)
        printf("%c", pattern[i]);*/
    printf("\nPattern Size: %d\n", LEN);
    border('S');

    // BRUTE FORCE SEARCH
    t = clock();
    res1 = brute_force(text, pattern);
    t = clock() - t;
    double timer = (double)t/CLOCKS_PER_SEC;
    space(1);
    printf("Brute Force Timer: %fs\n", timer);
    if (res1 == -1)
        printf("Pattern not found\n");
    else
        printf("Index Returned: %d\n", res1);
    space(1);
    border('M');

    // RABIN-KARP SEARCH
    t = clock();
    res2 = rabin_karp(text, pattern);
    t = clock() - t;
    timer = (double)t/CLOCKS_PER_SEC;
    space(1);
    printf("Rabin-Karp Timer: %fs\n", timer);
    if (res2 == -1)
        printf("Pattern not found\n");
    else
        printf("Index Returned: %d\n", res2);
    space(1);
    border('M');

    // BOYER-MOORE SEARCH
    t = clock();
    res3 = boyer_moore(text, pattern);
    t = clock() - t;
    timer = (double)t/CLOCKS_PER_SEC;
    space(1);
    printf("Smart Search Timer: %fs\n", timer);
    if (res3 == -1)
        printf("Pattern not found\n");
    else
        printf("Index Returned: %d\n", res3);
    space(1);

    // close
    border('D');
    space(3);
    return 0;
}

