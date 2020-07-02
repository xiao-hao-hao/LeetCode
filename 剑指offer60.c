//剑指 Offer 60. n个骰子的点数
class Solution {
public:
	void dfs(vector<double>& tmp, int n, int sum)
	{
		if (n == 0)
		{
			tmp[sum] += 1;
			return;
		}
		for (int i = 1; i <= 6; ++i)
			dfs(tmp, n - 1, sum + i);
	}
	vector<double> twoSum(int n)
	{
		int count = 0;
		vector<double> tmp(n * 6 + 1, 0);
		dfs(tmp, n, 0);
		int all = pow(6, n);
		vector<double> ret;
		for (int i = n; i < n * 6 + 1; ++i)
			ret.push_back(tmp[i] / all);
		return ret;
	}
};

/*
//dp[i][j]表示投掷完i枚骰子后，点数j的出现次数
class Solution {
public:
vector<double> twoSum(int n)
{
vector<vector<int>> dp(n+1, vector<int>(6*n+1, 0));
for (int i = 1; i <= 6; ++i)
dp[1][i] = 1;
for (int i = 2; i <= n; ++i)
{
for (int j = i; j <= 6*i; ++j)
{
for (int cur = 1; cur <= 6; ++cur)
{
if (j-cur <= 0)
break;
dp[i][j] += dp[i-1][j-cur];
}
}
}
int all = pow(6, n);
vector<double> ret;
for (int i = n; i <= 6*n; ++i)
ret.push_back(dp[n][i]*1.0 / all);
return ret;
}
};
*/
/*
class Solution {
public:
vector<double> twoSum(int n)
{
vector<int> dp(n*6+1, 0);
for (int i = 1; i <= 6; ++i)
dp[i] = 1;
for (int i = 2; i <= n; ++i)
{
for (int j = 6*i; j >= i; --j)
{
dp[j] = 0;//必须置0
for (int cur = 1; cur <= 6; ++cur)
{
if (j-cur < i-1)
break;
dp[j] += dp[j-cur];
}
}
}
int all = pow(6, n);
vector<double> ret;
for (int i = n; i <= 6*n; ++i)
ret.push_back(dp[i]*1.0 / all);
return ret;
}
};
*/