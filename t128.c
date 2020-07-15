//128. 最长连续序列

/*
class Solution {
public:
int longestConsecutive(vector<int>& nums)
{
if (nums.empty())
return 0;
sort(nums.begin(), nums.end());
int n = nums.size();
int maxLen = 0, cur = 1;
for (int i = 1; i < n; ++i)
{
if (nums[i] != nums[i-1])
{
if (nums[i-1]+1 == nums[i])
{
++cur;
}
else
{
maxLen = max(cur, maxLen);
cur = 1;
}
}
}
return max(cur, maxLen);
}
};
*/


class Solution {
public:
	int longestConsecutive(vector<int>& nums)
	{
		unordered_map <int, int> mp;
		int left, right, res = 0, len;
		for (int num : nums)
		{
			if (!mp[num])
			{
				left = mp[num - 1];
				right = mp[num + 1];
				len = left + right + 1;
				if (res < len) res = len;
				mp[num] = len;
				mp[num - left] = len;//只需要把左右边缘改变即可
				mp[num + right] = len;
			}
		}
		return res;
	}
};