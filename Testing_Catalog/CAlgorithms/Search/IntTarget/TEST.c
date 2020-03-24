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
    int MAX = 40000;
    int target = GetRandom(1, MAX);
    int array[MAX];
    for (int i = 0; i < MAX; ++i)
        array[i] = i+1;
    clock_t t;
    int res;

    // display input
    printf("Target: %d\n", target);
    printf("Input Size: %d\n", MAX);
    border('S');
    space(1);
    
    // LINEAR SEARCH
    t = clock();
    res = linear_search(array, MAX, target);
    t = clock() - t;
    double timer = (double)t/CLOCKS_PER_SEC;
    printf("Linear Search Timer: %fs\n", timer);
    printf("Index Returned: %d\n", res);
    space(1);
    border('M');

    // BINARY SEARCH
    t = clock();
    res = binary_search(array, MAX, target);
    t = clock() - t;
    timer = (double)t/CLOCKS_PER_SEC;
    border('M');
    space(1);
    printf("Binar Search Timer: %fs\n", timer);
    printf("Index Returned: %d\n", res);
    space(1);

    // close
    border('D');
    space(3);
    return 0;
}
