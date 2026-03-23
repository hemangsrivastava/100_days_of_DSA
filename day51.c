#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Create new node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Find path from root to target node
bool findPath(struct TreeNode* root, struct TreeNode* target, struct TreeNode** path, int* pathLen) {
    if (root == NULL) return false;

    path[(*pathLen)++] = root;

    if (root == target) return true;

    if (findPath(root->left, target, path, pathLen) ||
        findPath(root->right, target, path, pathLen)) {
        return true;
    }

    // Backtrack
    (*pathLen)--;
    return false;
}

// LCA using path comparison (local solution)
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode* path1[1000];
    struct TreeNode* path2[1000];
    int len1 = 0, len2 = 0;

    if (!findPath(root, p, path1, &len1) || !findPath(root, q, path2, &len2)) {
        return NULL;
    }

    int i = 0;
    while (i < len1 && i < len2 && path1[i] == path2[i]) {
        i++;
    }

    return path1[i - 1];
}

// Example usage
int main() {
    /*
            3
           / \
          5   1
         / \ / \
        6  2 0  8
          / \
         7   4
    */

    struct TreeNode* root = newNode(3);
    root->left = newNode(5);
    root->right = newNode(1);

    root->left->left = newNode(6);
    root->left->right = newNode(2);
    root->right->left = newNode(0);
    root->right->right = newNode(8);

    root->left->right->left = newNode(7);
    root->left->right->right = newNode(4);

    struct TreeNode* p = root->left;              // Node 5
    struct TreeNode* q = root->left->right->right; // Node 4

    struct TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca != NULL) {
        printf("LCA: %d\n", lca->val);
    } else {
        printf("LCA not found\n");
    }

    return 0;
}
