#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

typedef struct Node Node;

Node* create();
void preOrder(Node*);
void inOrder(Node*);
void postOrder(Node*);
void delete(Node*, int);
int findHeight(Node*);
int max(int, int);
Node* minValueNode(Node*);
bool isEmpty(Node*);
Node* deleteNode(Node*, int);
bool search(Node*, int, int);

void main() {
	int choice;
	Node* root = NULL;
	printf("\nBinary tree implementation\n");
	while (true) {
		printf("\n1) Create");
		printf("\n2) inOrder");
		printf("\n3) preOrder");
		printf("\n4) postOrder");
		printf("\n5) Height of tree");
		printf("\n6) isEmpty");
		printf("\n7) Delete a node");
		printf("\n8) Search a node");
		printf("\nEnter choice ");
		scanf("%d", &choice);
		switch(choice) {
			case 1: {
				root = create();
				break;
			}

			case 2: {
				inOrder(root);
				printf("\n");
				break;
			} 

			case 3: {
				preOrder(root);
				printf("\n");
				break;
			} 

			case 4: {
				postOrder(root);
				printf("\n");
				break;
			}

			case 5: {
				int height = findHeight(root);
				printf("Height of tree is %d\n", height);
				break;
			}

			case 6: {
				if (isEmpty(root)) {
					printf("Binary Tree is empty\n");
				} else {
					printf("Binary Tree is not empty\n");
				}
				break;
			}

			case 7: {
				int value;
				printf("Enter value to be deleted ");
				scanf("%d", &value);
				root = deleteNode(root, value);
				printf("%d, deleted", value);
				break;
			}

			case 8: {
				int value;
				printf("Enter value to be searched ");
				scanf("%d", &value);
				if (search(root, value, false)) {
					printf("%d, element exist\n", value);
				} else {
					printf("%d, element not exist\n", value);
				}
				break;
			}

			case 0: {
				return;
			} 

			default: break;
		}
	}
}

Node* deleteNode(Node* root, int value) {
	if (root == NULL) return NULL;
	if (root->data == value) {
		if (root->left == NULL && root->right == NULL) {
			free(root);
			return NULL;
		}
		if (root->left == NULL) {
			Node* temp = root->right;
			free(root);
			return temp;
		}
		if (root->right == NULL) {
			Node* temp = root->left;
			free(root);
			return temp;
		}
		Node* temp = minValueNode(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
		free(temp);
	}
	root->left = deleteNode(root->left, value);
	root->right = deleteNode(root->right, value);
	return root;
}

bool search(Node* root, int value, int res) {
	if (root == NULL) return false;
	if (root->data == value) return true;
	if (res) return res;
	res = search(root->left, value, res);
	if (res) return res;
	res = search(root->right, value, res);
}

bool isEmpty(Node* root) {
	return root == NULL;
}

Node* minValueNode(Node* root) {
	Node* temp = root;
	while (temp && temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}

int max(int a, int b) {
	return a > b ? a : b;
}

int findHeight(Node* root) {
	if (root == NULL) return -1;
	return max(findHeight(root->left), findHeight(root->right)) + 1;
}

void preOrder(Node* root) {
	if (root == NULL) return;
	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node* root) {
	if (root == NULL) return;
	inOrder(root->left);
	printf("%d ", root->data);
	inOrder(root->right);
}

void postOrder(Node* root) {
	if (root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->data);
}

Node* create() {
	int value;
	Node* newNode = (Node*)malloc(sizeof(Node));
	printf("Enter value for node ");
	scanf("%d", &value);
	if (value == -1) return NULL;
	newNode->data = value;
	printf("\nEnter left child of %d\n", value);
	newNode->left = create();
	printf("\nEnter right child of %d\n", value);
	newNode->right = create();
	return newNode;
}

