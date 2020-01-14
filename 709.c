//709. 转换成小写字母
//实现函数 ToLowerCase()，该函数接收一个字符串参数 str，并将该
//字符串中的大写字母转换成小写字母，之后返回新的字符串
class Solution {
public:
	string toLowerCase(string str)
	{
		for (int i = 0; i < str.length(); ++i)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] += 32;
			}
		}
		return str;
	}
};