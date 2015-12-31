/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/

int FindMergeNode(Node *headA, Node *headB, Node *tempA, Node *tempB)
{
    if (tempA != tempB)
    {
        if (tempA->next == NULL && tempB == NULL)
        {
            return FindMergeNode(headA, headB, headB, headA);
        }
        else if (tempA->next == NULL)
        {
            return FindMergeNode(headA, headB, headB, tempB->next);
        }
        else if (tempB->next == NULL)
        {
            return FindMergeNode(headA, headB, tempA->next, headA);
        }
        else
        {
            return FindMergeNode(headA, headB, tempA->next, tempB->next);
        }
    }
    else
    {
        return tempA->data;
    }
}

int FindMergeNode(Node *headA, Node *headB)
{
    return FindMergeNode(headA, headB, headA, headB);
}
