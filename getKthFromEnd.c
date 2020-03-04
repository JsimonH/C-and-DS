/*输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。
input: 1->2->3->4->5 and k = 2.
output: 4->5    */

struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    //快慢指针
        struct ListNode* fast = head;
        struct ListNode* slow = head;
        //快指针先移动k步
        for(int i = 0; i < k; i++)
        {
            fast = fast->next;
        }
        //快慢指针一起移动
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
}
