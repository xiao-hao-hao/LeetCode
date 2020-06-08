//132. 分割回文串 II

/*
//dp[i]表示前i+1个字符组成的字符串最少需要分割几次才能变成都是回文串
//状态转移：对于所有的j<i，如果s[j+1,i]是回文串,且dp[j]+1<dp[i]则dp[i]=dp[j]+1
//初始化:dp[i]=i ,长度为i+1的子串,最多切i次，都变成单个字符，就是回文串了
//返回值dp[len]
class Solution {
public:
int minCut(string s)
{
int len = s.size();
vector<int> dp(len);
//初始化为每种情况的最大分割次数
for (int i = 0; i < len; ++i)
dp[i] = i;
for (int i = 1; i < len; ++i)
{
for (int j = 0; j <= i; ++j)
{
if (j == 0)
{
if (isFunc(s.substr(j, i-j+1)))
{
dp[i] = 0;
continue;
}
}
else if (isFunc(s.substr(j, i-j+1)))
dp[i] = min(dp[i], dp[j-1]+1);
}
}
return dp[len-1];
}
bool isFunc(string s)
{
int left = 0, right = s.size() - 1;
while (left < right)
{
if (s[left] != s[right])
return false;
++left;
--right;
}
return true;
}
};
*/
/*
class Solution {
public:
int minCut(string s)
{
int len = s.size();
vector<int> dp(len);
isFunc(s);
//初始化为每种情况的最大分割次数
for (int i = 0; i < len; ++i)
dp[i] = i;
for (int i = 1; i < len; ++i)
{
for (int j = 0; j <= i; ++j)
{
if (j == 0)
{
if (memo[j][i])
{
dp[i] = 0;
continue;
}
}
else if (memo[j][i])
dp[i] = min(dp[i], dp[j-1]+1);
}
}
return dp[len-1];
}
void isFunc(string &s)
{
int len = s.size();
memo = vector<vector<bool>>(len, vector<bool>(len));
for (int i = 0; i < len; ++i)
{
memo[i][i] = true;
if (s[i] == s[i+1])
memo[i][i+1] = true;
else
memo[i][i+1] = false;
}
for (int i = len-3; i >= 0; --i)
{
for (int j = i+2; j < len; ++j)
memo[i][j] = memo[i+1][j-1] && (s[i] == s[j]);
}
}
private:
vector<vector<bool>> memo;
int len;
};
*/
//dp[i]表示前i+1个字符组成的字符串最少需要分割几次才能变成都是回文串
class Solution {
public:
	int minCut(string s)
	{
		int len = s.size();
		vector<int> dp(len);
		isFunc(s);
		//初始化为每种情况的最大分割次数
		for (int i = 0; i < len; ++i)
			dp[i] = i;
		for (int i = 1; i < len; ++i)
		{
			if (memo[0][i])
			{
				dp[i] = 0;
				continue;
			}
			for (int j = 0; j < i; ++j)
			{
				if (memo[j + 1][i])
					dp[i] = min(dp[i], dp[j] + 1);
			}
		}
		return dp[len - 1];
	}
	void isFunc(string &s)
	{
		int len = s.size();
		memo = vector<vector<bool>>(len, vector<bool>(len));
		for (int i = 0; i < len; ++i)
		{
			memo[i][i] = true;
			if (s[i] == s[i + 1])
				memo[i][i + 1] = true;
			else
				memo[i][i + 1] = false;
		}
		for (int i = len - 3; i >= 0; --i)
		{
			for (int j = i + 2; j < len; ++j)
				memo[i][j] = memo[i + 1][j - 1] && (s[i] == s[j]);
		}
	}
private:
	vector<vector<bool>> memo;
	int len;
};