/*
  Detect loop in a linked list
  List could be empty also
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

int HasCycle(Node *tortoise, Node *hare)
{
    if (tortoise == NULL || hare == NULL || hare->next == NULL) {
        return 0;
    } else if (tortoise == hare) {
        return 1;
    } else {
        return HasCycle(tortoise->next, hare->next->next);
    }
}

int HasCycle(Node* head)
{
    if (head == NULL) {
        return 0;
    } else {
        return HasCycle(head, head->next);
    }
}
