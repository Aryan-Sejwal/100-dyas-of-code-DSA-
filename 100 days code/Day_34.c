#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Node {
    int data;
    struct Node* next;
};
void push(struct Node** top, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}
int pop(struct Node** top) {
    if (*top == NULL) {
        return 0;
    }
    struct Node* temp = *top;
    int val = temp->data;
    *top = temp->next;
    free(temp);
    return val;
}

int main() {
    char exp[100];
    struct Node* stack = NULL;

    fgets(exp, sizeof(exp), stdin);

    char* token = strtok(exp, " ");

    while (token != NULL) {

        if (isdigit(token[0]) || 
           (token[0] == '-' && isdigit(token[1]))) {
            push(&stack, atoi(token));
        }
        else {
            int b = pop(&stack);
            int a = pop(&stack);
            int result;

            if (token[0] == '+') result = a + b;
            else if (token[0] == '-') result = a - b;
            else if (token[0] == '*') result = a * b;
            else if (token[0] == '/') result = a / b;

            push(&stack, result);
        }

        token = strtok(NULL, " ");
    }

    printf("%d", pop(&stack));

    return 0;
}