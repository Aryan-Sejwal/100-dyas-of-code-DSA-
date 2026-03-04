#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, key;
    struct Node *head = NULL, *newNode, *temp, *prev;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    scanf("%d", &key);

    temp = head;
    prev = NULL;
    while(temp != NULL) {
        if(temp->data == key) {
            
            if(prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }

            free(temp);   
            break;        
        }

        prev = temp;
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}