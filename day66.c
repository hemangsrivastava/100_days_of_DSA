#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(int node, int** adj, int* adjSize, bool* visited, bool* recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, adjSize, visited, recStack)) {
                return true;
            }
        } else if (recStack[neighbor]) {
            return true; // cycle found
        }
    }

    recStack[node] = false; // backtrack
    return false;
}

int hasCycle(int V, int** adj, int* adjSize) {
    bool* visited = (bool*)calloc(V, sizeof(bool));
    bool* recStack = (bool*)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSize, visited, recStack)) {
                return 1; // YES
            }
        }
    }

    return 0; // NO
}
