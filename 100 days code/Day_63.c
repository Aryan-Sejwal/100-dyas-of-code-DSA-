#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];  
int visited[MAX];   
int n;      
void dfs(int v) {
    printf("%d ", v);
    visited[v] = 1;

    for(int i = 0; i < n; i++) {
        if(adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int i, j, edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for(i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; 

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    for(i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}