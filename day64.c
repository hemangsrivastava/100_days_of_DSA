#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = 0;

void enqueue(int x) {
    queue[rear++] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

void BFS(int n, int adj[MAX][MAX], int source) {
    int visited[MAX] = {0};

    enqueue(source);
    visited[source] = 1;

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, source;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int adj[MAX][MAX];

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter source node: ");
    scanf("%d", &source);

    printf("BFS Traversal: ");
    BFS(n, adj, source);

    return 0;
}
