#if 0
#define _CRT_SECURE_NO_WARNINGS 1
//¶þ²æÊ÷Ç°Ðò±éÀú
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

void _preorderTraversal(int *ar, struct TreeNode* root, int *returnSize)
{
    if(root != NULL)
    {
        ar[*returnSize] = root->val;
        ++(*returnSize);
        _preorderTraversal(ar, root->left, returnSize);
        _preorderTraversal(ar, root->right, returnSize);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    int sz = TreeSize(root);
    *returnSize = 0;
    int *ar = (int*)malloc(sizeof(int) * sz);
    _preorderTraversal(ar, root, returnSize);
    return ar;
}
#endif