/*
  Delete Node at a given position in a linked list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

Node* Delete(Node *head, int position)
{
    if (position == 0) {
        Node *next = head->next;
        delete head;
        return next;
    } else {
        head->next = Delete(head->next, --position);
        return head;
    }
}
