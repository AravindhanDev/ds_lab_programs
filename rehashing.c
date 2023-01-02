#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

int rehashing(int*, int*, int);
void initializeHashTable(int*, int);
int h1(int, int);
int deleteWithLinearProbing(int*,int , int);
int deleteLinearProbing(int*, int, int, int);
int insertWithLinearProbing(int*, int, int);
int linearProbing(int*, int, int, int);
int searchWithLinearProbing(int*, int, int);
int searchLinearProbing(int*, int, int, int);
void display(int*, int);

void main() {
	int size;
	printf("Enter size of hashtable ");
	scanf("%d", &size);
	int load = 0;
	int* hashTable = (int*)calloc(size, sizeof(int));
	int* tempTable = (int*)calloc(size, sizeof(int));
	int LOAD_BALANCE_LIMIT = (size * (75 / 100));
	initializeHashTable(hashTable, size);
	printf("Hash table implementation\n");
	printf("-------------------------\n");
	int choice;
	while (true) {
		if (load >= LOAD_BALANCE_LIMIT) {
			size = rehashing(hashTable, tempTable, size);
		}
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
				if (insertWithLinearProbing(hashTable, size, value)) {
					printf("%d, inserted\n", value);
					load++;
				} else {
					printf("%d, can't be inserted\n", value);
				}
				break;
			} 

			case 2: {
				int value;
				printf("Enter value ");
				scanf("%d", &value);
				if (deleteWithLinearProbing(hashTable, size, value)) {
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
				int element = searchWithLinearProbing(hashTable, size, value);
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

int rehashing(int* hashTable, int* tempTable, int size) {
	for (int i = 0; i < size; i++) {
		if (hashTable[i] != -1) {
			tempTable[i] = hashTable[i];
		}
	} 
	size *= 2;
	hashTable = (int*)realloc(hashTable, size);
	initializeHashTable(hashTable, size);
	for (int i = 0; i < (size/2); i++) {
		if (tempTable[i] != -1) {
			int key = h1(tempTable[i], size);
			hashTable[key] = tempTable[i];
 		}
	}
	return size;
}

void initializeHashTable(int* hashTable, int size) {
	for (int i = 0; i < size; i++) {
		hashTable[i] = -1;
	}
}

int h1(int value, int size) {
	return value % size;
}

int deleteWithLinearProbing(int* hashTable, int size, int value) {
	int key = h1(value, size);
	if (hashTable[key] == value) {
		hashTable[key] = -1;
		return 1;
	}
	return linearProbing(hashTable, key, size, value);
}

int deleteLinearProbing(int* hashTable, int key, int size, int value) {
	int newKey = 0;
	for (int i = 0; i < size; i++) {
		newKey = (key + i) % size;
		if (hashTable[newKey] == value) {
			hashTable[newKey] = -1;
			return 1;
		}
	}
	return 0;
}

int insertWithLinearProbing(int* hashTable, int size, int value) {
	int key = h1(value, size);
	if (hashTable[key] == -1) {
		hashTable[key] = value;
		return 1;
	}
	return linearProbing(hashTable, key, size, value);
}

int linearProbing(int* hashTable, int key, int size, int value) {
	int newKey = 0;
	for (int i = 0; i < size; i++) {
		newKey = (key + i) % size;
		if (hashTable[newKey] == -1) {
			hashTable[newKey] = value;
			return 1;
		}
	}
	return 0;
}

int searchWithLinearProbing(int* hashTable, int size, int value) {
	int key = h1(value, size);
	if (hashTable[key] == value) {
		return 1;
	}
	return linearProbing(hashTable, key, size, value);
}

int searchLinearProbing(int* hashTable, int key, int size, int value) {
	int newKey = 0;
	for (int i = 0; i < size; i++) {
		newKey = (key + i) % size;
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