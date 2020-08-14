//102. 二叉树的层序遍历
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
            return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> temp;
            int n = q.size();
            while (n)
            {
                temp.push_back(q.front()->val);
                if (q.front()->left != nullptr)
                    q.push(q.front()->left);
                if (q.front()->right != nullptr)
                    q.push(q.front()->right);
                q.pop();   
                --n;
            }
            result.push_back(temp);
        }
        return result;
    }
};