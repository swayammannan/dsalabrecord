#include <stdio.h>
#include <stdlib.h>

struct TreeNode { int data; struct TreeNode* left; struct TreeNode* right; };

struct TreeNode* newNode(int d) {
    struct TreeNode* n = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    n->data=d; n->left=n->right=NULL; return n;
}
struct TreeNode* insert(struct TreeNode* r, int d) {
    if(!r) return newNode(d);
    if(d < r->data) r->left  = insert(r->left, d);
    else            r->right = insert(r->right,d);
    return r;
}

/* Find LCA */
struct TreeNode* find_lca(struct TreeNode* root, int n1, int n2) {
    if (root == NULL) return NULL;
    /* Both smaller → go left */
    if (n1 < root->data && n2 < root->data)
        return find_lca(root->left, n1, n2);
    /* Both larger → go right */
    if (n1 > root->data && n2 > root->data)
        return find_lca(root->right, n1, n2);
    /* Otherwise, this node is the LCA */
    return root;
}

int main() {
    struct TreeNode* root = NULL;
    int vals[] = {50,30,70,20,40,60,80};
    for(int i=0;i<7;i++) root = insert(root,vals[i]);

    struct TreeNode* lca = find_lca(root, 20, 40);
    printf("LCA of 20 and 40: %d\n", lca->data);  /* should be 30 */

    lca = find_lca(root, 20, 80);
    printf("LCA of 20 and 80: %d\n", lca->data);  /* should be 50 */
    return 0;
}