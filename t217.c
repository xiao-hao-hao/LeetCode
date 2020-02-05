//217. 存在重复元素
//给定一个整数数组，判断是否存在重复元素。
//如果任何值在数组中出现至少两次，函数返回 true。
//如果数组中每个元素都不相同，则返回 false。

#include <algorithm>
class Solution {
public:
	bool containsDuplicate(vector<int>& nums)
	{
		if (nums.capacity() == 0)
			return false;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.capacity() - 1; ++i)
		{
			if (nums[i] == nums[i + 1])
				return true;
		}
		return false;
	}
};