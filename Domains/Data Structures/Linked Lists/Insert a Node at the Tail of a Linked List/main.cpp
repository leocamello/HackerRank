/*
  Insert Node at the end of a linked list
  head pointer input could be NULL as well for empty list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node* Insert(Node *head,int data)
{
    if (head == NULL) {
        head = new Node();
        head->data = data;
        head->next = NULL;
    } else if (head->next == NULL) {
        Node *node = new Node();
        node->data = data;
        node->next = NULL;
        head->next = node;
    } else {
        Insert(head->next, data);
    }

    return head;
}
