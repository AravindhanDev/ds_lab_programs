#include "stdio.h"
#define V 4

void init(int (*)[V]);
void addEdge(int (*)[V], int, int);
void printAdjMatrix(int (*)[V]);

void main() {
	int adjMatrix[V][V];
	init(adjMatrix);
	addEdge(adjMatrix, 0, 1);
	addEdge(adjMatrix, 0, 2);
 	addEdge(adjMatrix, 1, 2);
 	addEdge(adjMatrix, 2, 0);
 	addEdge(adjMatrix, 2, 3);
	printAdjMatrix(adjMatrix);
}

void init(int adjMatrix[][V]) {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			adjMatrix[i][j] = 0;
		}
	}
} 

void addEdge(int adjMatrix[][V], int i, int j) {
	adjMatrix[i][j] = 1;
	adjMatrix[j][i] = 1;
}

void printAdjMatrix(int adjMatrix[][V]) {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (j == 0) {
				printf("| %d ", adjMatrix[i][j]);
			}
			else if (j == V-1) {
				printf("%d |", adjMatrix[i][j]);
			} else {
				printf("%d ", adjMatrix[i][j]);				
			}
		}
		printf("\n");
	}
}