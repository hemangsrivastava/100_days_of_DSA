#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 1005
#define MAXM 20005

typedef struct {
    int v, w, next;
} Edge;

Edge edges[MAXM];
int head[MAXN], edge_count = 0;

void addEdge(int u, int v, int w) {
    edges[edge_count].v = v;
    edges[edge_count].w = w;
    edges[edge_count].next = head[u];
    head[u] = edge_count++;
}

// -------- Min Heap --------
typedef struct {
    int node, dist;
} HeapNode;

HeapNode heap[MAXM];
int size = 0;

void swap(int i, int j) {
    HeapNode temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void push(int node, int dist) {
    heap[++size].node = node;
    heap[size].dist = dist;

    int i = size;
    while (i > 1 && heap[i].dist < heap[i/2].dist) {
        swap(i, i/2);
        i /= 2;
    }
}

HeapNode pop() {
    HeapNode root = heap[1];
    heap[1] = heap[size--];

    int i = 1;
    while (1) {
        int smallest = i;
        int left = 2*i, right = 2*i + 1;

        if (left <= size && heap[left].dist < heap[smallest].dist)
            smallest = left;
        if (right <= size && heap[right].dist < heap[smallest].dist)
            smallest = right;

        if (smallest != i) {
            swap(i, smallest);
            i = smallest;
        } else break;
    }

    return root;
}

// -------- Dijkstra --------
int dist[MAXN];

void dijkstra(int n, int source) {
    for (int i = 1; i <= n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;
    push(source, 0);

    while (size > 0) {
        HeapNode top = pop();
        int u = top.node;
        int d = top.dist;

        if (d > dist[u]) continue;

        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].v;
            int w = edges[i].w;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
        }
    }
}

// -------- Main --------
int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++)
        head[i] = -1;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w); // remove if directed
    }

    int source;
    scanf("%d", &source);

    dijkstra(n, source);

    for (int i = 1; i <= n; i++)
        printf("%d ", dist[i]);

    return 0;
}
