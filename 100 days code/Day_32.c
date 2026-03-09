#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

int main() {
    int n, m;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &stack[++top]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        if (top != -1) {
            top--;
        }
    }
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}