//151. 翻转字符串里的单词

/*
//方法一：使用栈的先进后出的特性，将每个单词读入栈，然后依次出栈合并即可。
//时间复杂度O(n)，额外的空间复杂度O(n)
class Solution {
public:
string reverseWords(string s)
{
stack<string> strStack;
int strSize = s.size();
int index = 0;
while (index < strSize)
{
//跳过空格
while (index<strSize && s[index]==' ')
{
++index;
}
if (index >= strSize)
{
break;
}
//确定单词的尾部下标
int endIndex = index;
while (endIndex<strSize && s[endIndex]!=' ')
{
++endIndex;
}
//将一个单词截取出来
string tempStr = s.substr(index, endIndex-index);
strStack.push(tempStr);
index = endIndex + 1;
}
s = "";
if (!strStack.empty())
{
s += strStack.top();
strStack.pop();
}
while (!strStack.empty())
{
s += " " + strStack.top();
strStack.pop();
}
return s;
}
};
*/


//方法二：先将整个字符串翻转，然后翻转单词，再去掉多余的空格。
//时间复杂度O(n)，额外的空间复杂度O(1)
class Solution {
public:
	string reverseWords(string s)
	{
		int strSize = s.size();
		reverse(s.begin(), s.end());//将字符串全部翻转
		s.erase(0, s.find_first_not_of(" "));//去除字符串前多余的空格
		s += ' ';
		//将中间的单词翻转
		for (int i = 0, x = 0; i < s.size(); ++i)
		{
			if (s[i] == ' ')
			{
				reverse(s.begin() + x, s.begin() + i);
				x = i + 1;
				for (int j = i + 1; j < s.size(); ++j)
				{
					//移除多余空格
					if (s[j] != ' ')
					{
						s.erase(i + 1, j - (i + 1));
						break;
					}
				}
			}
		}
		s.erase(s.find_last_not_of(" ") + 1);//去除字符串尾部多余的空格
		return s;
	}
};