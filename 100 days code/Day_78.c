#include <stdio.h>
#include <limits.h>

#define MAX 100

int n, m;
int graph[MAX][MAX];
int selected[MAX];

int findMin(int key[]) {
    int min = INT_MAX, index = -1;
    for (int i = 1; i <= n; i++) {
        if (!selected[i] && key[i] < min) {
            min = key[i];
            index = i;
        }
    }
    return index;
}

int main() {
    int u, v, w;

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w; 
    }

    int key[MAX];
    int parent[MAX];

    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        selected[i] = 0;
    }

    key[1] = 0; 
    parent[1] = -1;

    int totalWeight = 0;

    for (int i = 1; i <= n; i++) {
        int u = findMin(key);
        selected[u] = 1;
        totalWeight += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != INT_MAX && !selected[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}