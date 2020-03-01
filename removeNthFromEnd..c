/*Remove Nth Node From End of List
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
*/

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* fast = head;
    while (n-- > 0) 
    {
        fast = fast->next;
    }
    if (fast == NULL) 
    {
        return head->next;
    }
    struct ListNode* slow = head;
    while (fast->next != NULL) 
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}
