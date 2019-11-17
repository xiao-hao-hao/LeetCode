#if 0
#define _CRT_SECURE_NO_WARNINGS 1
//236. 二叉树的最近公共祖先
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool findNode(struct TreeNode *root, struct TreeNode *n)
{
    if(root == NULL)
        return false;
    if(root->val == n->val)
        return true;
    else
        return findNode(root->left, n) || findNode(root->right, n);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q)
{
    if(p == root || q == root)
        return root;
    bool pInleft, pInright, qInleft, qInright;
    if(findNode(root->left, p))
    {
        pInleft = true;
        pInright = false;
    }
    else
    {
        pInleft = false;
        pInright = true;
    }
    if(findNode(root->left, q))
    {
        qInleft = true;
        qInright = false; 
    }
    else
    {
        qInleft = false;
        qInright = true;
    }
    if(pInleft && qInleft)
        return lowestCommonAncestor(root->left, p, q);
    else if(pInright && qInright)
        return lowestCommonAncestor(root->right, p, q);
    return root;
}



#endif