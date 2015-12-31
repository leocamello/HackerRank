/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/

int FindMergeNode(Node *headA, Node *headB, Node *firstB)
{
    if (firstB == NULL) {
        firstB = headB;
    }

    if (headA != NULL && headB != NULL) {
        if (headA == headB) {
            return headA->data;
        } else {
            return FindMergeNode(headA, headB->next, firstB);
        }
    } else if (headB == NULL) {
        return FindMergeNode(headA->next, firstB, firstB);
    } else {
        return -1;
    }
}

int FindMergeNode(Node *headA, Node *headB)
{
    return FindMergeNode(headA, headB, NULL);
}
