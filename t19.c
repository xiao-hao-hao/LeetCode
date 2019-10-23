#if 0
//19. 删除链表的倒数第N个节点
#define _CRT_SECURE_NO_WARNINGS 1

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode *p = NULL;
    struct ListNode *pfast = head;
    struct ListNode *pslow = head;
    while(pfast != NULL && n >= 0)
    {
        pfast = pfast->next;
        --n;
    }
    if(n == 0)
    {
        p = head->next;
        free(head);
        head = p;
    }
    else
    {
        while(pfast != NULL)
        {
            pfast = pfast->next;
            pslow = pslow->next;
        }
        p = pslow->next->next;
        free(pslow->next);
        pslow->next = p;
    }
    return head;
}
#endif