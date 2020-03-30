//================================================
//================================================
// Variable/Printing Tools
// tools.c
//================================================
//================================================
#include "main.h"


/**********************************
  Graph Tools
***********************************/
// read adjacency matrix from file redirect
int input_graph(int **A) {
  int N, r, c;
  char w[10];

  scanf("%d", &N);
  
  //scan unused
  for (c = 0; c < N; c++)
    scanf("%s", w);
  //scan unused
  for (r = 0; r < N; r++) {
    scanf("%s", w);

    for (c = 0; c < N; c++) {
      scanf("%s", w);
      if (w[0] == '-')
        A[r][c] = -1;
      else
        A[r][c] = atoi(w);
    }
  }

  return N;
}

// print graph
int print_graph(int N, int **A) {
  int r, c;

  printf("\n%d\n\n", N);
  
  printf("  ");
  for (c = 0; c < N; c++)
    printf("   %c", c+'A');
  printf("\n");  
  
  for (r = 0; r < N; r++) {
    printf("%c  ", r+'A');
    for (c = 0; c < N; c++) {
      if (A[r][c] == -1)
        printf("  - ");
      else
        printf("%3d ", A[r][c]);
    }
    printf("\n");
  }
  printf("\n");  
}

// print edge list
int print_edge_list(Edge *elist, int N) {

  printf("\n");  
  for (int i = 0; i < N; i++)
    printf("<%c, %c, %d> ", 'A'+elist[i].vstart, 'A'+elist[i].vend, elist[i].weight);

  printf("\n");
}

//// Edge List Quick Sort ////
//utility
void swap (Edge* array, int a, int b) {
  Edge temp = array[a];
  array[a] = array[b];
  array[b] = temp;
  return;
}
//utility
int partition(Edge* array, int low, int high) {
    int pivot = low;
    int i = low;
    int j = high;

    while (i < j) {
        while ((array[i].weight <= array[pivot].weight) && (i < high))
            ++i;
        while (array[j].weight > array[pivot].weight)
            --j;
        if (i < j)
            swap(array, i, j);
    }
    swap(array, pivot, j);

    return j;
}
//algorithm
void quick_sort(Edge* array, int low, int high) {
    if (low >= high)
        return;

    int pivot = partition(array, low, high);

    quick_sort(array, low, pivot - 1);
    quick_sort(array, pivot + 1, high);

    return;
}


/**********************************
  General Printing
***********************************/
// prints white space
void space(int n) {
    for (int i = 0; i < n; ++i)
        printf("\n");
}

// prints border
void border(char c) {
    if (tolower(c) == 's')
        printf("=========\n");
    else if (tolower(c) == 'm')
        printf("===================\n");
    else if (tolower(c) == 'l')
        printf("==================================================\n");
    else if (tolower(c) == 'd')
    {
        printf("==================================================\n");
        printf("==================================================\n");
    }
}


/**********************************
  RNG Functions
***********************************/
// seed
void InitRandom() {
	time_t timestr;

#ifdef _DEBUG
	timestr = 0;
#else
	time(&timestr);
#endif
	srand((unsigned int)timestr);

    return;
}

// generator
unsigned int GetRandom(unsigned int minval, unsigned int maxval) {
	char temp[sizeof(int)];
	int* val;
	int i;
	

	val = (int*)temp;

	for (i = 0; i < sizeof(unsigned int); i++)
	{
		temp[i] = rand() & 0xFF;
	}

	*val = ((*val) % (maxval - minval + 1)) + minval;
	assert((*val <= maxval) && (*val >= minval));
	return *val;
}
