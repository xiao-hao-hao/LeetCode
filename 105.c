#if 0
#define _CRT_SECURE_NO_WARNINGS 1

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    if(preorderSize == 0)
        return NULL;
    int k = 0;
    while(preorder[0] != inorder[k])
        ++k;
    struct TreeNode *p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p->val = inorder[k];
    p->left = buildTree(preorder+1, k, inorder, k);
    p->right = buildTree(preorder+k+1, preorderSize-k-1, inorder+k+1, inorderSize-k-1);
    return p;
}

#endif