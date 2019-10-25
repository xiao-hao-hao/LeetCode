#if 0
//86.·Ö¸îÁ´±í
#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* partition(struct ListNode* head, int x)
{
    struct ListNode *pleft = NULL;
    struct ListNode *pright = NULL;
    struct ListNode *left_end = NULL;
    struct ListNode *right_end = NULL;
    struct ListNode *p = head;
    while(p != NULL)
    {
        if(head != NULL)
            head = head->next;
        p->next = NULL;
        if(p->val < x)
        {
            if(pleft == NULL) 
            {
                pleft = p;
                left_end = p;
            }
            else
            {
                left_end->next = p;
                left_end = p;
            }
        }
        else
        {
            if(pright == NULL) 
            {
                pright = p;
                right_end = p;
            }
            else
            {
                right_end->next = p;
                right_end = p;
            }
        }
        p = head;
    }
    if(left_end != NULL)
    {
        left_end->next = pright;
        head = pleft;
    }
    else
        head = pright;
    return head;
}
#endif