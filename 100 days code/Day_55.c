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
struct Queue {
    struct Node* arr[100];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, struct Node* node) {
    if (q->rear == 99) return;

    if (q->front == -1)
        q->front = 0;

    q->arr[++q->rear] = node;
}
struct Node* dequeue(struct Queue* q) {
    if (isEmpty(q)) return NULL;

    struct Node* temp = q->arr[q->front];

    if (q->front == q->rear)
        q->front = q->rear = -1;
    else
        q->front++;

    return temp;
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Queue q;
    initQueue(&q);

    struct Node* root = newNode(arr[0]);
    enqueue(&q, root);

    int i = 1;

    while (!isEmpty(&q) && i < n) {
        struct Node* temp = dequeue(&q);

        if (arr[i] != -1) {
            temp->left = newNode(arr[i]);
            enqueue(&q, temp->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            temp->right = newNode(arr[i]);
            enqueue(&q, temp->right);
        }
        i++;
    }

    return root;
}

int size(struct Queue* q) {
    if (isEmpty(q)) return 0;
    return q->rear - q->front + 1;
}

void rightView(struct Node* root) {
    if (root == NULL) return;

    struct Queue q;
    initQueue(&q);

    enqueue(&q, root);

    while (!isEmpty(&q)) {
        int n = size(&q);

        for (int i = 1; i <= n; i++) {
            struct Node* temp = dequeue(&q);

            if (i == n) {
                printf("%d ", temp->data);
            }

            if (temp->left)
                enqueue(&q, temp->left);

            if (temp->right)
                enqueue(&q, temp->right);
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

    rightView(root);

    return 0;
}