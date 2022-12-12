#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left, *right;
};

typedef struct Node Node;

Node* createNewNode(int);
Node* insert(Node*, int);
void inOrder(Node*);
void preOrder(Node*);
void postOrder(Node*);

int main() {
    Node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);
    printf("InOrder Traversal: ");
    inOrder(root);
    printf("\nPreOrder Traversal: ");
    preOrder(root);
    printf("\nPostOrder Traversal: ");
    postOrder(root);
}

Node *createNewNode(int value) {
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->data = value;
  temp->left = temp->right = NULL;
  return temp;
}

void preOrder(Node *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node *root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

void postOrder(Node *root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

Node *insert(Node *node, int data) {
  if (node == NULL) return createNewNode(data);

  if (data < node->data) node->left = insert(node->left, data);
  else node->right = insert(node->right, data);
  return node;
}