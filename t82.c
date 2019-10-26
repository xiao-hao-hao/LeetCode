#if 0
//82. 删除排序链表中的重复元素 II
#define _CRT_SECURE_NO_WARNINGS 1

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct NodeTag
{
    int val;
    int num;
}NodeTag;

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    struct ListNode *p = NULL;
    struct ListNode *ptag = NULL;
    struct ListNode *NewHead = NULL;
    struct ListNode *NewTail = NULL;
    NodeTag NT;
    while(head != NULL)
    {
        NT.val = head->val;
        NT.num = 1;
        p = head;
        while(p->next != NULL)
        {
            if(p->next->val == NT.val)
            {
                ptag = p->next;
                p->next = ptag->next; 
                free(ptag);
                ptag = NULL;
                ++(NT.num);
            }
            else
                p = p->next;
        }
        if(NT.num == 1)
        {
            if(NewHead == NULL)
                NewHead = head;
            else
                NewTail->next = head;
            NewTail = head;
            head = head->next;
            NewTail->next = NULL;
        }
        else
        {
            ptag = head;
            head = head->next;
            free(ptag);
            ptag = NULL;
        }
    }
    head = NewHead;
    return head;
}
#endif