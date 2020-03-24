//================================================
//================================================
// Main Header File
// main.h
//================================================
//================================================
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>


/*****************************
* Tool Declerations
*****************************/
// printers
void space(int n);
void border(char c);

// rng
void InitRandom(void);
unsigned int GetRandom(unsigned int minval, unsigned int maxval);

// algorithms
int min(int a, int b, int c); // utility
int naive_least_change(int n);
int memoized_least_change(int n, int* hashT);
int tabular_least_change(int n, int* hashT);

