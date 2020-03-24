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
int brute_force(char* text, char* pattern);
int stringHash(char* input, int start, int end, int modVal); // utility
int rabin_karp(char* text, char* pattern);
int boyer_moore(char* text, char* pattern);

