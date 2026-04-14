#include <stdio.h>
#include <stdlib.h>

struct TreeNode { int data; struct TreeNode* left; struct TreeNode* right; };

struct TreeNode* newNode(int d) {
    struct TreeNode* n=(struct TreeNode*)malloc(sizeof(struct TreeNode));
    n->data=d;n->left=n->right=NULL;return n;
}
struct TreeNode* insert(struct TreeNode* r,int d){
    if(!r)return newNode(d);
    if(d<r->data)r->left=insert(r->left,d);
    else r->right=insert(r->right,d);
    return r;
}

/* Find a node by value */
struct TreeNode* find(struct TreeNode* root, int val) {
    if (!root) return NULL;
    if (root->data == val) return root;
    struct TreeNode* l = find(root->left, val);
    return l ? l : find(root->right, val);
}

/* Print grandchildren of node with value 'val' */
void find_grandchildren(struct TreeNode* root, int val) {
    struct TreeNode* node = find(root, val);
    if (!node) { printf("Node not found\n"); return; }
    printf("Grandchildren of %d: ", val);
    /* Children of left child */
    if (node->left) {
        if (node->left->left)  printf("%d ", node->left->left->data);
        if (node->left->right) printf("%d ", node->left->right->data);
    }
    /* Children of right child */
    if (node->right) {
        if (node->right->left)  printf("%d ", node->right->left->data);
        if (node->right->right) printf("%d ", node->right->right->data);
    }
    printf("\n");
}

int main() {
    struct TreeNode* root = NULL;
    int vals[] = {50,30,70,20,40,60,80};
    for(int i=0;i<7;i++) root=insert(root,vals[i]);
    find_grandchildren(root, 50);  /* should print 20 40 60 80 */
    return 0;
}