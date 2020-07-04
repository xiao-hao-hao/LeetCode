//最长公共前缀
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		string res = "";
		if (strs.empty())
			return res;
		int n = 0;//用来遍历单词的第n个字符
		char ch = 0;
		while (1)
		{
			ch = strs[0][n];
			if (ch == '\0')
				return res;
			for (int i = 1; i < strs.size(); ++i)
			{
				if (strs[i][n] == '\0' || strs[i][n] != ch)
					return res;
			}
			res += ch;
			++n;
		}
	}
};