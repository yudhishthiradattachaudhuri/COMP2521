
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

int numWithin(Graph g, int src, int dist) {
    // return value
	int numReachable = 0;
	
	// initialise visited array
	int nV = GraphNumVertices(g);
	int visited[nV];
	for (int i = 0; i < nV; i++) {
	    visited[i] = -1;
	}
	visited[src] = 0; // distance from src to src = 0;
	
	// initialise queue for BFS and other variables
	Queue q = QueueNew();
	QueueEnqueue(q, src);
	int v; // value of vertex leaving queue
	
	// do BFS
	while (!QueueIsEmpty(q)) {
        // initialise at start of each iteration
	    v = QueueDequeue(q);
	    int distToCurr = visited[v];
	    
	    // since BFS will reach closest neighbours first, the first occurrence 
	    // of a path that is too long will occur after all shorter paths from 
	    // the source have already been reached 
	    if (distToCurr > dist) break;
	    
	    // if v passes the distance check another node in range has been found
	    numReachable++;
	    
	    // check all of v's adjacent edges
	    for (int w = 0; w < nV; w++) {
	        if (visited[w] == -1 && GraphIsAdjacent(g, v, w)) {
	            // if adjacent, then it will take 1 more move to reach w
	            visited[w] = visited[v] + 1;
	            QueueEnqueue(q, w);
	        }
	    }
	}
	
	QueueFree(q);
	return numReachable;
}









