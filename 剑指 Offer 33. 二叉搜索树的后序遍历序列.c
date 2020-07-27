//剑指 Offer 33. 二叉搜索树的后序遍历序列
class Solution {
public:
    bool verifyPostorderHelper(vector<int>& postorder, int start, int end)
    {
        if (start >= end)
            return true;
        int root = postorder[end];
        int i = start;
        while (i < end && postorder[i] < root)
        {
            ++i;
        }
        for (int j = i; j < end; ++j)
        {
            if (postorder[j] < root)
                return false;
        }
        return verifyPostorderHelper(postorder, start, i-1) && verifyPostorderHelper(postorder, i, end-1);
    }
    bool verifyPostorder(vector<int>& postorder)
    {
        if (postorder.empty())
            return true;
        return verifyPostorderHelper(postorder, 0, postorder.size()-1);
    }
};