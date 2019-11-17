#if 0
#define _CRT_SECURE_NO_WARNINGS 1
//102. 二叉树的层次遍历.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int Height(struct TreeNode* root)
{
    if(root == NULL)
        return 0;
    else
    {
        int left_h = Height(root->left);
        int right_h = Height(root->right);
        return (left_h>right_h ? left_h : right_h) + 1;
    }
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    *returnSize = Height(root);
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));//用来记录每一行元素个数
    int **levelArray = (int**)malloc(sizeof(int*) * (*returnSize));
    struct TreeNode *q1[1000], *q2[1000];
    int q1_size = 0, q2_size = 0;
    q1[0] = root;
    ++q1_size;
    int level = 0;
    while(level < (*returnSize))
    {
        levelArray[level] = (int*)malloc(sizeof(int) * q1_size);
        for(int i = 0; i < q1_size; ++i)
        {
            levelArray[level][i] = q1[i]->val;
        }
        (*returnColumnSizes)[level] = q1_size;
        for(int i = 0; i < q1_size; ++i)
        {
            if(q1[i]->left != NULL)
                q2[q2_size++] = q1[i]->left;
            if(q1[i]->right != NULL)
                q2[q2_size++] = q1[i]->right;
        }
        memcpy(q1, q2, sizeof(struct Node*) * q2_size);
        q1_size = q2_size;
        q2_size = 0;
        ++level;
    }
    return levelArray;
}




#endif