#include <stdio.h>
#include <limits.h>
#define V 5
int minDistance(int dist[], int visited[]){
    int min = INT_MAX, min_index;
    for (int v=0; v<V; v++){
        if (!visited[v] && dist[v] <= min){
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}





int main(){

    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {0, 0, 50, 0, 0},
        {0, 0, 0, 0, 10},
        {0, 0, 20, 0, 60},
        {0, 0, 0, 0, 0}
    }

    dijkstra(graph, 0);
    return 0;
}
