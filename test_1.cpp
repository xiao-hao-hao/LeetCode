#if 0
#define _CRT_SECURE_NO_WARNINGS 1
//206. 反转链表
////反转一个单链表
//输入: 1->2->3->4->5->NULL
//输出: 5->4->3->2->1->NULL

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//方法1：将链表断开，然后头插
/*
struct ListNode* reverseList(struct ListNode* head){
    if(head && head->next)
    {
        struct ListNode *p1 = head->next;
        struct ListNode *p2 = p1;
        head->next = NULL;
        while(p1 != NULL)
        {
            p2 = p2->next;
            p1->next = head;
            head = p1;
            p1 = p2;
        }        
    }
    return head;
}
*/

//方法2：递归法
struct ListNode* reverseList(struct ListNode* head){
    if(head && head->next)
    {
        struct ListNode *p1 = head;
        struct ListNode *p2 = p1->next;
        head = reverseList(head->next);
        p2->next = p1;
        p1->next = NULL;
    }
    return head;
}

#endif