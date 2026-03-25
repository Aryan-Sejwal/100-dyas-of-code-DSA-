#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct QueueNode {
    struct Node* treeNode;
    int hd;
};

struct Queue {
    int front, rear;
    struct QueueNode arr[100];
};

void initQueue(struct Queue* q) {
    q->front = q->rear = 0;
}

void enqueue(struct Queue* q, struct Node* node, int hd) {
    q->arr[q->rear].treeNode = node;
    q->arr[q->rear].hd = hd;
    q->rear++;
}

struct QueueNode dequeue(struct Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(struct Queue* q) {
    return q->front == q->rear;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* current = queue[front++];

        if (arr[i] != -1) {
            current->left = newNode(arr[i]);
            queue[rear++] = current->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            queue[rear++] = current->right;
        }
        i++;
    }

    return root;
}

void verticalOrder(struct Node* root) {
    if (root == NULL)
        return;

    struct Queue q;
    initQueue(&q);

    int map[200][100]; 
    int count[200] = {0};

    int offset = 100; 

    enqueue(&q, root, 0);

    while (!isEmpty(&q)) {
        struct QueueNode temp = dequeue(&q);
        struct Node* curr = temp.treeNode;
        int hd = temp.hd;

        map[hd + offset][count[hd + offset]++] = curr->data;

        if (curr->left)
            enqueue(&q, curr->left, hd - 1);

        if (curr->right)
            enqueue(&q, curr->right, hd + 1);
    }

    for (int i = 0; i < 200; i++) {
        if (count[i] != 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", map[i][j]);
            }
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    verticalOrder(root);

    return 0;
}