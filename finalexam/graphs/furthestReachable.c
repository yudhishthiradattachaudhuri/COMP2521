
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

int furthestReachable(Graph g, int src) {
    // if isolated node, exit early
    int nV = GraphNumVertices(g);
    bool isolated = true;
    for (int i = 0; i < nV; i++) {
        if (GraphIsAdjacent(g, src, i)) {
            isolated = false;
            break;
        }
    }
    if (isolated) return src;
    
	// initialise visited array
	int visited[nV];
	for (int i = 0; i < nV; i++) {
	    visited[i] = -1;
	}
	visited[src] = 0; // distance from src to src = 0;
	
	// initialise queue for BFS and other variables
	Queue q = QueueNew();
	QueueEnqueue(q, src);
	int v; // value of vertex leaving queue
	
	// do BFS, fill visited array with distances from source
	while (!QueueIsEmpty(q)) {
        // initialise at start of each iteration
	    v = QueueDequeue(q);
	    // check all of v's adjacent edges
	    for (int w = 0; w < nV; w++) {
	        if (visited[w] == -1 && GraphIsAdjacent(g, v, w)) {
	            // if adjacent, then it will take 1 more move to reach w
	            visited[w] = visited[v] + 1;
	            QueueEnqueue(q, w);
	        }
	    }
	}
	
	// find the max distance value
	int max = -1;
	for (int i = 0; i < nV; i++) {
	    if (visited[i] > max) max = visited[i];
	}
	
	// find the first occurence of the max distance, prioritising highest index
	// vertex first
	int out = 0;
	for (int i = nV - 1; i >= 0; i--) {
	    if (visited[i] == max) {
	        out = i;
	        break;
	    }
	}
	
	QueueFree(q);
	return out;
}

