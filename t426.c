#if 0
#define _CRT_SECURE_NO_WARNINGS 1
//将二叉搜索树转化为排序的双向链表  

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void ConvertList(TreeNode *t, TreeNode **pre)
    {
        if(t == NULL)
            return;
        ConvertList(t->left, pre);
        t->left = *pre;
        if(*pre != NULL)
            (*pre)->right = t;
        *pre = t;
        ConvertList(t->right, pre);
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
            return NULL;
        TreeNode *pre = NULL;
        ConvertList(pRootOfTree, &pre);
        TreeNode *pHead = pre;
        while(pHead->left != NULL)
            pHead = pHead->left;
        return pHead;
    }
};



#endif