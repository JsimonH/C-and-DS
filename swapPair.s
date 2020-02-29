/*Swap Nodes in Pairs
Given 1->2->3->4, you should return the list as 2->1->4->3.
*/

struct ListNode* swapPairs(struct ListNode* head){
    if ((head == NULL) || (head->next == NULL))
    {
        return head;
    }
    struct ListNode* firstNode = head;
    struct ListNode* secondNode = head->next;

    firstNode->next  = swapPairs(secondNode->next);
    secondNode->next = firstNode;
   
    return secondNode;
}
