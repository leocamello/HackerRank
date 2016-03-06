/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

#include <algorithm>

using namespace std;

int height(node *root) {
    int height = -1;
    if (root != NULL) {
        height = root->ht;
    }
    return height;
}

void update_height(node *root) {
    if (root != NULL) {
        root->ht = max(height(root->left), height(root->right)) + 1;
    }
}

int balance_factor(node *root) {
    int balance_factor = 0;
    if (root != NULL) {
        balance_factor = height(root->left) - height(root->right);
    }
    return balance_factor;
}

void fix_left(node *root) {

}

node* rotate_left(node *root) {
    node *old_root = root;
    root = old_root->right;
    old_root->right = root->left;
    root->left = old_root;
    update_height(root->left);
    update_height(root->right);
    update_height(root);
    return root;
}

node* rotate_right(node *root) {
    node *old_root = root;
    root = old_root->left;
    old_root->left = root->right;
    root->right = old_root;
    update_height(root->left);
    update_height(root->right);
    update_height(root);
    return root;
}

node* rotate(node *root) {
    if (balance_factor(root) < -1) {
        return rotate_left(root);
    } else if (balance_factor(root) > 1) {
        return rotate_right(root);
    } else {
        return root;
    }
}

node* insert(node *root, int val) {
    if (root != NULL) {
        if (val != root->val) {
            if (val < root->val) {
                root->left = insert(root->left, val);
            } else {
                root->right = insert(root->right, val);
            }
            update_height(root);
            return rotate(root);
        } else {
            return root;
        }
    } else {
        root = new node();
        root->right = NULL;
        root->left = NULL;
        root->val = val;
        return root;
    }
}
