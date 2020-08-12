
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

int shortestDistance(Graph g, int src, int dest) {
    // default case
    if (src == dest) return 0;
    // initialise
    int nV = GraphNumVertices(g);
    int visited[nV]; 
    for (int i = 0; i < nV; i++) visited[i] = -1;
	Queue q = QueueNew();
	QueueEnqueue(q, src); 
	int v; int count = 0;
	visited[src] = src;
	// do BFS
	while (!QueueIsEmpty(q)) {
	    v = QueueDequeue(q);
	    if (v == dest) break;
	    for (int w = 0; w < nV; w++) {
	        if (visited[w] == -1 && GraphIsAdjacent(g, v, w)) {
	            visited[w] = v;
	            QueueEnqueue(q, w);
	        }
	    }
	}
	QueueFree(q);
	// find path length 
	if (visited[dest] == -1) return -1;
	for (int i = dest; visited[i] != src; i = visited[i]) {
	    count++;
	} 
	return count + 1;
}



