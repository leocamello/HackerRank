/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node* RemoveDuplicates(Node *head)
{
    if (head->next != NULL) {
        Node *next = head->next;
        if (next->data == head->data) {
            head->next = next->next;
            delete next;
            RemoveDuplicates(head);
        } else {
            RemoveDuplicates(next);
        }
    }

    return head;
}
