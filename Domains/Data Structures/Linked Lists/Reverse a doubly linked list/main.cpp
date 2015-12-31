/*
   Reverse a doubly linked list, input list may also be empty
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev;
   }
*/

Node* Reverse(Node* head)
{
    if (head == NULL) {
        return head;
    } else {
        Node *next = head->next;
        head->next = head->prev;
        head->prev = next;

        if (next == NULL) {
            return head;
        } else {
            return Reverse(next);
        }
    }
}
