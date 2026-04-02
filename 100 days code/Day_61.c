#include <stdio.h>

int main() {
    int n, m, i, j;
    
    // Input number of vertices and edges
    scanf("%d %d", &n, &m);

    int adj[n][n];

    // Initialize matrix with 0
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    int u, v;

    // Input edges
    for(i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // For undirected graph
        adj[u][v] = 1;
        adj[v][u] = 1;

        // For directed graph (use only this line)
        // adj[u][v] = 1;
    }

    // Print adjacency matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}