#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = front;
    printf("%d\n", front->data);

    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

int main() {
    int N;
    scanf("%d", &N);

    char op[10];
    int value;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (op[0] == 'e') {  
            scanf("%d", &value);
            enqueue(value);
        } 
        else if (op[0] == 'd') {  
            dequeue();
        }
    }

    return 0;
}