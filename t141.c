#if 0
#define _CRT_SECURE_NO_WARNINGS 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head)
{
    if(head == NULL)
        return false;
    struct ListNode *low = head;
    struct ListNode *fast = head;
    do
    {
        if(fast != NULL && fast->next != NULL)
            fast = fast->next->next;
        else
            return false;
        low = low->next;
    } while(low != fast);
    return true;
}
#endif