/*
  Print elements of a linked list on console
  head pointer input could be NULL as well for empty list
  Node is defined as
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
#include <iostream>

using namespace std;

void Print(Node *head)
{
    if (head != NULL) {
        cout << head->data << endl;
        Print(head->next);
    }
}
