//55. 跳跃游戏

//这道题表面不是求最值，但可以改一下
//请问通过题目中的跳跃规则，最多能跳多远
//如果能够越过最后一格返回true，否则返回false
//这种方法所依据的核心特性：如果一个位置能够到达，
//那么这个位置左侧所有位置都能到达。 想到这一点，解法就呼之欲出了
//https://leetcode-cn.com/problems/jump-game/solution/55-by-ikaruga/
class Solution {
public:
	bool canJump(vector<int>& nums)
	{
		int n = nums.size();
		int farthest = 0;
		for (int i = 0; i < n; ++i)
		{
			if (i > farthest)
				return false;
			farthest = max(farthest, i + nums[i]);
		}
		return true;
	}
};