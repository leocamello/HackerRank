#include <queue>
#include <stack>
#include <utility>
#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class Tree {
    private:
    Node *root;
    queue<Node*> build_queue;

    public:
    Tree(int root_data) {
        root = new Node(root_data);
        build_queue.push(root);
    }

    void LevelOrderAdd(int left_data, int right_data) {
        Node *curr = build_queue.front();
        if (left_data != -1) {
            curr->left = new Node(left_data);
            build_queue.push(curr->left);
        }
        if (right_data != -1) {
            curr->right = new Node(right_data);
            build_queue.push(curr->right);
        }
        build_queue.pop();
    }

    void InOrderPrint() {
        stack<Node*> s;
        Node* current = root;
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
        cout << endl;
    }

    void SwapOperation(int k) {
        int level = 0;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            level++;
            int nodes = q.size();
            while (nodes--) {
                Node *current = q.front();
                if (current != NULL) {
                    if (level % k == 0) {
                        swap(current->left, current->right);
                    }
                    q.push(current->left);
                    q.push(current->right);
                }
                q.pop();
            }
        }
    }
};

int main() {
    int N;
    cin >> N;

    Tree *t = new Tree(1);

    while (N--) {
        int a, b;
        cin >> a >> b;
        t->LevelOrderAdd(a, b);
    }

    int T;
    cin >> T;

    while (T--) {
        int k;
        cin >> k;
        t->SwapOperation(k);
        t->InOrderPrint();
    }

    return 0;
}
