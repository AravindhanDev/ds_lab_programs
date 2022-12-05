#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#define SIZE 5

struct Node {
	int data;
	struct Node *prev;
	struct Node *next;
};

typedef struct Node Node;

Node* front = NULL, *rear = NULL;
int length = 0;

Node* createNewNode(int);
void enqueue(int);
int dequeue();
bool isEmpty();
bool isFull();
void displayQueue();
bool searchElement(int);

void main() {
	printf("\nQueue implementation using linked list\n");
	int option = 1;
	while (true) {
		printf("\n1) Enqueue");
		printf("\n2) Dequeue");
		printf("\n3) Check if queue is full or not");
		printf("\n4) Check if queue is empty or not");
		printf("\n5) Display queue");
		printf("\n6) Search an element");
		int choice;
		printf("\nEnter choice ");
		scanf("%d", &choice);
		switch (choice) {
			case 0:
				printf("End of program");
				return;

			case 1:{
				if (length == SIZE) {
					printf("Queue is full\n");
					break;
				}
				int value;
				printf("Enter value ");
				scanf("%d", &value);
				enqueue(value);
				break;
			}

			case 2: {
				int dequeuedElement = dequeue();
				if (!dequeuedElement) {
					printf("Can't be performed\n");
					break;
				}
				printf("Dequeued Element is %d\n", dequeuedElement);
				break;
			}

			case 3: {
				if (isFull()) {
					printf("Queue is full\n");
					break;
				}
				printf("Queue is not full\n");
				break;
			}

			case 4: {
				if (isEmpty()) {
					printf("Queue is empty\n");
					break;
				}
				printf("Queue is not empty\n");
				break;
			}

			case 5: {
				displayQueue();
				break;
			}

			case 6: {
				int element;
				printf("Enter element ");
				scanf("%d", element);
				bool isFound = searchElement(element);
				if (isFound) {
					printf("Element exist");
				} else {
					printf("Element not existW");
				}
			} 

			default:
				break;
		}
	}
}

bool searchElement(int element) {
	if (isEmpty()) {
		printf("Queue is empty\n");
		return false;
	}
	Node* current = front;
	while (current != NULL) {
		if (current->data = element) {
			return true;
		}
		current = current->next;
	}
}

Node* createNewNode(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void enqueue(int value) {
	if (isFull()) {
		printf("Queue is full\n");
		return;
	} 	 
	Node* newNode = createNewNode(value);
	if (front == NULL) {
		front = rear = newNode;
		length++;
		return;
	}
	rear->next = newNode;
	newNode->prev = rear;
	rear = newNode;
	length++;
}

int dequeue() {
	if (isEmpty()) {
		printf("Queue is empty\n");
		return 0;
	}
	if (front == NULL && rear == NULL) {
		printf("Queue is empty\n");
		return 0;
	}
	Node* temp = front;
	front = temp->next;
	front->prev = NULL;
	int element = temp->data;
	free(temp);
	length--;
	return element;
}

void displayQueue() {
	if (isEmpty()) {
		printf("Queue is empty\n");
		return;
	}
	Node* current = front;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

bool isFull() {
	return length == SIZE;
}

bool isEmpty() {
	return length == 0;
}