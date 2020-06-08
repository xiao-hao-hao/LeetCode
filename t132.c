//132. �ָ���Ĵ� II

/*
//dp[i]��ʾǰi+1���ַ���ɵ��ַ���������Ҫ�ָ�β��ܱ�ɶ��ǻ��Ĵ�
//״̬ת�ƣ��������е�j<i�����s[j+1,i]�ǻ��Ĵ�,��dp[j]+1<dp[i]��dp[i]=dp[j]+1
//��ʼ��:dp[i]=i ,����Ϊi+1���Ӵ�,�����i�Σ�����ɵ����ַ������ǻ��Ĵ���
//����ֵdp[len]
class Solution {
public:
int minCut(string s)
{
int len = s.size();
vector<int> dp(len);
//��ʼ��Ϊÿ����������ָ����
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
//��ʼ��Ϊÿ����������ָ����
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
//dp[i]��ʾǰi+1���ַ���ɵ��ַ���������Ҫ�ָ�β��ܱ�ɶ��ǻ��Ĵ�
class Solution {
public:
	int minCut(string s)
	{
		int len = s.size();
		vector<int> dp(len);
		isFunc(s);
		//��ʼ��Ϊÿ����������ָ����
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