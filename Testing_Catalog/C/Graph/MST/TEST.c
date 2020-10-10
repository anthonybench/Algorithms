//================================================
//================================================
// Main Program
// TEST.C
//================================================
//================================================
#include "main.h"

/* 
  ./a.out < Graphs/graphfile.txt
                                 */

int main() {
    // open
    space(3);
    border('D');

    //// parameters ////
    const int ROWS = 100; //switch//
    const int COLS = 100; //switch//
    int res1, res2;
    //number of vertices
    int N;
    //adjacency matrix
    int** A = (int**)malloc(sizeof(int*)*ROWS);
    for (int i = 0; i < ROWS; ++i)
        A[i] = (int*)malloc(sizeof(int)*COLS);
    //edge list
    Edge* elist = (Edge*)malloc(sizeof(Edge)*ROWS);
    N = input_graph(A);

    // display input
    printf("Adjacency Matrix:\n");
    print_graph(N, A);
    printf("Original Edge List:\n");
    print_edge_list(elist, N);
    space(1);

    // PRIM'S
    border('L');
    printf("Prims's Results:\n");
    border('M');
    res1 = prim(N, A, elist);
    printf("\n\nMST gross weight:\n%d\n", res1);
    
    // KRUSKAL'S
    border('L');
    printf("Kruskal's Results:\n");
    border('M');
    res2 = kruskal(N, A, elist);
    printf("\nMST gross weight:\n%d\n", res2);

    // close
    for (int i = 0; i < ROWS; ++i)
        free(A[i]);
    free(A);
    free(elist);
    border('D');
    space(3);
    return 0;
}
