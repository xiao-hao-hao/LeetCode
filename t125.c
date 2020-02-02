//125. 验证回文串
bool isFigure(char ch)
{
	return ch >= '0' && ch <= '9';
}

bool isLetter(char ch)
{
	return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

bool isPalindrome(char * s)
{
	int left = 0, right = strlen(s) - 1;
	while (left < right)
	{
		while (left < right && !isFigure(s[left]) && !isLetter(s[left]))
		{
			++left;
		}
		while (left < right && !isFigure(s[right]) && !isLetter(s[right]))
		{
			--right;
		}
		if (left < right && isFigure(s[left]) && isFigure(s[right]))
		{
			if (s[left] == s[right])
			{
				++left;
				--right;
			}
			else
				return false;
		}
		else if (left < right && isLetter(s[left]) && isLetter(s[right]))
		{
			if (s[left] == s[right] || s[left] - s[right] == 32 || s[left] - s[right] == -32)
			{
				++left;
				--right;
			}
			else
				return false;
		}
		else if (left < right && (isLetter(s[left]) && isFigure(s[right])) || (isLetter(s[right]) && isFigure(s[left])))
			return false;
	}
	return true;
}