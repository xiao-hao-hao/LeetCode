#if 0
#define _CRT_SECURE_NO_WARNINGS 1
//¶þ²æÊ÷ºóÐò±éÀú
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

void _postorderTraversal(int *ar, struct TreeNode* root, int *returnSize)
{
    if(root != NULL)
    {
        _postorderTraversal(ar, root->left, returnSize);
        _postorderTraversal(ar, root->right, returnSize);
        ar[*returnSize] = root->val;
        ++(*returnSize);
    }
}


int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    int sz = TreeSize(root);
    *returnSize = 0;
    int *ar = (int*)malloc(sizeof(int) * sz);
    _postorderTraversal(ar, root, returnSize);
    return ar;
}
#endif