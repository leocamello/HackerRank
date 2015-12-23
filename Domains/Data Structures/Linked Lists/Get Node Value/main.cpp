/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

int GetNode(Node *head, int *positionFromTail)
{
    int value = -1;

    if (head->next != NULL) {
        value = GetNode(head->next, positionFromTail);
        (*positionFromTail)--;
    }

    if ((*positionFromTail) == 0) {
        value = head->data;
    }

    return value;
}

int GetNode(Node *head, int positionFromTail)
{
    return GetNode(head, &positionFromTail);
}
