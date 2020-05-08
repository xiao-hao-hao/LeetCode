//正则表达式匹配

/*
//递归
class Solution {
public:
bool isMatch(string s, string p)
{
if (p.empty())
return s.empty();
bool first_match = !s.empty() && (p[0]==s[0] || p[0]=='.');//判断第一个字符可不可以匹配
if (p.size()>=2 && p[1]=='*')//处理第二个字符是*的情况
return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
else//处理第二个字符不是*的情况
return first_match && isMatch(s.substr(1), p.substr(1));
}
};
*/

/*
//递归优化
class Solution {
public:
bool isMatch(string s, string p)
{
return isMatch(s.c_str(), p.c_str());
}
bool isMatch(const char *s, const char *p)
{
if (*p == 0)
return *s == 0;
bool first_match = *s && (*s==*p || *p=='.');
if (*(p+1) == '*')
return isMatch(s, p+2) || (first_match && isMatch(++s, p));
else
return first_match && isMatch(++s, ++p);
}
};
*/

/*
//递归再次优化，加备忘录，把重叠子问题消除
class Solution {
public:
bool isMatch(string s, string p)
{
vector<vector<int>> memo(s.size()+1, vector<int>(p.size()+1, -1));//这里需要加1，防止数组越界
return isMatch(s.c_str(), p.c_str(), memo, 0, 0);
}
bool isMatch(const char *s, const char *p, vector<vector<int>> &memo, int i, int j)
{
if (memo[i][j] != -1)//这里会越界
return memo[i][j];
if (*p == 0)
return memo[i][j] = (*s==0);
int first_match = *s && (*s==*p || *p=='.');
if (*(p+1) == '*')
return memo[i][j]=(isMatch(s, p+2, memo, i, j+2)||(first_match && isMatch(++s, p, memo, i+1, j)));
else
return memo[i][j]=(first_match && isMatch(++s, ++p, memo, i+1, j+1));
}
};
*/


//dp[i][j]表示s[i:]和p[j:]是否可以匹配
//注意：题目中不会出现多个*相连的情况
//动态规划
class Solution {
public:
	bool isMatch(string s, string p)
	{
		vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
		dp[s.size()][p.size()] = true;//base case 空和空一定可以匹配，s不为空p为空一定不能匹配
		for (int i = s.size(); i >= 0; --i)
		{
			for (int j = p.size() - 1; j >= 0; --j)
			{
				//在匹配过程中，我们实际不会用到p以*开头的情况，所以如果第一个字符是*，它的dp值不影响结果
				bool first_match = i<s.size() && (s[i] == p[j] || p[j] == '.');//判断首字符是否匹配
				if (j<p.size() - 1 && p[j + 1] == '*')//从p的倒数第二个字符开始判断下一个字符是不是*
					dp[i][j] = (first_match && (dp[i + 1][j] || dp[i][j + 2])) || (!first_match && dp[i][j + 2]);
				else//如果下一个字符不是*
					dp[i][j] = first_match && dp[i + 1][j + 1];
			}
		}
		return dp[0][0];
	}
};