/*Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5    */

struct ListNode* partition(struct ListNode* head, int x){
    struct ListNode* pList1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* pList2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* before = pList1;
    struct ListNode* after = pList2;
    while(head)
    {
        if(head->val < x)
        {
            before->next = head;
            before = before->next;
        }
        else
        {
            after->next = head;
            after = after->next;
        }
        head = head->next;
    }
    after->next = NULL;
    before->next = pList2->next;
    return pList1->next;
}
