#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

struct Node {
  int data;
  struct Node *left, *right;
};

typedef struct Node Node;

Node* createNewNode(int);
Node* insert(Node*, int);
Node* minValueNode(Node*);
Node* deleteNode(Node*, int);
int search(Node*, int);
void inOrder(Node*);
bool isEmpty(Node*);

void main() {
  Node *root = NULL;
  printf("Binary Tree Implementation");
  while (true) {
    printf("\n1) Insert");
    printf("\n2) Delete");
    printf("\n3) Search");
    printf("\n4) Traversal");
    printf("\n5) Check if binary tree is empty");
    printf("\nEnter your choice ");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1: {
            int value;
            printf("\nEnter value ");
            scanf("%d", &value);
            if (value == -1) break;
            root = insert(root, value);
            printf("%d inserted\n", value);
            // 8, 3, 1, 6, 7, 10, 14, 4
            break;
        }
        
        case 2: {
            int value;
            printf("\nEnter node to be deleted ");
            scanf("%d", &value);
            if (value == -1) break;
            root = deleteNode(root, value);
            printf("%d is deleted\n", value);
            break;
        }

        case 3: {
            int value;
            printf("\nEnter value to search ");
            scanf("%d", &value);
            if (value == -1) break;
            int res = search(root, value);
            if (res == 1) {
                printf("Element found\n");
            } else {
                printf("Element not found\n");
            }
            break;
        }

        case 4: {
            inOrder(root);
            printf("\n");
            break;
        }

        case 5: {
            if (isEmpty(root)) {
              printf("Binary tree is empty\n");
            } else {
              printf("Binary tree is not empty\n");
            }
            break;
        }

        case 0: exit(0);

        default:
          break;
    }
  }
}

bool isEmpty(Node* root) {
  return root == NULL;
}

Node *createNewNode(int value) {
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->data = value;
  temp->left = temp->right = NULL;
  return temp;
}

void inOrder(Node *root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

Node *insert(Node *node, int data) {
  if (node == NULL) return createNewNode(data);

  if (data < node->data) node->left = insert(node->left, data);
  else node->right = insert(node->right, data);
  return node;
}

Node *minValueNode(Node *node) {
  Node *current = node;

  while (current && current->left != NULL)
    current = current->left;

  return current;
}

Node *deleteNode(Node *root, int data) {
  if (root == NULL) return root;
  if (data < root->data)
    root->left = deleteNode(root->left, data);
  else if (data > root->data)
    root->right = deleteNode(root->right, data);
  else {
    if (root->left == NULL) {
      Node *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      Node *temp = root->left;
      free(root);
      return temp;
    }
    Node *temp = minValueNode(root->right);
    root->data = temp->data;
    root->right = deleteNode(root->right, temp->data);
  }
  return root;
}

int search(Node* root, int value) 
{ 
    while (root != NULL){
        if (value > root->data) root = root->right; 
        else if (value < root->data) root = root->left; 
        else return 1;
    } 
    return 0; 
} 