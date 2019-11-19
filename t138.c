#if 0
#define _CRT_SECURE_NO_WARNINGS 1
//138. ���ƴ����ָ�������

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        Node *p1, *p2, *p;
        Node *NewHead = NULL;
        if(head == NULL)
            return NewHead;
        //��ԭ�����ÿ���ڵ�����һ��ֵ��ͬ�Ľڵ�
        p1 = head;
        while(p1 != NULL)
        {
            p = (Node*)malloc(sizeof(Node));
            p->val = p1->val;
            p->random = NULL;
            p->next = p1->next;
            p1->next = p;
            p1 = p->next;
        }

        //���´����Ľڵ��randomָ�븳ֵ
        p1 = head, p2 = p1->next;
        while(p1 != NULL)
        {
            if(p1->random != NULL)
                p2->random = p1->random->next;
            else
                p2->random = NULL;
            p1 = p2->next;
            if(p1 != NULL)
                p2 = p1->next;
        }

        //���¾ɽڵ����
        NewHead = head->next;
        p1 = head, p2 = p1->next;
        while(p1 != NULL)
        {
            p1->next = p2->next;
            p1 = p2->next;
            if(p1 != NULL)
            {
                p2->next = p1->next;
                p2 = p1->next;
            }
        }
        return NewHead;
    }
};






#endif