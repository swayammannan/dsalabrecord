#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

/* Create a new tree node */
struct TreeNode* newNode(int data) {
    struct TreeNode* n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    n->data = data; n->left = n->right = NULL;
    return n;
}

/* Insert: left if smaller, right if larger */
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data) root->left  = insert(root->left,  data);
    else                   root->right = insert(root->right, data);
    return root;
}

/* Pre-order: Root → Left → Right */
void pre_order_traversal(struct TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);          /* visit root */
    pre_order_traversal(root->left);   /* go left  */
    pre_order_traversal(root->right);  /* go right */
}

int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    printf("Pre-order: ");
    pre_order_traversal(root);
    printf("\n");
    return 0;
}