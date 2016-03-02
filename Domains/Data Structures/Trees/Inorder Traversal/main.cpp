/* you only have to complete the function given below.
Node is defined as

struct node
{
    int data;
    node* left;
    node* right;
};

*/

#include <iostream>

using namespace std;

// Recursive approach
void Inorder(node *root) {
    if (root != NULL) {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}

#include <stack>

// Iterative approach
void Inorder(node *root) {
    stack<node*> s;
    node* current = root;
    do {
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }
        if (current == NULL && !s.empty()) {
            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;
        }
    } while (current != NULL || !s.empty());
}
