#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAXN 1005
#define MAXM 10005

typedef struct {
    int to, weight;
} Edge;

Edge adj[MAXN][MAXN];
int adjSize[MAXN];

bool visited[MAXN];

typedef struct {
    int node, weight;
} HeapNode;

HeapNode heap[MAXM];
int heapSize = 0;

// Swap
void swap(HeapNode *a, HeapNode *b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Push into min heap
void push(int node, int weight) {
    heap[++heapSize] = (HeapNode){node, weight};
    int i = heapSize;

    while (i > 1 && heap[i].weight < heap[i/2].weight) {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

// Pop min
HeapNode pop() {
    HeapNode top = heap[1];
    heap[1] = heap[heapSize--];

    int i = 1;
    while (1) {
        int left = 2*i, right = 2*i+1, smallest = i;

        if (left <= heapSize && heap[left].weight < heap[smallest].weight)
            smallest = left;
        if (right <= heapSize && heap[right].weight < heap[smallest].weight)
            smallest = right;

        if (smallest != i) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else break;
    }

    return top;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Build graph
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        adj[u][adjSize[u]++] = (Edge){v, w};
        adj[v][adjSize[v]++] = (Edge){u, w};
    }

    int totalWeight = 0;

    // Start from node 1
    push(1, 0);

    while (heapSize > 0) {
        HeapNode curr = pop();
        int node = curr.node;
        int weight = curr.weight;

        if (visited[node]) continue;

        visited[node] = true;
        totalWeight += weight;

        // Add neighbors
        for (int i = 0; i < adjSize[node]; i++) {
            int next = adj[node][i].to;
            int w = adj[node][i].weight;

            if (!visited[next]) {
                push(next, w);
            }
        }
    }

    printf("%d\n", totalWeight);
    return 0;
}
