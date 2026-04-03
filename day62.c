#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjLists;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->adjLists = (struct Node**)malloc(V * sizeof(struct Node*));

    for (int i = 0; i < V; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph* graph) {
    printf("\nAdjacency List Representation:\n");
    for (int i = 0; i < graph->V; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("%d: ", i);

        while (temp) {
            printf("%d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {

    int n, m;

    printf("Enter number of vertices and edges (n m): ");
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    printf("Enter %d edges (each as: u v):\n", m);

    for (int i = 0; i < m; i++) {
        int u, v;

        printf("Edge %d: ", i + 1);
        scanf("%d %d", &u, &v);

        addEdge(graph, u, v);
    }

    printGraph(graph);

    return 0;
}
