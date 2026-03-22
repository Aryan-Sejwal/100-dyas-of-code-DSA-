#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}
struct TreeNode* searchBST(struct TreeNode* root, int val) {
   
    if (root == NULL || root->val == val) {
        return root;
    }

    if (val < root->val) {
        return searchBST(root->left, val);
    }

    return searchBST(root->right, val);
}

int main() {
    struct TreeNode* root = NULL;

    root = insertIntoBST(root, 50);
    insertIntoBST(root, 30);
    insertIntoBST(root, 70);
    insertIntoBST(root, 20);
    insertIntoBST(root, 40);
    insertIntoBST(root, 60);
    insertIntoBST(root, 80);

    int key = 60;

    struct TreeNode* result = searchBST(root, key);

    if (result != NULL) {
        printf("Value %d found in BST\n", key);
    } else {
        printf("Value %d not found in BST\n", key);
    }

    return 0;
}