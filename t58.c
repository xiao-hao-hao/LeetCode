//58. 最后一个单词的长度
//给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。
//如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
//如果不存在最后一个单词，请返回 0 。

int lengthOfLastWord(char * s)
{
	if (!s)
	{
		return 0;
	}
	int right = strlen(s) - 1;
	int left = 0;
	while (right >= 0 && s[right] == ' ')
	{
		--right;
	}
	left = right;
	while (left >= 0 && s[left] != ' ')
	{
		--left;
	}
	return right - left;
}


/*
int lengthOfLastWord(char * s)
{
if (!s)
{
return 0;
}
else
{
int len = strlen(s);
int i = 0, j = 0;
for (i = len - 1; i >= 0 && s[i] == ' '; --i);
for (j = i; j >= 0 && s[j] != ' '; --j);
return i - j;
}
}
*/