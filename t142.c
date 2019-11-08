#if 0
#define _CRT_SECURE_NO_WARNINGS 1
//环形列表二
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *MeetPoint(struct ListNode *head)
{
    if(head == NULL)
        return NULL;
    struct ListNode *low = head;
    struct ListNode *fast = head;
    do
    {
        if(fast != NULL && fast->next != NULL)
            fast = fast->next->next;
        else
            return NULL;
        low = low->next;
    } while(low != fast);
    return low;
}

struct ListNode *detectCycle(struct ListNode *head)
{
    struct ListNode *p = MeetPoint(head);
    if(p == NULL)
        return NULL;
    struct ListNode *ret = head;
    while(ret != p)
    {
        ret = ret->next;
        p = p->next;
    }
    return ret;
}
#endif