#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

typedef struct Node Node;

Node* createNode(int);
Node* insert(Node*, int);
Node* delete(Node*, int);
Node* minValueNode(Node*);
Node* maxValueNode(Node*);
void inOrder(Node*);
void preOrder(Node*);
void postOrder(Node*);
bool search(Node*, int);
int findHeight(Node*);
int max(int, int);

void main() {
	Node* root = NULL;
	root = insert(root, 8);
	insert(root, 3);
	insert(root, 1);
	insert(root, 6);
	insert(root, 7);
	insert(root, 10);
	insert(root, 17);
	insert(root, 4);
	inOrder(root);
	preOrder(root);
	postOrder(root);
}

bool search(Node* root, int value) {
	if (root == NULL) return false;
	if (value == root->data) return true;
	if (value < root->data) return search(root->left, value);
	if (value > root->data) return search(root->right, value);
}

int max(int a, int b) {
	return a > b ? a : b;
}

int findHeight(Node* root) {
	if (root == NULL) return -1;
	return max(findHeight(root->left), findHeight(root->right)) + 1;
}

Node* createNode(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = value;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

Node* minValueNode(Node* root) {
	Node* temp = root;
	while (temp && temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}

Node* maxValueNode(Node* root) {
	Node* temp = root;
	while (temp && temp->right != NULL) {
		temp = temp->right;
	}
	return temp;
}

void postOrder(Node* root) {
	if (root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ", root->data);
}

void inOrder(Node* root) {
	if (root == NULL) return;
	inOrder(root->left);
	printf("%d ", root->data);
	inOrder(root->right);
}

void preOrder(Node* root) {
	if (root == NULL) return;
	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}

Node* insert(Node* root, int value) {
	if (root == NULL) return createNode(value);
	if (root->data > value) root->left = insert(root->left, value);
	else root->right = insert(root->right, value);
	return root;
}

Node* delete(Node* root, int value) {
	if (root == NULL) return root;
	if (value < root->data) {
		root->left = delete(root->left, value);
	}
	else if (value > root->data) {
		root->right = delete(root->right, value);
	}
	else {
		if (root->left == NULL) {
			Node* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			Node* temp = root->left;
			free(root);
			return temp;
		}
		Node* temp = minValueNode(root->right);
		root->data = temp->data;
		root->right = delete(root->right, temp->data);
	}
}