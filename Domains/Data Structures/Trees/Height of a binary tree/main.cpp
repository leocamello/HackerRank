/*The tree node has data, left child and right child
struct node
{
    int data;
    node* left;
    node* right;
};

*/

#include <algorithm>

using namespace std;

int height(node * root)
{
    if (root == NULL) {
        return 0;
    } else {
        return 1 + max(height(root->left), height(root->right));
    }
}
