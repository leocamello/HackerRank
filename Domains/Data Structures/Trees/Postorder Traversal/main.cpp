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
void Postorder(node *root) {
    if (root != NULL) {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
}

#include <stack>

// Iterative approach
void Postorder(node *root) {
    stack<node*> s1, s2;
    s1.push(root);
    node* current;
    while (!s1.empty()) {
        current = s1.top();
        s1.pop();
        if (current != NULL) {
            s2.push(current);
            s1.push(current->left);
            s1.push(current->right);
        }
    }
    while (!s2.empty()) {
        current = s2.top();
        s2.pop();
        if (current != NULL) {
            cout << current->data << " ";
        }
    }
}
