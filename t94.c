#if 0
#define _CRT_SECURE_NO_WARNINGS 1
//�������������

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int TreeSize(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    return TreeSize(root->left) + TreeSize(root->right) + 1;
}

void _inorderTraversal(int *ar, struct TreeNode* root, int *returnSize)
{
    if(root != NULL)
    {
        _inorderTraversal(ar, root->left, returnSize);
        ar[*returnSize] = root->val;
        ++(*returnSize);
        _inorderTraversal(ar, root->right, returnSize);
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    int sz = TreeSize(root);
    *returnSize = 0;
    int *ar = (int*)malloc(sizeof(int) * sz);
    _inorderTraversal(ar, root, returnSize);
    return ar;
}
#endif