#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#define size 5

int push(char*, int, char);
int pop(char*, int);
char peek(char*, int);
bool isEmpty(int);
bool isFull(int);
void display(char*, int);
int noOfOccurances(char*, char);
bool in(char*, char);

void main() {
    char numbers[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    printf("\nStack implementation using arrays\n");
    char stack[size];
    int top = -1;
    int choice;
    while(true) {
        printf("\n1) Push element\n");
        printf("2) Pop element\n");
        printf("3) Peek element\n");
        printf("4) Display element\n");
        printf("5) Find occurrence\n");
        printf("Enter choice ");
        scanf("%d", &choice);
        switch(choice) {
            case 0: return;

            case 1: {
                if (isFull(top)) {
                    printf("Stack Overflow\n");
                    break;
                }
                char value;
                printf("Enter value ");
                getchar();
                scanf("%c", &value);
                if (in(numbers, value)) {
                    printf("ValueError: Value of type integer instead of char\n");
                    break;
                }
                int last = peek(stack, top);
                if (last == value) {
                    printf("Can't repetitively pushed\n");
                    break;
                }
                top = push(stack, top, value);
                printf("%c, pushed\n", value);
                break;
            }

            case 2: {
                if (isEmpty(top)) {
                    printf("Stack Underflow\n");
                    break;
                }
                top = pop(stack, top);
                if (top == -1) {
                    printf("Stack is empty\n");
                } else {
                    printf("Popped\n");
                }
                break;
            }

            case 3: {
                char value = peek(stack, top);
                if (value == '\0') {
                    printf("Stack is empty\n");
                } else {
                    printf("%c is top element\n", value);
                }
                break;
            }

            case 4: {
                display(stack, top);
                printf("\n");
                break;
            }

            case 5: {
                int value;
                printf("Enter value ");
                getchar();
                scanf("%c", &value);
                int res = noOfOccurances(stack, value);
                printf("%d, times occured\n", res);
            }

            default: break;
        }
    }
}

bool in(char* numbers, char value) {
    for (int i = 0;  i < 10; i++) {
        if (numbers[i] == value) {
            return true;
        }
    }
    return false;
}

int noOfOccurances(char* stack, char value) {
    int charCount = 0;
    for (int i = 0; i < size; i++) {
        if (stack[i] == value) ++charCount;
    }
    return charCount;
}

void display(char* stack, int top) {
    for (int i = 0; i <= top; i++) {
        printf("%c ", stack[i]);
    }
}

int push(char* stack, int top, char value) {
    if (isFull(top)) return false;
    stack[++top] = value;
    return top;
}

int pop(char* stack, int top) {
    if (top == -1) return top;
    stack[top] = '\0';
    return --top; 
}

char peek(char* stack, int top) {
    if (top == -1) return '\0';
    return stack[top];
}

bool isEmpty(int top) {
    return top == -1;
}

bool isFull(int top) {
    return top + 1 == size;
}
