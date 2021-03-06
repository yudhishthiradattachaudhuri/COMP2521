
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

void doDFS(Graph g, int src, int *visited);

void depthFirstSearch(Graph g, int src) {
	int nV = GraphNumVertices(g);
	int visited[nV];
	for (int i = 0; i < nV; i++) visited[i] = 0;
	doDFS(g, src, visited);
}

void doDFS(Graph g, int v, int *visited) {
    int nV = GraphNumVertices(g);
    visited[v] = 1;
    printf("%d ", v);
    for (int w = 0; w < nV; w++) {
        if (visited[w] == 0 && GraphIsAdjacent(g, v, w)) {
            doDFS(g, w, visited);
        }
    }
}   
