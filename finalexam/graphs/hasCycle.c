
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Stack.h"

bool dfsCycle(Graph g, int v, int u, int *visited);

bool hasCycle(Graph g) {
	// initialise visited array
	int nV = GraphNumVertices(g);
	int visited[nV];
	
	// do the cycle check on all nodes to ensure all connected components are checked
	bool out = false;
	for (int v = 0; v < nV; v++) {
	    // reset visited array each iteration
	    for (int i = 0; i < nV; i++) visited[i] = 0;
	    if (dfsCycle(g, v, v, visited)) {
	        out = true;
	        break;        
	    }
	}
	
	return out;
}

// need 2 vertices to make sure that an edge between 2 vertices is not a cycle
bool dfsCycle(Graph g, int v, int u, int *visited) {
    // initialise
    int nV = GraphNumVertices(g);
	visited[v] = 1;
	// do DFS
    for (int w = 0; w < nV; w++) {
        if (GraphIsAdjacent(g, v, w)) {
           if (!visited[w]) {
                if (dfsCycle(g, w, v, visited)) return true;
           }
           // reject 2-vertex "cycles"
           else if (w != u) return true;
        }
    }
    return false;
}




