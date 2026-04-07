#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];   
int visited[MAX];
int recStack[MAX];
int n;

int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[v][i]) {
           
            if (!visited[i] && dfs(i))
                return 1;

            else if (recStack[i])
                return 1;
        }
    }

    recStack[v] = 0; 
    return 0;
}

int hasCycle() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i))
                return 1;
        }
    }
    return 0;
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        recStack[i] = 0;
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;
    }

    printf("Enter edges (u v) for directed graph:\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }

    if (hasCycle())
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}