#if 0
#define _CRT_SECURE_NO_WARNINGS 1
//��������
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
//        if(fast != NULL)//����벿�ַ�ת
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
//        slow = slow->next;//��ʱslow���ұ�����ͷָ�룬pre���������ͷָ��
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
        slow = slow->next;//��ʱslow���ұ�����ͷָ�룬pre���������ͷָ��
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