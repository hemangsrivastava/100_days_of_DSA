#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int visited[MAXN];
int *adj[MAXN];
int deg[MAXN];

void dfs(int node) {
    visited[node] = 1;
    for (int i = 0; i < deg[node]; i++) {
        int neighbor = adj[node][i];
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        adj[i] = (int*)malloc(MAXN * sizeof(int)); 
        deg[i] = 0;
        visited[i] = 0;
    }

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }

    // start DFS from node 1
    dfs(1);

    // count visited nodes
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i]) count++;
    }

    if (count == n)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}
