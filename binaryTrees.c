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
Node* delete(Node*, int);
int findHeight(Node*);
int max(int, int);
Node* minValueNode(Node*);

void main() {
	int choice;
	Node* root = NULL;
	printf("\nBinary tree implementation\n");
	while (true) {
		printf("\n1) Create");
		printf("\n2) inOrder");
		printf("\n3) preOrder");
		printf("\n4) postOrder");
		printf("\nEnter choice ");
		scanf("%d", &choice);
		switch(choice) {
			case 1: {
				root = create();
				break;
			}

			case 2: {
				inOrder(root);
				break;
			} 

			case 3: {
				preOrder(root);
				break;
			} 

			case 4: {
				postOrder(root);
				break;
			}

			case 0: {
				return;
			} 

			default: break;
		}
	}
}

// Node* minValueNode(Node* root) {
// 	Node* temp = root;
// 	while (temp && temp->left != NULL) {
// 		temp = temp->left;
// 	}
// 	return temp;
// }

// Node* delete(Node* root, int value) {
// 	if (root == NULL) return root;
// 	if (value < root->data) {
// 		root->left = delete(root->left, value);
// 	}
// 	else if (value > root->data) {
// 		root->right = delete(root->right, value);
// 	}
// 	else {
// 		if (root->left == NULL) {
// 			Node* temp = root->right;
// 			free(root);
// 			return temp;
// 		}
// 		else if (root->right == NULL) {
// 			Node* temp = root->left;
// 			free(root);
// 			return temp;
// 		}
// 		Node* temp = minValueNode(root->right);
// 		root->data = temp->data;
// 		root->right = delete(root->right, temp->data);
// 	}
// }

// int max(int a, int b) {
// 	return a > b ? a : b;
// }

// int findHeight(Node* root) {
// 	if (root == NULL) return -1;
// 	return max(findHeight(root->left), findHeight(root->right)) + 1;
// }


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

