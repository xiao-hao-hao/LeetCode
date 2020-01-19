//9. 回文数
//判断一个整数是否是回文数。回文数是指正
//序（从左向右）和倒序（从右向左）读都是一样的整数
bool isPalindrome(int x)
{
	if (x < 0 || (x != 0 && x % 10 == 0))
	{
		return false;
	}
	else
	{
		int reverseNumber = 0;
		while (x > reverseNumber)
		{
			reverseNumber = reverseNumber * 10 + x % 10;
			x /= 10;
		}
		return x == reverseNumber || x == reverseNumber / 10;
	}

}