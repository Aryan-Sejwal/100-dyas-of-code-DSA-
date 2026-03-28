#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    
    if (t1 == NULL && t2 == NULL)
        return 1;

    if (t1 == NULL || t2 == NULL)
        return 0;

    if (t1->data == t2->data &&
        isMirror(t1->left, t2->right) &&
        isMirror(t1->right, t2->left))
        return 1;

    return 0;
}

int isSymmetric(struct TreeNode* root) {
    return isMirror(root, root);
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("YES\n");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct TreeNode* nodes[n];

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        if (nodes[i] != NULL) {
            int leftIndex = 2 * i + 1;
            int rightIndex = 2 * i + 2;

            if (leftIndex < n)
                nodes[i]->left = nodes[leftIndex];

            if (rightIndex < n)
                nodes[i]->right = nodes[rightIndex];
        }
    }

    struct TreeNode* root = nodes[0];

    if (isSymmetric(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}