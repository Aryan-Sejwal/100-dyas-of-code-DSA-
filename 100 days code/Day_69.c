#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct Node {
    int vertex, weight;
    struct Node* next;
};

struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Node* adj[], int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = adj[u];
    adj[u] = newNode;
}

struct HeapNode {
    int vertex, dist;
};

struct MinHeap {
    int size;
    struct HeapNode heap[MAX];
};

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct MinHeap* h, int i) {
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < h->size && h->heap[l].dist < h->heap[smallest].dist)
        smallest = l;
    if (r < h->size && h->heap[r].dist < h->heap[smallest].dist)
        smallest = r;

    if (smallest != i) {
        swap(&h->heap[i], &h->heap[smallest]);
        heapify(h, smallest);
    }
}

void push(struct MinHeap* h, int v, int dist) {
    int i = h->size++;
    h->heap[i].vertex = v;
    h->heap[i].dist = dist;

    while (i && h->heap[(i-1)/2].dist > h->heap[i].dist) {
        swap(&h->heap[i], &h->heap[(i-1)/2]);
        i = (i-1)/2;
    }
}

struct HeapNode pop(struct MinHeap* h) {
    struct HeapNode root = h->heap[0];
    h->heap[0] = h->heap[--h->size];
    heapify(h, 0);
    return root;
}

int isEmpty(struct MinHeap* h) {
    return h->size == 0;
}

void dijkstra(struct Node* adj[], int V, int src) {
    int dist[MAX];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    struct MinHeap h;
    h.size = 0;

    push(&h, src, 0);

    while (!isEmpty(&h)) {
        struct HeapNode minNode = pop(&h);
        int u = minNode.vertex;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&h, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < V; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }
}

int main() {
    int V, E, u, v, w;

    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    struct Node* adj[MAX] = {NULL};

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(adj, u, v, w);
    }

    int src;
    printf("Enter source: ");
    scanf("%d", &src);

    dijkstra(adj, V, src);

    return 0;
}