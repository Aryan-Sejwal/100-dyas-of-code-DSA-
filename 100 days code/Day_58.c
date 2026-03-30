#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Find index of value in inorder array
int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

// Build tree function
struct Node* buildTree(int preorder[], int inorder[], int start, int end, int *preIndex) {
    if (start > end)
        return NULL;

    // Get current root from preorder
    int curr = preorder[*preIndex];
    (*preIndex)++;

    struct Node* root = newNode(curr);

    // If only one node
    if (start == end)
        return root;

    // Find root in inorder
    int pos = search(inorder, start, end, curr);

    // Build left and right subtree
    root->left = buildTree(preorder, inorder, start, pos - 1, preIndex);
    root->right = buildTree(preorder, inorder, pos + 1, end, preIndex);

    return root;
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    // Input preorder
    for (int i = 0; i < n; i++) {
        scanf("%d", &preorder[i]);
    }

    // Input inorder
    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    int preIndex = 0;

    // Build tree
    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    // Print postorder
    postorder(root);

    return 0;
}