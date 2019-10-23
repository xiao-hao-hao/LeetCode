#if 0
#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//方法1
/*
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *p = head;
    int count = 0;
    while(p->next != NULL)
    {
        ++count;
        p = p->next;
    }
    count = count/2 + count%2;
    p = head;
    while(count--)
        p = p->next;
    return p;
}
*/

//方法2
struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *p1 = head;
    struct ListNode *p2 = head;
    if(p1->next)
    {
        while(p2 != NULL && p2->next != NULL)
        {
            p2 = p2->next->next;
            p1 = p1->next;
        }        
    }
    return p1;
}

#endif