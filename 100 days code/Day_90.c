#include <stdio.h>

int isPossible(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int currTime = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxTime)
            return 0;

        if (currTime + arr[i] > maxTime) {
            painters++;
            currTime = arr[i];

            if (painters > k)
                return 0;
        } else {
            currTime += arr[i];
        }
    }
    return 1;
}

int minTime(int arr[], int n, int k) {
    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > low)
            low = arr[i];   
        high += arr[i];     
    }

    int result = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (isPossible(arr, n, k, mid)) {
            result = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;  
        }
    }

    return result;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d\n", minTime(arr, n, k));

    return 0;
}