/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		if (headA == NULL || headB == NULL)
			return NULL;
		ListNode *ptrA = headA;
		ListNode *ptrB = headB;
		while (ptrA != ptrB)
		{
			if (ptrA == NULL)
				ptrA = headB;
			else
				ptrA = ptrA->next;
			if (ptrB == NULL)
				ptrB = headA;
			else
				ptrB = ptrB->next;
		}
		return ptrA;
	}
};


/*
class Solution {
public:
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
if (headA==NULL || headB==NULL)
return NULL;
ListNode *ptrA = headA;
ListNode *ptrB = headB;
while (ptrA != ptrB)
{
ptrA = (ptrA==NULL ? headB : ptrA->next);
ptrB = (ptrB==NULL ? headA : ptrB->next);
}
return ptrA;
}
};
*/

class Solution {
public:
	ListNode* GetListLength(ListNode* pHead, int &length)
	{
		ListNode *end = NULL;
		while (pHead)
		{
			++length;
			end = pHead;
			pHead = pHead->next;
		}
		return end;
	}
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL || pHead2 == NULL)
			return NULL;
		int len1 = 0;
		int len2 = 0;
		ListNode *end1 = GetListLength(pHead1, len1);
		ListNode *end2 = GetListLength(pHead2, len2);
		if (end1 != end2)
			return NULL;
		int step = abs(len1 - len2);
		if (len1 > len2)
		{
			while (step)
			{
				pHead1 = pHead1->next;
				--step;
			}
		}
		else
		{
			while (step)
			{
				pHead2 = pHead2->next;
				--step;
			}
		}
		while (pHead1 != pHead2)
		{
			pHead1 = pHead1->next;
			pHead2 = pHead2->next;
		}
		return pHead1;
	}
};