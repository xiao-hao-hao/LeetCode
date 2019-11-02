#if 0
#define _CRT_SECURE_NO_WARNINGS 1
//另一个数的子数
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    if(p == NULL && q == NULL)
        return true;
    if(p == NULL || q == NULL)
        return false;
    return p->val == q->val 
        && isSameTree(p->left, q->left) 
        && isSameTree(p->right, q->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t)
{
    if(isSameTree(s, t))
        return true;
    if(s == NULL)
        return false;
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}
#endif