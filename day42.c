#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int queue[MAX];
int front = 0, rear = 0;

void enqueue(int val) {
    queue[rear++] = val;
}

int dequeue() {
    return queue[front++];
}

int isQueueEmpty() {
    return front == rear;
}

int isStackEmpty() {
    return top == -1;
}

int main() {
    int n, val;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(val);
    }

    while (!isQueueEmpty()) {
        push(dequeue());
    }

    while (!isStackEmpty()) {
        enqueue(pop());
    }

    for (int i = front; i < rear; i++) {
        printf("%d%s", queue[i], (i == rear - 1) ? "" : " ");
    }
    printf("\n");

    return 0;
}
