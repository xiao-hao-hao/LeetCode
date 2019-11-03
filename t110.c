#if 0
#define _CRT_SECURE_NO_WARNINGS 1
//平衡二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root)//求二叉树最大深度
{
    if(root == NULL)
        return 0;
    int left_sz = maxDepth(root->left);
    int right_sz = maxDepth(root->right);
    return left_sz > right_sz ? left_sz+1 : right_sz+1;
}

bool isBalanced(struct TreeNode* root)
{
    if(root == NULL)
        return true;
    return abs(maxDepth(root->left)-maxDepth(root->right))<=1 
        && isBalanced(root->left) && isBalanced(root->right);
}
#endif