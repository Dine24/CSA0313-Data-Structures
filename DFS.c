#include <stdio.h>
#include <stdlib.h>
#define MAX 100  
int adj[MAX][MAX];  
int visited[MAX];   
void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;  
}
void DFS(int vertex, int numVertices) {
	int i;
    printf("%d ", vertex);
    visited[vertex] = 1;
    for (i = 0; i < numVertices; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            DFS(i, numVertices);
        }
    }
}
int main() {
    int numVertices, numEdges,i,j;
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);
    for (i = 0; i < numVertices; i++) {
        for (j = 0; j < numVertices; j++) {
            adj[i][j] = 0;
        }
        visited[i] = 0;
    }
    printf("Enter edges (u v) for each edge:\n");
    for (i = 0; i < numEdges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    printf("Depth First Search traversal starting from vertex 0:\n");
    DFS(0, numVertices);

    return 0;
}

