#include <stdio.h>

int main() {
    int n, pos, x;
    scanf("%d", &n);
    int arr[50];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &pos);
    scanf("%d", &x);
    for(int i = n-1; i >= pos-1; i--) {
        arr[i+1] = arr[i];
    }
    arr[pos-1] = x;
    for(int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}