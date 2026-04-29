#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;   // element found

        else if (arr[mid] < key)
            left = mid + 1;   // search right half

        else
            right = mid - 1;  // search left half
    }

    return -1; // not found
}

int main() {
    int n, key;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input sorted array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input element to search
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}