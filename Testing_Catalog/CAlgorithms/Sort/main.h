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
void swap(int* array, int L, int R); //general utility
void selection_sort(int* array, int size);
void merge(int* merged, int* arrayL, int* arrayR, int sizeL, int sizeR); //merge sort utility
void merge_sort(int* array, int size);
int partition(int* array, int low, int high); //quick sort utility
void quick_sort(int* array, int low, int high);

