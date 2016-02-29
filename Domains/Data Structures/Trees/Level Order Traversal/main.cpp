/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

#include <queue>
#include <iostream>

using namespace std;

void LevelOrder(node * root) {
    queue<node*> q;
    q.push(root);

    node *current;
    while (!q.empty()) {
        current = q.front();
        if (current != NULL) {
            cout << current->data << " ";
            q.push(current->left);
            q.push(current->right);
        }

        q.pop();
    }
}
