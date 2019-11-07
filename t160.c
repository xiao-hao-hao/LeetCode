#if 0
#define _CRT_SECURE_NO_WARNINGS 1
//相交链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//本题是指地址相同的节点
/*
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    struct ListNode *PA = headA;
    struct ListNode *PB = headB;
    while(PA != NULL)
    {
        PB = headB;
        while(PB != NULL)
        {
            if(PA == PB)
                return PB;
            PB = PB->next;
        }
        PA = PA->next;
    }
    return NULL;//时间复杂度mxn
}
*/


struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    struct ListNode *PA = headA;
    struct ListNode *PB = headB;
    struct ListNode *P = headA;
    int tag = 1;
    while(PA != PB)
    {
        if(PA != NULL)
            PA = PA->next;
        else
            PA = headB;
        if(PB != NULL)
            PB = PB->next;
        else
            PB = headA;
        if(PA == PB && PA == NULL)
            return NULL;
    }
    return PA;
}

#endif