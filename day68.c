#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue implementation
int queue[MAX], front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int main() {
    int V, E;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};

    // Input edges
    printf("Enter edges (u v) meaning u -> v:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    // Step 1: Add all vertices with indegree 0 to queue
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    int topo[MAX];
    int count = 0;

    // Step 2: Process queue
    while (!isEmpty()) {
        int node = dequeue();
        topo[count++] = node;

        for (int i = 0; i < V; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // Step 3: Check for cycle
    if (count != V) {
        printf("Cycle detected! Topological sort not possible.\n");
        return 0;
    }

    // Print result
    printf("Topological Order: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", topo[i]);
    }

    return 0;
}
