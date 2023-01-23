#include "stdio.h"
#include "stdlib.h"
#define SIZE 40

typedef struct Queue {
	int items[SIZE];
	int front;
	int rear;
} Queue;

typedef struct Node {
	int vertex;
	struct Node* next;
} Node;

typedef struct Graph { 
	int numVertices; 
	struct Node** adjLists; 
	int* visited;
} Graph;

Queue* createQueue();
void enqueue(Queue*, int);
int dequeue(Queue*);
int isEmpty(Queue*);
void printQueue(Queue*);
void bfs(Graph*, int);
Node* createNewNode(int);
Graph* createGraph(int);
void addEdge(Graph*, int, int);

void main() {
	Graph* graph = createGraph(5);
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 4);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 4);
	addEdge(graph, 3, 4);
	bfs(graph, 0);
}

void bfs(Graph* graph, int startVertex) {
	Queue* q = createQueue();

	graph->visited[startVertex] = 1;
	enqueue(q, startVertex);

	while (!isEmpty(q)) {
		printQueue(q);
		int currentVertex = dequeue(q);
		printf("Visited: %d\n", currentVertex);

		Node* temp = graph->adjLists[currentVertex];

		while (temp) {
			int adjVertex = temp->vertex;

			if (graph->visited[adjVertex] == 0) {
				graph->visited[adjVertex] = 1;
				enqueue(q, adjVertex);
			}
			temp = temp->next;
		}
	} 
}

void addEdge(Graph* graph, int src, int dest) {
	Node* newNode = createNewNode(dest);
	newNode->next = graph->adjLists[src];
	graph->adjLists[src] = newNode;

	newNode = createNewNode(src);
	newNode->next = graph->adjLists[dest];
	graph->adjLists[dest] = newNode;
}

Graph* createGraph(int vertices) {
	Graph* graph = malloc(sizeof(Graph));
	graph->numVertices = vertices;
	graph->adjLists = malloc(vertices * sizeof(Node*));
	graph->visited = malloc(vertices * sizeof(int));

	for (int i = 0; i < vertices; i++) {
		graph->adjLists[i] = NULL;
		graph->visited[i] = 0;
	}
	return graph;
}

Node* createNewNode(int value) {
	Node* newNode = malloc(sizeof(Node));
	newNode->vertex = value;
	newNode->next = NULL;
	return newNode;
}

void printQueue(Queue* q) {
	if (isEmpty(q)) {
		printf("Queue is empty!");
		return;
	} 
	for (int i = q->front; i < q->rear + 1; i++) {
		printf("%d ", q->items[i]);
	}
}

Queue* createQueue() {
	Queue* q = malloc(sizeof(Queue));
	q->front = -1;
	q->rear = -1;
	return q;
}

int isEmpty(Queue* q) {
	if (q->rear == -1) return 1;
	return 0;
}

void enqueue(Queue* q, int value) {
	if (q->rear == SIZE - 1) {
		printf("Queue is full!");
		return;
	} 
	if (q->front == -1) q->front = 0;
	q->rear++;
	q->items[q->rear] = value;
}

int dequeue(Queue* q) {
	int item;
	if (isEmpty(q)) {
		printf("Queue is empty!");
		return -1;
	}
	item = q->items[q->front];
	q->front++;
	if (q->front > q->rear) {
		q->front = -1;
		q->rear = -1;
	}
	return item;
}	