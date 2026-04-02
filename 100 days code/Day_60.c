#include <stdio.h>

// Function to check Min-Heap property
int isMinHeap(int arr[], int n) {
    int i;

    // Check for all parent nodes
    for (i = 0; i <= (n - 2) / 2; i++) {
        
        // Check left child
        if (2*i + 1 < n && arr[i] > arr[2*i + 1])
            return 0;

        // Check right child
        if (2*i + 2 < n && arr[i] > arr[2*i + 2])
            return 0;
    }

    return 1;
}

int main() {
    int n, i;

    // Input number of nodes
    scanf("%d", &n);

    int arr[n];

    // Input level-order traversal
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check Min-Heap
    if (isMinHeap(arr, n))
        printf("YES");
    else
        printf("NO");

    return 0;
}