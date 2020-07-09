//93. 复原IP地址
class Solution
{
public:
	vector<string> restoreIpAddresses(string s)
	{
		int len = s.size();
		vector<string> res;
		if (len>12 || len<4)
			return res;
		vector<string> path;
		dfs(s, len, 0, 4, path, res);
		return res;
	}
private:
	//residue--剩余  用来记录剩余多少段还没被分割
	void dfs(string s, int len, int begin, int residue, vector<string> &path, vector<string> &res)
	{
		if (begin == len)
		{
			if (residue == 0)
			{
				string temp = path[0];
				for (int i = 1; i < path.size(); ++i)
					temp += '.' + path[i];
				res.push_back(temp);
			}
			return;
		}
		for (int i = begin; i<begin + 3; ++i)
		{
			if (i >= len)
				break;
			if ((residue - 1) * 3 < len - i - 1)
				continue;
			if (judgeIpSegment(s, begin, i))
			{
				string currentIpSegment = s.substr(begin, i - begin + 1);
				path.push_back(currentIpSegment);
				dfs(s, len, i + 1, residue - 1, path, res);
				path.pop_back();
			}
		}
	}
	bool judgeIpSegment(string s, int left, int right)
	{
		int len = right - left + 1;
		if (len>1 && s[left] == '0')//ip段第一个数字不能是0
			return false;
		int res = 0;
		while (left <= right)
		{
			res = res * 10 + s[left] - '0';
			++left;
		}
		return res >= 0 && res <= 255;
	}
};