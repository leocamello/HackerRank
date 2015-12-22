/*
  Reverse a linked list and return pointer to the head
  The input list will have at least one element
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node* Reverse(Node *head, Node* previous)
{
    if (head->next == NULL) {
        head->next = previous;
        return head;
    } else {
        Node *node = Reverse(head->next, head);
        head->next = previous;
        return node;
    }
}

Node* Reverse(Node *head)
{
    return Reverse(head, NULL);
}
