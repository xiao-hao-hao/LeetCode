#if 0
#define _CRT_SECURE_NO_WARNINGS 1
//回文链表
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


//bool isPalindrome(struct ListNode* head)
//{
//    if(head == NULL || head->next == NULL)
//        return true;
//    int i = 0;
//    struct ListNode *slow = head;
//    struct ListNode *fast = head;
//    struct ListNode *pre = NULL;
//    struct ListNode *pre_pre = NULL;
//    while(fast != NULL)
//    {
//        fast = fast->next;
//        ++i;
//        if(fast != NULL)//将左半部分反转
//        {
//            fast = fast->next;
//            ++i;
//            pre_pre = pre;
//            pre = slow;
//            slow = slow->next;
//            pre->next = pre_pre;
//        }
//    }
//    if(i%2 != 0)
//        slow = slow->next;//此时slow是右边链表头指针，pre是左边链表头指针
//    while(slow != NULL)
//    {
//        if(slow->val != pre->val)
//            return false;
//        slow = slow->next;
//        pre = pre->next;
//    }
//    return true;
//}



bool isPalindrome(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return true;
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    struct ListNode *pre = NULL;
    struct ListNode *pre_pre = NULL;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            pre_pre = pre;
            pre = slow;
            slow = slow->next;
            pre->next = pre_pre;
            fast = fast->next;
        }
    }
    if(fast != NULL)
        slow = slow->next;//此时slow是右边链表头指针，pre是左边链表头指针
    while(slow != NULL)
    {
        if(slow->val != pre->val)
            return false;
        slow = slow->next;
        pre = pre->next;
    }
    return true;
}
#endif