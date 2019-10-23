#if 0
#define _CRT_SECURE_NO_WARNINGS 1

//21. �ϲ�������������
/*��������������ϲ�Ϊһ���µ������������ء�
��������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�*/ 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int list_len(struct ListNode *pl)
{
    int count = 0;
    while(pl != NULL)
    {
        ++count;
        pl = pl->next;
    }
    return count;
}

struct ListNode* Buynode(int val)
{
    struct ListNode *s = (struct ListNode*)malloc(sizeof(struct ListNode));
    s->val = val;
    s->next = NULL;
    return s;
}

void PushBack(struct ListNode *plast, int val)
{
    struct ListNode *p = Buynode(val);
    plast->next = p;
}
    
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    int l1_len = list_len(l1);
    int l2_len = list_len(l1);
    struct ListNode *l3 = NULL;
    struct ListNode *plast = NULL;
    while(l1 && l2)
    {
        if(l1->val < l2->val)
        {
            if(l3 == NULL)
            {
                l3 = Buynode(l1->val);
                plast = l3;
                l1 = l1->next;
            }
            else
            {
                PushBack(plast, l1->val);
                l1 = l1->next;
                plast = plast->next; 
            }
        }
        else
        {
            if(l3 == NULL)
            {
                l3 = Buynode(l2->val);
                plast = l3;
                l2 = l2->next;
            }
            else
            {
                PushBack(plast, l2->val);
                l2 = l2->next;
                plast = plast->next; 
            }
        }
    }
    if(l1 != NULL)
    {
        while(l1 != NULL)
        {
            if(l3 == NULL)
            {
                l3 = Buynode(l1->val);
                plast = l3;
                l1 = l1->next;
            }
            else
            {
                PushBack(plast, l1->val);
                l1 = l1->next;
                plast = plast->next; 
            }
        }
            
    }
    
    if(l2 != NULL)
    {
        while(l2 != NULL)
        {
            if(l3 == NULL)
            {
                l3 = Buynode(l2->val);
                plast = l3;
                l2 = l2->next;
            }
            else
            {
                PushBack(plast, l2->val);
                l2 = l2->next;
                plast = plast->next; 
            }
        }
    }
    return l3;
}
#endif