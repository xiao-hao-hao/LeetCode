//剑指 Offer 39. 数组中出现次数超过一半的数字

/*
//当存在这样的数字时，排序后数组中间一定是这个数
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int target = nums[nums.size()/2];
        int count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (target == nums[i])
                ++count;
        }
        if (count > nums.size()/2)
            return target;
        return 0;
    }
};
*/
/*
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        unordered_map<int, int> dict;
        int half = nums.size()/2;
        for (int i = 0; i < nums.size(); ++i)
        {
            ++dict[nums[i]];
            if (dict[nums[i]] > half)
                return nums[i];
        }
        return 0;
    }
};
*/

//如果存在这个数字，那么最后剩下的一定就是
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        if (nums.size() == 0)
            return 0;
        int num = nums[0];
        int times = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (times == 0)
            {
                num = nums[i];
                times = 1;
            }
            else if (num == nums[i])
            {
                ++times;
            }
            else
            {
                --times;
            }
        }
        int count = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == num)
                ++count;
        }
        return count>nums.size()/2 ? num : 0;
    }
};





