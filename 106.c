#if 0
#define _CRT_SECURE_NO_WARNINGS 1
//106. 从中序与后序遍历序列构造二叉树
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize)
{
    if(inorderSize == 0)
        return NULL;
    int k = 0;
    while(postorder[postorderSize-1] != inorder[k])
        ++k;
    struct TreeNode *p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p->val = inorder[k];
    p->left = buildTree(inorder, k, postorder, k);
    p->right = buildTree(inorder+k+1, inorderSize-k-1, postorder+k, postorderSize-k-1);
    return p;
}
#endif