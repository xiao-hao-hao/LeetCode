//9. ������
//�ж�һ�������Ƿ��ǻ���������������ָ��
//�򣨴������ң��͵��򣨴������󣩶�����һ��������
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