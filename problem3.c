#include "stdio.h"
#include "stdlib.h"

int insert(int*, int, int);
int delete(int*, int, int);
int search(int*, int, int);
int insertQuadraticProbing(int*, int, int, int);
int deleteQuadraticProbing(int*, int, int, int);
int searchQuadraticProbing(int*, int, int, int);
void display(int*, int);
int h1(int);

void main() {
    int choice;
    printf("Hash Table Implementation (Quadratic Probing)\n");
    printf("\n");
    int hashTable[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int size = 10;
    while (1)
    {
        printf("\n1) Insert\n");
        printf("2) Delete\n");
        printf("3) Search\n");
        printf("4) Display\n");
        printf("Enter choice");
        scanf("%d", &choice);
        switch (choice) {
            case 0: return;

            case 1: {
                int value;
                printf("Enter value ");
                scanf("%d", &value);
                if (insert(hashTable, size, value)) {
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
                if (delete(hashTable, size, value)) {
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
                if (search(hashTable, size, value)) {
                    printf("%d, exists\n", value);
                } else {
                    printf("%d, not exists\n", value);
                }
                break;
            }

            case 4:
                display(hashTable, size);
                break;
            
            default:
                break;
        }
    }
}

int insert(int* hashTable, int size, int value) {
    int u = h1(value);
    if (hashTable[u] == -1) {
        hashTable[u] = value;
        return 1;
    }
    return insertQuadraticProbing(hashTable, u, size, value);
}

int delete(int* hashTable, int size, int value) {
    int u = h1(value);
    if (hashTable[u] == value) {
        hashTable[u] = -1;
        return 1;
    }
    return deleteQuadraticProbing(hashTable, u, size, value);
}

int search(int* hashTable, int size, int value) {
    int u = h1(value);
    if (hashTable[u] == value) {
        return 1;
    }
    return searchQuadraticProbing(hashTable, u, size, value);
}

int insertQuadraticProbing(int* hashTable, int u, int size, int value) {
    for (int i = 0; i < size; i++) {
        int newkey = (u + (i*i)) % size;
        if (hashTable[newkey] == -1) {
            hashTable[newkey] = value;
            return 1;
        }
    }
    return 0;
}

int deleteQuadraticProbing(int* hashTable, int u, int size, int value) {
    for (int i = 0; i < size; i++) {
        int newkey = (u + (i*i)) % size;
        if (hashTable[newkey] == value) {
            hashTable[newkey] = -1;
            return 1;
        }
    }
    return 0;
}

int searchQuadraticProbing(int* hashTable, int u, int size, int value) {
    for (int i = 0; i < size; i++) {
        int newkey = (u + (i*i)) % size;
        if (hashTable[newkey] == value) {
            return 1;
        }
    }
    return 0;
}

void display(int* hashTable, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", hashTable[i]);
    }
    printf("\n");
}

int h1(int value) {
    return value % 10;
}