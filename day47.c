#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node *newNode(int data) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data  = data;
    n->left  = n->right = NULL;
    return n;
}

int height(Node *root) {
    if (root == NULL) return 0;

    int leftHeight  = height(root->left);
    int rightHeight = height(root->right);

    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main(void) {
    Node *root    = newNode(1);
    root->left    = newNode(2);
    root->right   = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    printf("Height of the binary tree: %d\n", height(root));

    return 0;
}

