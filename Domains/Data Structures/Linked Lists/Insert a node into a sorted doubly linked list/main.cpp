/*
    Insert Node in a doubly sorted linked list
    After each insertion, the list should be sorted
    Node is defined as
    struct Node
    {
      int data;
      Node *next;
      Node *prev;
    }
*/

Node* CreateNode(int data, Node *prev, Node *next)
{
    Node *node = new Node();
    node->data = data;
    node->prev = prev;
    node->next = next;
    return node;
}

Node* SortedInsert(Node *head,int data)
{
    if (head == NULL) {
        return CreateNode(data, NULL, NULL);
    } else {
        if (head->data < data) {
            if (head->next == NULL) {
                head->next = CreateNode(data, head, NULL);
            } else {
                if (head->next->data < data) {
                    head->next = SortedInsert(head->next, data);
                } else {
                    head->next = CreateNode(data, head, head->next);
                }
            }
            return head;
        } else {
            head->prev = CreateNode(data, NULL, head);
            return head->prev;
        }
    }
}
