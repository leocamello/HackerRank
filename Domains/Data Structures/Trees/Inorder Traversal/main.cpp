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

void Inorder(node *root) {
    if (root != NULL) {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}
