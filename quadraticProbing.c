#include "stdio.h"
#include "stdbool.h"
#define size 10

int h1(int, int);
int h2(int, int);
int deleteWithQuadraticProbing(int*, int, int);
int insertWithQuadraticProbing(int*, int, int);
int searchWithQuadraticProbing(int*, int, int);
int quadraticProbing(int*, int, int, int);
int deleteQuadraticProbing(int*, int, int, int);
int searchQuadraticProbing(int*, int, int, int);
void display(int*, int);

void main() {
	int size;
	printf("Enter size: ");
	scanf("%d", &size);
	int hashTable[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
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
				if (insertWithQuadraticProbing(hashTable, size, value)) {
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
				if (deleteWithQuadraticProbing(hashTable, size, value)) {
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
				int element = searchWithQuadraticProbing(hashTable, size, value);
				if (element) {
					printf("%d, exists\n", value);
				} else {
					printf("%d, doesn't exists\n", value);
				}
				break;
			} 

			case 4: {
				display(hashTable, size);
				break;
			} 

			default:
				break;
		}
	}
}

int h1(int value, int size) {
	return ((2 * value) + 3) % size;
}

int h2(int value, int size) {
	return ((3 * value) + 1) % size;
}

int deleteQuadraticProbing(int* hashTable, int key, int size, int value) {
	int newKey = 0;
	for (int i = 0; i < size; i++) {
		newKey = (key + (i*i)) % size;
		if (hashTable[newKey] == value) {
			hashTable[newKey] = -1;
			return 1;
		}
	}
	return 0;
}

int deleteWithQuadraticProbing(int* hashTable, int size, int value) {
	int key = h1(value, size);
	if (hashTable[key] == value) {
		hashTable[key] = -1;
		return 1;
	}
	return quadraticProbing(hashTable, key, size, value);
}

int insertWithQuadraticProbing(int* hashTable, int size, int value) {
	int key = h1(value, size);
	if (hashTable[key] == -1) {
		hashTable[key] = value;
		return 1;
	}
	return quadraticProbing(hashTable, key, size, value);
}

int quadraticProbing(int* hashTable, int key, int size, int value) {
	int newKey = 0;
	for (int i = 0; i < size; i++) {
		newKey = (key + (i*i)) % size;
		if (hashTable[newKey] == -1) {
			hashTable[newKey] = value;
			return 1;
		}
	}
	return 0;
}

int searchWithQuadraticProbing(int* hashTable, int size, int value) {
	int key = h1(value, size);
	if (hashTable[key] == value) {
		return 1;
	}
	return quadraticProbing(hashTable, key, size, value);
}

int searchQuadraticProbing(int* hashTable, int key, int size, int value) {
	int newKey = 0;
	for (int i = 0; i < size; i++) {
		newKey = (key + (i*i)) % size;
		if (hashTable[newKey] == value) {
			return 1;
		}
	}
	return 0;
}

void display(int* hashTable, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", hashTable[i]);
	}
}