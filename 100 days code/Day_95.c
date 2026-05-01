#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    double value;
    struct Node* next;
} Node;

Node* createNode(double value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void sortedInsert(Node** bucket, double value) {
    Node* newNode = createNode(value);

    if (*bucket == NULL || (*bucket)->value >= value) {
        newNode->next = *bucket;
        *bucket = newNode;
        return;
    }

    Node* curr = *bucket;
    while (curr->next != NULL && curr->next->value < value) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;
}

void bucketSort(double arr[], int n) {
    if (n <= 1) return;

    Node** buckets = (Node**)calloc(n, sizeof(Node*));

    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * n);
        sortedInsert(&buckets[index], arr[i]);
    }

    int k = 0;

    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];

        while (curr != NULL) {
            arr[k++] = curr->value;

            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }

    free(buckets);
}

void printArray(double arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main() {
    double arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printArray(arr, n);

    return 0;
}
