#if 0
#define _CRT_SECURE_NO_WARNINGS 1

//203. 移除链表元素
//删除链表中等于给定值 val 的所有节点。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *p = NULL;
    struct ListNode *prev = NULL;
    while(head != NULL && head->val == val)
    {
        p = head->next;
        free(head);
        head = p;
    }
    prev = head;
    while(prev != NULL && prev->next != NULL)
    {
        if(prev->next->val == val)
        {
            p = prev->next;
            prev->next = p->next;
            free(p);
            p = NULL;
            
        }
        else
            prev = prev->next;
    }
    return head;
}
*/

struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode *p = head;
    struct ListNode *prev = NULL;
    while(p != NULL)
    {
        if(p->val == val)
        {
            if(prev == NULL)
                head = head->next;
            else
                prev->next = p->next;
            free(p);
            if(prev != NULL)
                p = prev->next;
            else
                p = head;
        }
        else
        {
            prev = p;
            p = prev->next;
        }
        
    }
    return head;
}
#endif