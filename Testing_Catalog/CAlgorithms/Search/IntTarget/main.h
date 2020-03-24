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
int linear_search(int* array, int size, int target);
int binary_search(int* array, int size, int target);

