#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0;
int rear = -1;
int size = 0;

void enqueue(int value) {
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    size++;
}

void dequeue() {
    if (size == 0)
        return;

    front = (front + 1) % MAX;
    size--;
}

void display() {
    int i = front;

    for (int count = 0; count < size; count++) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        dequeue();
    }

    display();

    return 0;
}