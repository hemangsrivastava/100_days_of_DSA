#include <stdbool.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Simple queue structure
struct Queue {
    struct TreeNode** data;
    int front, rear, size, capacity;
};

struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = 0;
    q->size = 0;
    q->rear = capacity - 1;
    q->data = (struct TreeNode**)malloc(capacity * sizeof(struct TreeNode*));
    return q;
}

void enqueue(struct Queue* q, struct TreeNode* item) {
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = item;
    q->size++;
}

struct TreeNode* dequeue(struct Queue* q) {
    struct TreeNode* item = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

bool isEmpty(struct Queue* q) {
    return q->size == 0;
}

bool isSymmetric(struct TreeNode* root) {
    struct Queue* q = createQueue(2000);
    
    enqueue(q, root);
    enqueue(q, root);

    while (!isEmpty(q)) {
        struct TreeNode* t1 = dequeue(q);
        struct TreeNode* t2 = dequeue(q);

        if (t1 == NULL && t2 == NULL)
            continue;
        if (t1 == NULL || t2 == NULL)
            return false;
        if (t1->val != t2->val)
            return false;

        enqueue(q, t1->left);
        enqueue(q, t2->right);
        enqueue(q, t1->right);
        enqueue(q, t2->left);
    }

    return true;
}
