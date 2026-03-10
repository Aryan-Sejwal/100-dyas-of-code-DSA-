#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int empty() {
    return (front == -1);
}

// Size
int size() {
    if (empty()) return 0;
    return rear - front + 1;
}

// push_front
void push_front(int value) {
    if (front == -1) {
        front = rear = 0;
    }
    else if (front > 0) {
        front--;
    }
    else {
        printf("No space at front\n");
        return;
    }
    deque[front] = value;
}

// push_back
void push_back(int value) {
    if (rear == MAX - 1) {
        printf("Deque Overflow\n");
        return;
    }
    if (front == -1)
        front = rear = 0;
    else
        rear++;

    deque[rear] = value;
}

// pop_front
void pop_front() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed %d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

// pop_back
void pop_back() {
    if (empty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Removed %d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

// front element
int get_front() {
    if (empty()) return -1;
    return deque[front];
}

// back element
int get_back() {
    if (empty()) return -1;
    return deque[rear];
}

// display
void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);
    push_front(2);

    display();

    printf("Front: %d\n", get_front());
    printf("Back: %d\n", get_back());
    printf("Size: %d\n", size());

    pop_front();
    pop_back();

    display();

    return 0;
}