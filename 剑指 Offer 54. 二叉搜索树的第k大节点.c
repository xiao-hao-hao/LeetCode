//剑指 Offer 54. 二叉搜索树的第k大节点
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
class Solution {
public:
    void kthLargestHelper(TreeNode* root, int k, int &count, TreeNode* &result)
    {
        if (root==nullptr || count==k)
            return;
        kthLargestHelper(root->right, k, count, result);
        if (count == k) return;
        ++count;
        if (count == k)
            result = root;
        kthLargestHelper(root->left, k, count, result);
    }
    int kthLargest(TreeNode* root, int k)
    {
        if (root==nullptr || k<=0)
            return 0;
        int count = 0;
        TreeNode *result = nullptr;
        kthLargestHelper(root, k, count, result);
        return result->val;
    }
};
*/

class Solution {
public:
    int kthLargest(TreeNode* root, int k)
    {
        if (root==nullptr || k<=0)
            return 0;
        stack<TreeNode*> st;
        TreeNode *node = root;
        do
        {
            while (node != nullptr)
            {
                st.push(node);
                node = node->right;
            }
            if (!st.empty())
            {
                node = st.top();
                st.pop();
                --k;
                if (k == 0)
                    return node->val;
                node = node->left;
            }
        } while (node!=nullptr || !st.empty());
        return 0;
    }
};










