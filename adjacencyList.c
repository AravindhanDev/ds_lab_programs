#include "stdio.h"
#include "stdlib.h"

typedef struct Node {
  int vertex;
  struct Node* next;
} Node;

typedef struct Graph {
  int numVertices;
  Node** adjLists;
} Graph;

Node* createNewNode(int);
Graph* createGraph(int);
void addEdge(Graph*, int, int);
void printGraph(Graph*);

void main() {
    Graph* graph = createGraph(4);
     addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);
    printGraph(graph);
}

Node* createNewNode(int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = val;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;
  graph->adjLists = malloc(vertices * sizeof(struct node*));
  for (int i = 0; i < vertices; i++)
    graph->adjLists[i] = NULL;

  return graph;
}

void addEdge(Graph* graph, int s, int d) {
    Node* newNode = createNewNode(d);
    newNode->next = graph->adjLists[s];
    graph->adjLists[s] = newNode;

    newNode = createNewNode(s);
    newNode->next = graph->adjLists[d];
    graph->adjLists[d] = newNode;
}

void printGraph(Graph* graph) {
    for (int v = 0; v < graph->numVertices; v++) {
        Node* temp = graph->adjLists[v];
        printf("\nVertex %d -> ", v);
        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}