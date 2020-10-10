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

    // display input

    border('S');

    // KRUSKAL'S
    t = clock();

    t = clock() - t;
    double timer = (double)t/CLOCKS_PER_SEC;

    space(1);
    border('M');

    // PRIM'S
    t = clock();

    t = clock() - t;
    timer = (double)t/CLOCKS_PER_SEC;
    space(1);

    // close
    border('D');
    space(3);
    return 0;
}

