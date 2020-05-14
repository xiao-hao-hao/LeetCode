//戳气球

//dp[i][j]=x表示戳破请求i和气球j之间(开区间，不包括i和j)的
//所有气球，可以获得的最高分数为x，题目要求的结果就是dp[0][n+1]的值
//base case就是dp[i][j]=0(0<=i<=n+1,j<=i+1),因为这种情况下开区间
//(i,j)中间根本没有气球可以戳
//对于状态转移方程，求dp[i][j]我们会用到dp[i][k]和dp[k][j]，也就是dp[i][j]
//左边的和下边的dp,因此遍历方法为从下到上，从左到右，并且dp[i][k]和dp[k][j]两个问题相互独立
//理解：气球i和j之间的所有气球都是有可能最后被戳破的，假设最后一个被戳破的气球为k，
//i和j就是两个状态，最后戳破的气球就是选择，要想把气球k最后戳破，就得先把(i,k)和
//(k,j)的气球全部戳破，最后剩下气球k。那么，对于一组给定的i和j，我们只要穷举i<k<j的
//所有气球k，选择最高的作为dp[i][j]的值即可
class Solution {
public:
	int maxCoins(vector<int>& nums)
	{
		int n = nums.size();
		//添加两侧的虚拟气球
		vector<int> points(n + 2, 1);
		for (int i = 1; i <= n; ++i)
		{
			points[i] = nums[i - 1];
		}
		//base case为0
		vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
		for (int i = n; i >= 0; --i)
		{
			for (int j = i + 1; j < n + 2; ++j)
			{
				for (int k = i + 1; k < j; ++k)//最后戳破的气球是哪个,对于i和j相邻的情况，此循环不执行
				{
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + points[i] * points[j] * points[k]);
				}
			}
		}
		return dp[0][n + 1];
	}
};