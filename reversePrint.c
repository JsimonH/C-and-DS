/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
输入：head = [1,3,2]
输出：[2,3,1]
*/

int* reversePrint(struct ListNode* head, int* returnSize){
    if(head == NULL)
    {
        *returnSize = 0;
        return 0;
    }
    struct ListNode* tmp; 
    struct ListNode* header = head;
    int len = 1,i;
    
    while(head->next != NULL)
    {
        len++;
        tmp = head->next;
        head->next = tmp->next;
        tmp->next = header;
        header = tmp;
    }
    *returnSize = len;
    int *res = malloc(sizeof(int)*len);
    for(i=0; i<len; i++)
    {
        res[i] = header->val;
        header = header->next;
    }
    return res;
}
