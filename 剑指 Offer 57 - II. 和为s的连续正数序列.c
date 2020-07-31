//剑指 Offer 57 - II. 和为s的连续正数序列
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        int left = 1;
        int right = 2;
        vector<vector<int>> result;
        while (left < right)
        {
            int sum = (left+right)*(right-left+1)/2;
            if (sum == target)
            {
                vector<int> v;
                for (int i = left; i <= right; ++i)
                {
                    v.push_back(i);
                }
                result.push_back(v);
                ++left;
            }
            else if (sum < target)
            {
                ++right;
            }
            else
            {
                ++left;
            }
        }
        return result;
    }
};