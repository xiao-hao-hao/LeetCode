//60. 第k个排列

/*
class Solution {
public:
void dfs(int n, vector<int> &book, vector<string> &res, string tmp, int curPos)
{
book[curPos] = 1;
for (int i = 1; i <= n; ++i)
{
if (tmp.size() == n)
{
res.push_back(tmp);
return;
}
if (book[i] == 0)
{
tmp += i+'0';
dfs(n, book, res, tmp, i);
tmp.erase(tmp.end()-1);
book[i] = 0;
}
}
}
string getPermutation(int n, int k)
{
vector<int> book(n+1, 0);
vector<string> res;
string tmp;
for (int i = 1; i <= n; ++i)
{
tmp += i+'0';
dfs(n, book, res, tmp, i);
tmp.erase(tmp.end()-1);
book[i] = 0;
}
return res[k-1];
}
};
*/


class Solution {
public:
	void dfs(vector<int> &dict, vector<int> &book, int curPos, int k, string &res, int n)
	{
		res += curPos + '0';
		book[curPos] = 1;
		for (int i = 1; i <= n && res.size()<n; ++i)
		{
			if (book[i] == 0)
			{
				if (dict[n - res.size() - 1] >= k)
					dfs(dict, book, i, k, res, n);
				else
					k -= dict[n - res.size() - 1];
			}
		}
	}
	string getPermutation(int n, int k)
	{
		//计算阶乘数组
		vector<int> dict(n + 1, 0);
		dict[0] = 1;
		for (int i = 1; i <= n; ++i)
			dict[i] = dict[i - 1] * i;
		string res;
		vector<int> book(n + 1, 0);
		for (int i = 1; i <= n && res.size()<n; ++i)
		{
			if (dict[n - res.size() - 1] >= k)
				dfs(dict, book, i, k, res, n);
			else
				k -= dict[n - res.size() - 1];
		}
		return res;
	}
};