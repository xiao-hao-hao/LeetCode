//383. 赎金信
//给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串ransom能不能
//由第二个字符串magazines里面的字符构成。如果可以构成，返回 true ；否则返回 false。
//注意：你可以假设两个字符串均只含有小写字母
bool canConstruct(char * ransomNote, char * magazine)
{
	if (strlen(ransomNote) > strlen(magazine))
	{
		return false;
	}
	else
	{
		int i = 0;
		int count[26] = { 0 };
		for (i = 0; ransomNote[i] != '\0'; ++i)
		{
			++(count[(ransomNote[i] - 'a')]);
		}
		for (i = 0; magazine[i] != '\0'; ++i)
		{
			--(count[(magazine[i] - 'a')]);
		}
		for (i = 0; i < 26; ++i)
		{
			if (count[i] > 0)
			{
				return false;
			}
		}
		return true;
	}
}