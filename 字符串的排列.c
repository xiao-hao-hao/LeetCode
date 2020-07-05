//字符串的排列
/*
//时间复杂的O(n!) 空间复杂度O(n)
class Solution {
public:
void dfs(string &s1, string &s2, string &temp, int len, bool &isInclude, vector<int> &book)
{
if (len == s1.size())
{
if (s2.find(temp) != string::npos)
isInclude = true;
return;
}
for (int i = 0; i < s1.size(); ++i)
{
if (book[i] == 0)
{
temp += s1[i];
book[i] = 1;
dfs(s1, s2, temp, len+1, isInclude, book);
if (isInclude == 1)
return;
book[i] = 0;
temp.pop_back();
}
}
}
bool checkInclusion(string s1, string s2)
{
string temp = "";
bool isInclude = false;
vector<int> book(s1.size(), 0);
dfs(s1, s2, temp, 0, isInclude, book);
return isInclude;
}
};
*/

//滑动窗口法
//窗口的大小就是s1的长度，将s2向后移动进行匹配
//窗口中s2中的字符和s1字符出现次数相等即为匹配成功
//将窗口向后移，直到窗口右边界超出s2的右边界则结束
//在移动过程中要注意窗口内元素的变化
//时间复杂的O(26*(l2-l1)+l1) 空间复杂度O(1)
class Solution {
public:
	bool checkInclusion(string s1, string s2)
	{
		if (s1.size() > s2.size())
			return false;
		vector<int> diff(26, 0);//用来存放两个窗口中字符个数差的结果
		//建立窗口，窗口大小为s1的长度
		for (int i = 0; i < s1.size(); ++i)
		{
			++diff[s1[i] - 'a'];
			--diff[s2[i] - 'a'];
		}
		for (int i = s1.size(); i < s2.size(); ++i)
		{
			if (isSame(diff))
				return true;
			//对窗口进行移动
			++diff[s2[i - s1.size()] - 'a'];
			--diff[s2[i] - 'a'];
		}
		return isSame(diff);//判断最后一个窗口是否匹配
	}
	bool isSame(vector<int> diff)
	{
		for (int i = 0; i < diff.size(); ++i)
		{
			if (diff[i] != 0)
				return false;
		}
		return true;
	}
};