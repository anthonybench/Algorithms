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
    InitRandom();

    // parameters
    int MAX = 20;                       // SWITCH //
    int MAXrange = MAX;                 // SWITCH //
    int array1[MAX], array2[MAX], array3[MAX];
    for (int i = 0; i < MAX; ++i)
        array1[i] = GetRandom(1, MAXrange);
    for (int i = 0; i < MAX; ++i) {
        array2[i] = array1[i];
        array3[i] = array1[i];
    }
    clock_t t;

    // display input
    printf("Input Size: %d\n", MAX);
    printf("[ ");                        // SWITCH (x4) //
    for (int i = 0; i < MAX; ++i)       
        printf("%d ", array1[i]);       
    printf("]\n");
    border('S');
    space(1);
    
    // SELECTION SORT
    t = clock();
    selection_sort(array1, MAX);
    t = clock() - t;
    double timer = (double)t/CLOCKS_PER_SEC;
    printf("Selection Sort Timer: %fs\n", timer);
    printf("[ ");                        // SWITCH (x4) //
    for (int i = 0; i < MAX; ++i)       
        printf("%d ", array1[i]);       
    printf("]\n");
    space(1);
    border('M');

    // MERGE SORT
    t = clock();
    merge_sort(array2, MAX);
    t = clock() - t;
    timer = (double)t/CLOCKS_PER_SEC;
    border('M');
    space(1);
    printf("Merge Sort Timer: %fs\n", timer);
    printf("[ ");                        // SWITCH (x4) //
    for (int i = 0; i < MAX; ++i)       
        printf("%d ", array2[i]);       
    printf("]\n");
    space(1);
    border('M');

    // QUICK SORT
    t = clock();
    quick_sort(array3, 0, MAX - 1);
    t = clock() - t;
    timer = (double)t/CLOCKS_PER_SEC;
    border('M');
    space(1);
    printf("Quick Sort Timer: %fs\n", timer);
    printf("[ ");                        // SWITCH (x4) //
    for (int i = 0; i < MAX; ++i)       
        printf("%d ", array3[i]);       
    printf("]\n");
    space(1);

    // ERROR HANDELING
    // *** Selection Sort is the judge ***
    int errCode = 0;
    for (int i = 0; i < MAX; ++i) {
        if (array1[i] != array2[i]) {
            printf("Error at index: %d for merge_sort!!!\n", i);
            errCode = 1;
        }
        if (array1[i] != array3[i]) {
            printf("Error at index: %d for quick_sort!!!\n", i);
            errCode = 1;
        }
    }
    border('S');
    if (errCode == 0)
        printf("No errors found!\n");

    // close
    border('D');
    space(3);
    return 0;
}

