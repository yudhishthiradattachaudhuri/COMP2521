
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

void breadthFirstSearch(Graph g, int src) {
    // initialise
	int nV = GraphNumVertices(g);
	int visited[nV]; 
	for (int i = 0; i < nV; i++) visited[i] = -1;
	visited[src] = src;
	Queue q = QueueNew();
	QueueEnqueue(q, src); 
	int v;
	// loop until queue is empty
	while (!QueueIsEmpty(q)) {
	    v = QueueDequeue(q);
	    printf("%d ", v);
	    for (int w = 0; w < nV; w++) {
	        if (visited[w] == -1 && GraphIsAdjacent(g, v, w)) {
	            visited[w] = v;
	            QueueEnqueue(q, w);
	        }
	    }
	}
	QueueFree(q);
}

