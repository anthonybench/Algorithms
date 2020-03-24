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
void swap(int* array, int L, int R); // utility
void selection_sort(int* array, int size);
void merge(int* merged, int* arrayL, int* arrayR, int sizeL, int sizeR); // utility
void merge_sort(int* array, int size);
int partition(int* array, int low, int high);
void quick_sort(int* array, int low, int high);
void heapify(int* array); // utility
int heap_sort(int* array, int size);

