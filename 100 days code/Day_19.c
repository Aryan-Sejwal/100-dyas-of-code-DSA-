#include <stdio.h>
#include <stdlib.h>   

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min_sum = 1000000;   
    int first = 0, second = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {

            int sum = arr[i] + arr[j];

            if(abs(sum) < abs(min_sum)) {
                min_sum = sum;
                first = arr[i];
                second = arr[j];
            }
        }
    }

    printf("%d %d", first, second);

    return 0;
}