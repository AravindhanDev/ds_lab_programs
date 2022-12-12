#include "stdio.h"
#include "stdbool.h"
#define SIZE 5

void enqueue(int*, int);
int dequeue(int*);  
bool isFull(int*);
bool isEmpty(int*);
void displayQueue(int*);
bool isExists(int*, int);

int front = -1, rear = -1;

void main() {
    int queue[SIZE];
    printf("Circular Queue Implementation Using queues\n");
    int option = 1;
    while (option) {
        int choice;
        printf("\n1) Enqueue");
		printf("\n2) Dequeue");
		printf("\n3) Check if queue is full or not");
		printf("\n4) Check if queue is empty or not");
		printf("\n5) Display queue");
		printf("\n6) Search element");
        printf("\nEnter choice ");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                option = 0;
                printf("\nResurructed :)\n");
                break;
            
            case 1: {
                if (isFull(queue)) {
                    printf("Queue is full\n");
                    break;
                }
                int value;
                printf("Enter value ");
                scanf("%d", &value);
                enqueue(queue, value);
                printf("%d, Enqueued\n", value);
                break;
            }
            
            case 2: {
                int element = dequeue(queue);
                if (!element) break;
                printf("%d, Dequeued\n", element);
                break;
            }

            case 3:
                if (isFull(queue)) {
                    printf("Queue is full\n");
                    break;
                }
                printf("Queue is not full\n");
                break;

            case 4:
                if (isEmpty(queue)) {
                    printf("Queue is empty\n");
                    break;
                }
                printf("Queue is not empty\n");
                break;

            case 5:
                displayQueue(queue);
                break;

            case 6:{
                if (isEmpty(queue)) {
                    printf("Queue is empty\n");
                    break;
                }
                int element;
                printf("Enter element to be searched ");
                scanf("%d", &element);
                if (isExists(queue, element)) {
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

bool isExists(int* queue, int element) {
    bool found = false;
    for (int i = front; i <= rear; i++) {
        if (queue[i] == element) {
            found = true;
        }
    }
    return found;
}

bool isEmpty(int* queue) {
    return front == -1 && rear == -1;
}

bool isFull(int* queue) {
    return (rear + 1) == SIZE;
}

void displayQueue(int* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void enqueue(int* queue, int value) {
    if (front == -1) ++front;
    queue[++rear] = value;
}

int dequeue(int* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return 0;
    }
    int element = queue[0];
    for (int i = front; i <= rear; i++) {
        queue[i] = queue[i+1];
    }
    rear--;
    if (rear == -1) --front;
    return element;
}
