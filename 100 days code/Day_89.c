#include <stdio.h>

// Function to check if allocation is possible
int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than maxPages
        if (arr[i] > maxPages)
            return 0;

        if (pagesSum + arr[i] > maxPages) {
            students++;
            pagesSum = arr[i];

            if (students > m)
                return 0;
        } else {
            pagesSum += arr[i];
        }
    }
    return 1;
}

// Function to find minimum maximum pages
int allocateBooks(int arr[], int n, int m) {
    if (n < m)
        return -1;

    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    int low = max;
    int high = sum;
    int result = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1; // try smaller value
        } else {
            low = mid + 1;  // increase pages
        }
    }

    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = allocateBooks(arr, n, m);
    printf("%d\n", result);

    return 0;
}