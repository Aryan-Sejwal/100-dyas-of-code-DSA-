#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    return head;
}
int length(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}
void findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = length(head1);
    int len2 = length(head2);

    int diff;
    struct Node *temp1 = head1, *temp2 = head2;

    if (len1 > len2) {
        diff = len1 - len2;
        for (int i = 0; i < diff; i++)
            temp1 = temp1->next;
    } else {
        diff = len2 - len1;
        for (int i = 0; i < diff; i++)
            temp2 = temp2->next;
    }

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data == temp2->data) {
            printf("%d", temp1->data);
            return;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    printf("No Intersection");
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* head1 = createList(n);

    scanf("%d", &m);
    struct Node* head2 = createList(m);

    findIntersection(head1, head2);

    return 0;
}