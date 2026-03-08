#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
} CircularQueue;

CircularQueue* createQueue(int k) {
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->capacity = k;
    q->arr = (int*)malloc(sizeof(int) * k);
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    return q;
}

void enqueue(CircularQueue* q, int value) {
    if (q->size == q->capacity) return;
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = value;
    q->size++;
}

int dequeue(CircularQueue* q) {
    if (q->size == 0) return -1;
    int val = q->arr[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return val;
}

void display(CircularQueue* q) {
    for (int i = 0; i < q->size; i++) {
        printf("%d%s", q->arr[(q->front + i) % q->capacity], (i == q->size - 1) ? "" : " ");
    }
    printf("\n");
}

int main() {
    int n, m;
    
    // Input n elements
    if (scanf("%d", &n) != 1) return 0;
    CircularQueue* q = createQueue(n);
    
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        enqueue(q, val);
    }
    
    // Input m dequeue operations
    scanf("%d", &m);
    
    // According to your example, dequeued elements are re-added to the rear
    // to maintain the "Circular" nature shown in the output (30 40 50 10 20)
    for (int i = 0; i < m; i++) {
        int removed = dequeue(q);
        enqueue(q, removed);
    }
    
    display(q);
    
    // Clean up
    free(q->arr);
    free(q);
    
    return 0;
}
