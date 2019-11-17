#if 0
#define _CRT_SECURE_NO_WARNINGS 1
//606. 根据二叉树创建字符串
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

char buf[10];

void _tree2str(struct TreeNode *t, char *ar, int *i)
{
    if(t == NULL)
        return;
    sprintf(buf, "%d", t->val);
    strcat(ar, buf);
    if(t->left==NULL && t->right==NULL)
    {
        return;
    }
    else if(t->left!=NULL && t->right==NULL)
    {
        strcat(ar, "(");
        _tree2str(t->left, ar, i);
        strcat(ar, ")");
    }
    else if(t->left==NULL && t->right!=NULL)
    {
        strcat(ar, "()(");
        _tree2str(t->right, ar, i);
        strcat(ar, ")");
    }
    else
    {
        strcat(ar, "(");
        _tree2str(t->left, ar, i);
        strcat(ar, ")(");
        _tree2str(t->right, ar, i);
        strcat(ar, ")");
    }
}

char * tree2str(struct TreeNode* t)
{
    int i = 0;
    char *ar = (char*)calloc(sizeof(char), 100000);
    _tree2str(t, ar, &i);
    return ar;
}
#endif