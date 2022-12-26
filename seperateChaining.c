#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#define SIZE 10

typedef struct Node {
	int data;
	struct Node* next;
} Node;

Node* chain[SIZE];

Node* createNewNode(int);
void init();
int insert(int);
int delete(int);
bool search(int);
int getKey(int);
void display();

void main() {
	init();
	printf("Hash table implementation\n");
	printf("-------------------------\n");
	int choice;
	while (true) {
		printf("\n1) Insert\n");
		printf("2) Delete\n");
		printf("3) Search\n");
		printf("4) Display\n");
		printf("Enter choice ");
		scanf("%d", &choice);
		switch(choice) {
			case 0: 
				return;

			case 1: {
				int value;
				printf("Enter value ");
				scanf("%d", &value);
				if (insert(value)) {
					printf("%d, inserted\n", value);
				} else {
					printf("%d, can't be inserted\n", value);
				}
				break;
			} 

			case 2: {
				int value;
				printf("Enter value ");
				scanf("%d", &value);
				if (delete(value)) {
					printf("%d, deleted\n", value);
				} else {
					printf("%d, can't be deleted\n", value);
				}
				break;
			} 

			case 3: {
				int value;
				printf("Enter value ");
				scanf("%d", &value);
				int element = search(value);
				if (element) {
					printf("%d, exists\n", value);
				} else {
					printf("%d, doesn't exists\n", value);
				}
				break;
			} 

			case 4: {
				display();
				break;
			} 

			default:
				break;
		}
	}
}

Node* createNewNode(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

void init() {
	for (int i = 0; i < SIZE; i++) {
		chain[i] = NULL;
	}
}

int insert(int value) {
	Node* newNode = createNewNode(value);
	int key = getKey(value);
	if (chain[key] == NULL) {
		chain[key] = newNode;
		return 1;
	}	
	Node* temp = chain[key];
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
}

int getKey(int value) {
	return value % SIZE;
}

bool search(int value) {
	int key = getKey(value);
	Node* temp = chain[key];
	while (temp) {
		if (temp->data == value) {
			return true;
		}
		temp = temp->next;
	}
	return false;
}

int delete(int value) {
	int key = getKey(value);
	Node* temp = chain[key], *dealloc;
	if (temp == NULL) return 0;
	if (temp->data == value) {
		temp = NULL;
		return 1;
	}
	while (temp->next) {
		if (temp->next->data == value) {
			dealloc = temp->next;
			temp->next = temp->next->next;
			free(dealloc);
			return 1;
		}
		temp = temp->next;
	}
}

void display() {
	printf("\nHash Table");
	printf("\n----------\n");
	for (int i = 0; i < SIZE; i++) {
		Node* temp = chain[i];
		while (temp) {
			printf("%d -> ", temp->data);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}