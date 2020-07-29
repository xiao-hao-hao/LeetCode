//剑指 Offer 45. 把数组排成最小的数
class Solution {
public:
    string minNumber(vector<int>& nums)
    {
        vector<string> strs;
        string res;
        for (int i = 0; i < nums.size(); ++i)
        {
            strs.push_back(to_string(nums[i]));
        }
        sort(strs.begin(), strs.end(), [](string &s1, string &s2)->bool{return s1+s2 < s2+s1;});
        for (int i = 0; i < strs.size(); ++i)
            res += strs[i];
        return res;
    }
};