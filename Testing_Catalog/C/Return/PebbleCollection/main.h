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
void InitRandom();
unsigned int GetRandom(unsigned int minval, unsigned int maxval);

// algorithms
int max(int a, int b); //general utility
int naive(char** grid, int R, int C, int r, int c);
int naive_pebbles(char** grid, int R, int C); //naive wrapper
int memoized(char** grid, int** hashT, int R, int C, int r, int c);
int memoized_pebbles(char** grid, int** hashT, int R, int C); //memoized wrapper
int tabular(char** grid, int** hashT, int R, int C, int r, int c);
int tabular_pebbles(char** grid, int** hashT, int R, int C); //tabular wrapper

