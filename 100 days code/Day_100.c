#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} Pair;

void merge(Pair arr[], Pair temp[], int left, int mid, int right, int count[]) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (arr[i].value <= arr[j].value) {
            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        } else {
            rightCount++;
            temp[k++] = arr[j++];
        }
    }

    while (i <= mid) {
        count[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int p = left; p <= right; p++) {
        arr[p] = temp[p];
    }
}

void mergeSort(Pair arr[], Pair temp[], int left, int right, int count[]) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, temp, left, mid, count);
    mergeSort(arr, temp, mid + 1, right, count);
    merge(arr, temp, left, mid, right, count);
}

void countSmallerOnRight(int nums[], int n, int count[]) {
    Pair* arr = (Pair*)malloc(n * sizeof(Pair));
    Pair* temp = (Pair*)malloc(n * sizeof(Pair));

    for (int i = 0; i < n; i++) {
        arr[i].value = nums[i];
        arr[i].index = i;
        count[i] = 0;
    }

    mergeSort(arr, temp, 0, n - 1, count);

    free(arr);
    free(temp);
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int count[n];

    countSmallerOnRight(nums, n, count);

    printf("Counts:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", count[i]);
    }

    printf("\n");
    return 0;
}
