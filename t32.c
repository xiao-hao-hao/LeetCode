//
//最长有效括号

//dp[i]表示以s[i]结尾的子串中最长的包含有效括号的子串的长度
class Solution {
public:
	int longestValidParentheses(string s)
	{
		int maxLen = 0;
		int n = s.size();
		vector<int> dp(n, 0);
		for (int i = 1; i < n; ++i)
		{
			if (s[i] == ')')//以(结尾的子字符串不可能构成合法括号
			{
				if (s[i - 1] == '(')//如果i-1为左括号
					//结束部分的"()"是一个有效子字符串，并且将之前的有效子字符串的长度增加了2
					dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2;
				else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(')//如果遇到的不是左括号
					//把以上一个字符结尾的最长子串的上一个字符找到,如果前面字符全部匹配，dp[i]为0
					//否则，将之前的有效子字符串的长度增加了2
					dp[i] = (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + dp[i - 1] + 2;
			}
			maxLen = max(dp[i], maxLen);
		}
		return maxLen;
	}
};