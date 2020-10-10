//=======================================
//=======================================
// Isaac A.B. Yep
// CS-350; Introduction to Algorithms
// Kruskal's Algorithm Lab
//=======================================
//=======================================
#include <stdio.h>
#include <math.h>
#include <stdlib.h>   // for qsort
#include <unistd.h>   // for usleep
#define INF  1000000  // infinity


/**********************************
  Adjacency Matrix
***********************************/
// parameters
int N;               // number of vertices
int A[100][100];     // adjacency matrix

// read graph from redirect
int input_graph() {
  int r, c;
  char w[10];

  scanf("%d", &N);
  
  // scan the first row of labels....not used
  for (c = 0; c < N; c++)
    scanf("%s", w);

  for (r = 0; r < N; r++) {
    scanf("%s", w); // label ... not used

    for (c = 0; c < N; c++) {
      scanf("%s", w);
      if (w[0] == '-')
        A[r][c] = -1;
      else
        A[r][c] = atoi(w); // ascii to integer
    }
  }
}


/**********************************
  Print Graph
***********************************/
int print_graph() {
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


/**********************************
  Edge Implementation
***********************************/
typedef struct {
  int vstart;
  int vend;
  int vlen;
} Edge;

Edge elist[100];

int compare (const void *p1, const void *p2) {
  Edge *a, *b;
  a = (Edge *) p1;
  b = (Edge *) p2;
  if ((*a).vlen < (*b).vlen)
    return -1;
  else if ((*a).vlen > (*b).vlen)
    return 1;
  else
    return 0;
}


/**********************************
  Print Edge Array
***********************************/
int  print_edge_list(Edge *elist, int N) {
  int i;

  printf("\n");  

  for (i = 0; i < N; i++)
    printf("<%c, %c, %d> ", 'A'+elist[i].vstart, 'A'+elist[i].vend, elist[i].vlen);

  printf("\n");
}
// useless utility
int print_array(int *x, int n) {
  int i;

  for (i = 0; i < n; i++)
    printf(" %3d", x[i]);
}


/**********************************************
  Quick Sort Algorigthm (for edge list)
  Time Complexity: O(n*Log2(n))
***********************************************/
// utility
void swap (Edge* array, int a, int b) {
  Edge temp = array[a];
  array[a] = array[b];
  array[b] = temp;
  return;
}
// utility
int partition(Edge* array, int low, int high) {
    // parameters
    int pivot = low;
    int i = low;
    int j = high;

    // iterate and swap untill indices cross
    while (i < j) {
        while ((array[i].vlen <= array[pivot].vlen) && (i < high))
            ++i;
        while (array[j].vlen > array[pivot].vlen)
            --j;
        if (i < j)
            swap(array, i, j);
    }
    swap(array, pivot, j);

    return j;
}
// algorithm
void quick_sort(Edge* array, int low, int high) {
    if (low >= high)
        return;

    int pivot = partition(array, low, high);

    quick_sort(array, low, pivot - 1);
    quick_sort(array, pivot + 1, high);

    return;
}


/**********************************
  Solution
***********************************/
int kruskal() {
  //// Edge list set-up ////
  int e,r,c;
  e = 0; // number of edges
  for (r = 0; r < N; r++) {
    for (c = r+1; c < N; c++) {
      if (A[r][c] != -1) {
        elist[e].vstart = r;
        elist[e].vend = c;
        elist[e].vlen = A[r][c];
        e++;
      }
    }
  }
  if (e < N-1) {
    printf("there aren't enough edges to build a spanning tree\n");
    return 0;
  }
  printf("Original Edge List:");
  print_edge_list(elist, e);
  
  //// Sort edge list ////
  quick_sort(elist, 0, e-1);  
  printf("\n\nSorted Edge List:");
  print_edge_list(elist, e);

  //// Parameters ////
  //counters
  int res = 0;
  int Ecount = 0;
  int groupCount = 1;
  //arrays
  Edge elistR[N];
  int netWork[N];
  for (int i = 0; i < N; ++i)
    netWork[i] = -1;

  //// Build MST array ////
  int i = 0;
  while (Ecount < N - 1) {
    Edge current = elist[i];
    if (netWork[current.vstart] == -1 && netWork[current.vend] == -1) {
      netWork[current.vstart] = groupCount;
      netWork[current.vend] = groupCount;
      groupCount++;
      elistR[Ecount] = current;
      res += current.vlen;
      Ecount++;
    }
    else if (netWork[current.vstart] == -1) {
      netWork[current.vstart] = netWork[current.vend];
      elistR[Ecount] = current;
      res += current.vlen;
      Ecount++;
    }
    else if (netWork[current.vend] == -1) {
      netWork[current.vend] = netWork[current.vstart];
      elistR[Ecount] = current;
      res += current.vlen;
      Ecount++;
    }
    else if (netWork[current.vstart] != netWork[current.vend]) {
      for (int j = 0; j < N; ++j)
        if (netWork[j] == netWork[current.vend])
          netWork[j] = netWork[current.vstart];
      elistR[Ecount] = current;
      res += current.vlen;
      Ecount++;
    }
    i++;
  }

  //// Close ////
  printf("\n\nMST Edge List:");
  print_edge_list(elistR, N - 1);
  return res;
}


/**********************************
  Program Entry
***********************************/
/* 
  ./a.out < graphfile.input
                            */
int main() {
  printf("================================================\n");
  printf("================================================\n");

  printf("Adjacency Matrix:\n");
  input_graph();
  print_graph();

  printf("================================================\n");
  printf("================================================\n\n");

  int res = kruskal();

  printf("\n\nMST gross weight:\n%d\n", res);

  printf("\n================================================\n");
  printf("================================================\n");
}
