//45、跳跃游戏2

/*
//自顶向下的递归动态规划
//定义：从索引p跳到最后一格，至少需要dp(nums,p)步
//我们想要的结果就是dp(nums, p)
//base case就是当p超过超过最后一格时不需要跳跃
class Solution {
public:
int jump(vector<int>& nums)
{
int n = nums.size();
//备忘录都初始化为n，相当于INT_MAX
//因为从0跳到n-1最多n-1步
memo = vector<int>(n, n);
return dp(nums, 0);
}
int dp(vector<int>& nums, int p)
{
int n = nums.size();
//base case
if (p >= n - 1)
return 0;
//子问题已经计算过
if (memo[p] != n)
return memo[p];
int steps = nums[p];
//可以选择跳1步、2步...
for (int i = 1; i <= steps; ++i)
{
//穷举每一个选择，计算每一个子问题的结果
int subProblem = dp(nums, p+i);
//获取其中最小的作为最终结果
memo[p] = min(memo[p], subProblem+1);
}
return memo[p];
}
private:
vector<int> memo;
};
*/
/*
//dp[n]表示从索引n跳到最后一格，至少需要dp[n]步
//我们想要的结果就是dp[0]
//base case就是当p超过超过最后一格时不需要跳跃
//dp[nums.size()-1] = 0
class Solution {
public:
int jump(vector<int>& nums)
{
int n = nums.size();
//备忘录都初始化为n，相当于INT_MAX
//因为从0跳到n-1最多n-1步
vector<int> dp(n, n);
dp[n-1] = 0;
for (int i = n-2; i >= 0; --i)
{
int steps = nums[i];
for (int j = 1; j <= steps; ++j)
{
if (i+j == n-1)
dp[i] = 1;
else if (i+j < n-1)
dp[i] = min(dp[i], dp[i+j]+1);
else
break;
}
}
return dp[0];
}
};
*/

//贪心算法
//https://leetcode-cn.com/problems/jump-game-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-10/
//jumps记录了跳跃的次数
//farthest标记了所有可选择跳跃步数[i...end]中能够跳到的最远距离
//end标记了本次跳跃可跳的范围
class Solution {
public:
	int jump(vector<int>& nums)
	{
		int n = nums.size();
		int end = 0, farthest = 0, jumps = 0;
		for (int i = 0; i < n - 1; ++i)
		{
			//找能跳的最远的位置的下标
			farthest = max(nums[i] + i, farthest);
			//遇到边界，就更新边界(说明本次跳完)，并且步数加一
			if (end == i)
			{
				++jumps;
				end = farthest;
			}
		}
		return jumps;
	}
};
