//石子游戏
//dp[i][j].first表示对于piles[i...j]这部分石头堆，先手能获得的最高分数
//dp[i][j].second表示对于piles[i...j]这部分石头堆，后手能获得的最高分数
//我们想求的答案是先手的最优得分和后手的最优得分之差，也就是dp[0][n-1].first-dp[0][n-1].second
//状态：开始的索引i，结束的索引j，当前轮到的人
//对于每个状态，可以做的选择有两个：选择最左边的那堆石头或者选择最右边的那堆石头
//dp[i][j].first = max(piles[i] + dp[i+1][j].second, piles[j] + dp[i][j-1].second)
//dp[i][j].first = max(选择最左边的石头堆,选择最右边的石头堆)
//解释：我作为先手，面对 piles[i...j] 时，有两种选择：
//要么我选择最左边的那一堆石头，然后面对 piles[i+1...j],但是此时轮到对方，相当于我变成了后手；
//要么我选择最右边的那一堆石头，然后面对 piles[i...j-1],但是此时轮到对方，相当于我变成了后手。
//if 先手选择左边:dp[i][j].second = dp[i+1][j].first
//if 先手选择右边:dp[i][j].second = dp[i][j-1].first
class Solution {
public:
	bool stoneGame(vector<int>& piles)
	{
		int n = piles.size();
		vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));
		//base case
		for (int i = 0; i < n; ++i)
		{
			dp[i][i].first = piles[i];
			dp[i][i].second = 0;
		}
		for (int i = n - 2; i >= 0; --i)//从下到上从左到右进行遍历
		{
			for (int j = i + 1; j < n; ++j)
			{
				//先手选择左边的分数或先手选择右边的分数
				int left = piles[i] + dp[i + 1][j].second;
				int right = piles[j] + dp[i][j - 1].second;
				if (left > right)
				{
					dp[i][j].first = left;
					dp[i][j].second = dp[i + 1][j].first;
				}
				else
				{
					dp[i][j].first = right;
					dp[i][j].second = dp[i][j - 1].first;
				}
			}
		}
		return dp[0][n - 1].first > dp[0][n - 1].second;
	}
};


/*
//优化
class Solution {
public:
bool stoneGame(vector<int>& piles)
{
int n = piles.size();
vector<pair<int, int>> dp(n);
//base case
for (int i = 0; i < n; ++i)
{
dp[i].first = piles[i];
dp[i].second = 0;
}
for (int i = n-2; i >= 0; --i)//从下到上从左到右进行遍历
{
for (int j = i+1; j < n; ++j)
{
//先手选择左边的分数或先手选择右边的分数
int left = piles[i] + dp[j].second;
int right = piles[j] + dp[j-1].second;
if (left > right)
{
dp[j].second = dp[j].first;
dp[j].first = left;
}
else
{
dp[j].first = right;
dp[j].second = dp[j-1].first;
}
}
}
return dp[n-1].first > dp[n-1].second;
}
};
*/