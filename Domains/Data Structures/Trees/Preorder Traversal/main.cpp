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
void Preorder(node *root) {
    if (root != NULL) {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

#include <stack>

// Iterative approach
void Preorder(node *root) {
    stack<node*> s;
    s.push(root);
    node* current;
    while (!s.empty()) {
        current = s.top();
        s.pop();
        if (current != NULL) {
            cout << current->data << " ";
            s.push(current->right);
            s.push(current->left);
        }
    }
}
