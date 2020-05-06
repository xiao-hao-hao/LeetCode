//最大正方形

//dp[i][j]表示以matrix[i][j]为右下角的最大正方形边长
/*
class Solution {
public:
int maximalSquare(vector<vector<char>>& matrix)
{
if (matrix.empty() || matrix[0].empty())
return 0;
int m = matrix.size();
int n = matrix[0].size();
int maxLen = 0;
//相当于初始化第一行第一列为0
vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
for (int i = 1; i <= m; ++i)
{
for (int j = 1; j <= n; ++j)
{
if (matrix[i-1][j-1] == '1')
dp[i][j] = Min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
else
dp[i][j] = 0;
maxLen = max(maxLen, dp[i][j]);
}
}
return maxLen * maxLen;
}
int Min(int a, int b, int c)
{
return min(min(a, b), c);
}
};
*/

class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix)
	{
		if (matrix.empty() || matrix[0].empty())
			return 0;
		int m = matrix.size();
		int n = matrix[0].size();
		int maxLen = 0;
		//相当于初始化第一行第一列为0
		vector<int> dp(n + 1, 0);
		for (int i = 1; i <= m; ++i)
		{
			int pre = dp[0];
			for (int j = 1; j <= n; ++j)
			{
				int temp = dp[j];
				if (matrix[i - 1][j - 1] == '1')
					dp[j] = Min(dp[j], dp[j - 1], pre) + 1;
				else
					dp[j] = 0;
				maxLen = max(maxLen, dp[j]);
				pre = temp;
			}
		}
		return maxLen * maxLen;
	}
	int Min(int a, int b, int c)
	{
		return min(min(a, b), c);
	}
};


