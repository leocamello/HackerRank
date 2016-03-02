/*
Node is defined as

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

*/

#include <algorithm>

node* lca(node *root, int v1, int v2) {
    int min = std::min(v1, v2);
    int max = std::max(v1, v2);
    if (root != NULL) {
        if (root->data < min && root->data < max) {
            return lca(root->right, v1, v2);
        } else if (root->data > min && root->data > max) {
            return lca(root->left, v1, v2);
        } else {
            return root;
        }
    } else {
        return NULL;
    }
}
