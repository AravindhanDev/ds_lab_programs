#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node *head = NULL, *tail = NULL;

// 1 2 3 4 5


Node* createNewNode(int);
void insertAtEnd(int);
void insertAtBeginning(int);
void insertAtSpecificPos(int, int);
void insertBeforeGivenNode(int, int);
void insertAfterGivenNode(int, int);
// void deleteAtEnd(int);
// void deleteAtBeginning(int);
// void deleteAtSpecificPos(int, int);
// void deleteBeforeGivenNode(int, int);
// void deleteAfterGivenNode(int, int);
void display();
// bool searchElement(int);

void main() {
    insertAtEnd(1);
    insertAtEnd(2);
    insertAtEnd(3);
    insertAtEnd(4);
    insertAtEnd(5);
    display();
    insertAfterGivenNode(6, 5);
    display();
}

Node* createNewNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertBeforeGivenNode(int value, int node) {
    Node* newNode = createNewNode(value);
    Node* current = head;
    Node* prev = NULL;
    if (head->data == node) {
        insertAtBeginning(value);
        return;
    }
    while (current != NULL) {
        if (current->data == node) {
            break;
        }
        prev = current;
        current = current->next;
    }
    prev->next = newNode;
    newNode->next = current;
}

void insertAfterGivenNode(int value, int node) {
    Node* newNode = createNewNode(value);
    Node* current = head;
    Node* next = current->next;
    if (tail->data == node) {
        insertAtEnd(value);
        return;
    }
    while (next != NULL) {
        if (current->data == node) {
            break;
        }
        current = next;
        next = next->next;
    }
    current->next = newNode;
    newNode->next = next;
}

void insertAtSpecificPos(int value, int pos) {
    if (pos < 1) {
        printf("Invalid position");
        return;
    }
    if (pos == 1) {
        insertAtBeginning(value);
        return;
    }
    Node* newNode = createNewNode(value);
    Node* current = head;
    int i = 1;
    while (i < pos-1) {
        current = current->next;
        i++;
    }
    newNode->next = current->next;
    current->next = newNode;
}

void insertAtBeginning(int value) {
    Node* newNode = createNewNode(value);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtEnd(int value) {
    Node* newNode = createNewNode(value);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void display() {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}