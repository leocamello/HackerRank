/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

#include <iostream>

using namespace std;

void top_left_view(node *root) {
    if (root != NULL) {
        top_left_view(root->left);
        cout << root->data << " ";
    }
}

void top_right_view(node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        top_right_view(root->right);
    }
}

void top_view(node * root) {
    if (root != NULL) {
        top_left_view(root->left);
        cout << root->data << " ";
        top_right_view(root->right);
    }
}
