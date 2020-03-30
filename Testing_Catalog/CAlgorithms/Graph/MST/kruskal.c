//================================================
//================================================
// Kruskal's Algorithm
// kruskal.c
//
// Time Complexity:
//
// Space Complexity: 
//
//================================================
//================================================
#include "main.h"

int kruskal(int N, int **A, Edge *elist) {
  //// Edge list set-up ////
  int E,r,c;
  E = 0; //number of edges
  for (r = 0; r < N; r++) {
    for (c = r+1; c < N; c++) {
      if (A[r][c] != -1) {
        elist[E].vstart = r;
        elist[E].vend = c;
        elist[E].weight = A[r][c];
        E++;
      }
    }
  }
  if (E < N-1) {
    printf("there aren't enough edges to build a spanning tree\n");
    return 0;
  }
  
  //// Sort edge list ////
  quick_sort(elist, 0, E-1);  

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
      res += current.weight;
      Ecount++;
    }
    else if (netWork[current.vstart] == -1) {
      netWork[current.vstart] = netWork[current.vend];
      elistR[Ecount] = current;
      res += current.weight;
      Ecount++;
    }
    else if (netWork[current.vend] == -1) {
      netWork[current.vend] = netWork[current.vstart];
      elistR[Ecount] = current;
      res += current.weight;
      Ecount++;
    }
    else if (netWork[current.vstart] != netWork[current.vend]) {
      for (int j = 0; j < N; ++j)
        if (netWork[j] == netWork[current.vend])
          netWork[j] = netWork[current.vstart];
      elistR[Ecount] = current;
      res += current.weight;
      Ecount++;
    }
    i++;
  }

  //// Close ////
  printf("MST Edge List:");
  print_edge_list(elistR, N - 1);
  return res;
}
