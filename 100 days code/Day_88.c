#include <stdio.h>
#include <stdlib.h>

// Comparator for qsort
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to check if we can place k cows with minimum distance 'dist'
int canPlace(int stalls[], int n, int k, int dist) {
    int count = 1;              // first cow placed at first stall
    int lastPos = stalls[0];

    for (int i = 1; i < n; i++) {
        if (stalls[i] - lastPos >= dist) {
            count++;
            lastPos = stalls[i];

            if (count == k)
                return 1;       // possible
        }
    }
    return 0;                   // not possible
}

int main() {
    int n, k;

    // Input
    scanf("%d %d", &n, &k);

    int stalls[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &stalls[i]);
    }

    // Step 1: Sort stall positions
    qsort(stalls, n, sizeof(int), compare);

    // Step 2: Binary Search on answer
    int left = 1;  // minimum possible distance
    int right = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canPlace(stalls, n, k, mid)) {
            ans = mid;         // valid, try for bigger distance
            left = mid + 1;
        } else {
            right = mid - 1;   // try smaller distance
        }
    }

    // Output
    printf("%d\n", ans);

    return 0;
}