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

void Postorder(node *root) {
    if (root != NULL) {
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
}
