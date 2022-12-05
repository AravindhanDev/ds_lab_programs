#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#define SIZE 5

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* front = NULL, *rear = NULL;
int length = 0;

Node* createNewNode(int);
void enqueue(int);
int dequeue();
bool isFull();
bool isEmpty();
bool isExists(int);
void displayQueue();

void main() {
    printf("Circular Queue Implementation Using Linked List\n");
    int option = 1;
    while (option) {
        int choice;
        printf("\n1) Enqueue");
		printf("\n2) Dequeue");
		printf("\n3) Check if queue is full or not");
		printf("\n4) Check if queue is empty or not");
		printf("\n5) Display queue");
		printf("\n6) Search an element");
        printf("\nEnter choice ");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                option = 0;
                printf("\nResurructed :)\n");
                break;
            
            case 1: {
                if (isFull()) {
                    printf("Queue is full\n");
                    break;
                }
                int value;
                printf("Enter value ");
                scanf("%d", &value);
                enqueue(value);
                printf("%d, Enqueued\n", value);
                break;
            }
            
            case 2: {
                if (isEmpty()) {
                    printf("Queue is empty\n");
                    break;
                }
                int dequeuedElement = dequeue();
                if (!dequeuedElement) {
                    printf("Queue is empty\n");
                    break;
                }
                printf("%d Dequeued\n", dequeuedElement);
                break;
            }

            case 3:
                if (isEmpty()) {
                    printf("Queue is Empty\n");
                    break;
                }
                printf("Queue is not Empty\n");
                break;

            case 4:
                if (isFull()) {
                    printf("Queue is full\n");
                    break;
                }
                printf("Queue is not full\n");
                break;

            case 5:
                displayQueue();
                break;

            case 6: {
                if (isEmpty()) {
                    printf("Queue is Empty\n");
                    break;
                }
                int element;
                printf("Enter element to search ");
                scanf("%d", &element);
                if (isExists(element)) {
                    printf("Element exist\n");
                    break;
                }
                printf("Element not exist\n");
                break;
            }

            default:
                break;
        }
    }
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

Node* createNewNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void enqueue(int value) {
    Node* newNode = createNewNode(value);
    if (front == NULL) {
        front = rear = newNode;
        length++;
        return;
    }
    rear->next = newNode;
    rear = newNode;
    length++;
    return;
}

int dequeue() {
    if (isEmpty()) return 0;
    Node* current = front;
    front = current->next;
    int returnValue = current->data;
    free(current);
    length--;
    return returnValue;
}

bool isExists(int element) {
    if (isEmpty()) return false;    
    Node* current = front;
    while (current != NULL) {
        if (current->data == element) {
            return true;
        }
        current = current->next;
    }
    return false;
}

bool isFull() {
    return length == SIZE;
}

bool isEmpty() {
    return length == 0;
}