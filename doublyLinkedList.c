#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

struct Node {
	int data;
	struct Node *prev;
	struct Node* next;
};

typedef struct Node Node;

Node *head = NULL, *tail = NULL;

Node* createNewNode(int);
int searchElement(int);
bool isLinkedListEmpty();
void insertAtBeginning(int);
void insertAtEnd(int);
void insertAtSpecificPos(int, int);
void insertBeforeGivenNode(int, int);
void insertAfterGivenNode(int, int);
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtSpecificPos(int);
void deleteBeforeGivenNode(int);
void deleteAfterGivenNode(int);
void displayList();

void main() {
	int option = 1;
    int choice;
    while (option) {
        printf("\nDoubly Linked List");
        printf("\n------------------\n");
        printf("\n1) Insert at beginning ");
        printf("\n2) Insert at end ");
        printf("\n3) Insert before given node ");
        printf("\n4) Insert after given node ");
        printf("\n5) Delete at beginning ");
        printf("\n6) Delete at end ");
        printf("\n7) Delete before given node ");
        printf("\n8) Delete after given node ");
        printf("\n9) Search an element in linkedlist ");
        printf("\n10) Insert at specific Position ");
        printf("\n11) Delete at specific Position ");
        printf("\n12) Display the linkedlist ");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 0:
                option = 0;
                printf("\nThank you for using us :)");
                break;

            case 1: {
                int value;
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            }
            
            case 2:{
                int value;
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            }

            case 3: {
                int value, node;
                printf("\nEnter value: ");
                scanf("%d", &value);
                printf("\nEnter node: ");
                scanf("%d", &node);
                insertBeforeGivenNode(value, node);
                break;
            }

            case 4: {
                int value, node;
                printf("Enter value: ");
                scanf("%d", &value);
                printf("\nEnter node: ");
                scanf("%d", &node);
                insertAfterGivenNode(value, node);
                break;
            }
                
            case 5:
                deleteAtBeginning();
                break;

            case 6:
                deleteAtEnd();
                break;

            case 7: {
                int node;
                printf("Enter node: ");
                scanf("%d", &node);
                deleteBeforeGivenNode(node);
                break;
            }

            case 8: {
                int node;
                printf("Enter node: ");
                scanf("%d", &node);
                deleteAfterGivenNode(node);
                break;
            }

            case 9: {
                int ele;
                printf("Enter element to be searched ");
                scanf("%d", &ele);
                int res = searchElement(ele);
                if (res) {
                    printf("Element exists");
                    break;
                }
                printf("Element not exists");
                break;
            }

            case 10: {
                int pos, value;
                printf("\nEnter position: ");
                scanf("%d", &pos);
                printf("\nEnter value: ");
                scanf("%d", &value);
                insertAtSpecificPos(value, pos);
                break;
            }

            case 11: {
                int pos;
                printf("\nEnter position: ");
                scanf("%d", &pos);
                deleteAtSpecificPos(pos);
                break;
            }   

            case 12:
                displayList();
                break;

            default:
                option= 0;
                printf("\nThank you for using us :)");
                break;
        }
    }
}

bool isLinkedListEmpty() {
	if (head == NULL) {
		printf("Linked list is empty");
		return true;
	}
	return false;
}

Node* createNewNode(int value) {
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = value;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void displayList() {
	Node* current = head;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
}

int searchElement(int value) {
	Node* current = head;
	int isExist = 0;
	while (current->next != NULL) {
		if (current->data == value) {
			isExist = 1;
		}
		current = current->next;
	}
	return isExist;
}

void insertAtEnd(int value) {
	Node* newNode = createNewNode(value);
	if (head == NULL) {
		head = tail = newNode;
		return;
	}
	tail->next = newNode;
	newNode->prev = tail;
	tail = newNode;
	return;
}

void insertAtBeginning(int value) {
	Node* newNode = createNewNode(value);
	if (head == NULL) {
		head = tail = newNode;
		return;
	}
	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	return;
}

void insertAfterGivenNode(int value, int node) {
	Node* newNode = createNewNode(value);
	Node* current = head;
	if (tail->data == node) {
		insertAtEnd(value);
		return;
	}
	while (current->next != NULL) {
		if (current->data == node) {
			break;
		}
		current = current->next;
	}
	Node* next = current->next;
	current->next = newNode;
	newNode->prev = current;
	newNode->next = next;
	next->prev = newNode;
}

void insertBeforeGivenNode(int value ,int node) {
	Node* newNode = createNewNode(value);
	Node* current = head;
	if (current->data == node) {
		insertAtBeginning(value);
		return;
	}
	while (current->next != NULL) {
		if (current->data == node) {
			break;
		}
		current = current->next;
	}
	Node* prev = current->prev;
	prev->next = newNode;
	newNode->prev = prev;
	newNode->next = current;
	current->prev = newNode;
}

void insertAtSpecificPos(int value, int pos) {
    Node* newNode = createNewNode(value);
    Node* current = head;
    int i = 1;
    while (i < pos-1) {
        current = current->next;
        i++;
    }
    Node* next = current->next;
    current->next = newNode;
    newNode->prev = current;
    newNode->next = next;
    next->prev = newNode;
}

void deleteAtEnd() {
	if (isLinkedListEmpty()) return;
	Node* prev = tail->prev;
	Node* current = tail;
	tail = prev;
	tail->next = NULL;
	free(current);
}

void deleteAtBeginning() {
	if (isLinkedListEmpty()) return;
	Node* current = head;
	head = current->next;
	head->prev = NULL;
	free(current);
}

void deleteBeforeGivenNode(int node) {
	if (isLinkedListEmpty()) return;
    Node* current = head;
    while (current->next != NULL) {
    	if (current->data == node) {
    		break;
    	}
    	current = current->next;
    }
    Node* prev = current->prev;
    if (prev == head) deleteAtBeginning();
    Node* prevPrev = prev->prev;
    prevPrev->next = current;
    current->prev = prevPrev;
    free(prev);
}

void deleteAfterGivenNode(int node) {
	if (isLinkedListEmpty()) return;
	Node* current = head;
	while (current->next != NULL) {
		if (current->data == node) {
			break;
		}
		current = current->next;
	}
	Node* next = current->next;
	if (next == tail) deleteAtEnd();
	Node* nextNext = next->next;
	current->next = nextNext;
	nextNext->prev = current;
	free(next);
}

void deleteAtSpecificPos(int pos) {
	if (isLinkedListEmpty()) return;
	if (pos < 1) {
		printf("Invalid position");
		return;
	}
	Node* current = head;
    int i = 1;
    while (i < pos) {
        current = current->next;
        i++;
    }
    Node* prev = current->prev;
    Node* next = current->next;
    prev->next = next;
    next->prev = prev;
    free(current);
}