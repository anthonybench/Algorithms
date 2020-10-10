//================================================
//================================================
// Main Header File
// main.h
//================================================
//================================================
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>


/*****************************
* Graph
*****************************/
typedef struct {
    int vstart;
    int vend;
    int weight;
} Edge;


/*****************************
* Tool Declerations
*****************************/
// printers
void space(int n);
void border(char c);

// rng
void InitRandom();
unsigned int GetRandom(unsigned int minval, unsigned int maxval);

// graph utility
int input_graph(int **A);
int print_graph(int N, int **A);
int print_edge_list(Edge *elist, int N);
void swap(Edge* array, int a, int b); //quicksort utility
int partition(Edge* array, int low, int high); //quicksort utility
void quick_sort(Edge* array, int low, int high);

// algorithms
int prim(int n, int **A, Edge *elist);
int kruskal(int N, int **A, Edge *elist);

