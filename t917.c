//917. ������ת��ĸ
//����һ���ַ��� S������ ����ת��ġ� �ַ�����
//���в�����ĸ���ַ���������ԭ�أ���������ĸ��λ�÷�����ת

char * reverseOnlyLetters(char * S)
{
	int left = 0, right = strlen(S) - 1;
	while (left < right)
	{
		if ((S[left] >= 'a' && S[left] <= 'z' || S[left] >= 'A' && S[left] <= 'Z')
			&& (S[right] >= 'a' && S[right] <= 'z' || S[right] >= 'A' && S[right] <= 'Z'))
		{
			char temp = S[left];
			S[left] = S[right];
			S[right] = temp;
			++left;
			--right;
		}
		if (S[left]>'Z' && S[left]<'a' || S[left]<'A' || S[left]>'z')
		{
			++left;
		}
		if (S[right]>'Z' && S[right]<'a' || S[right]<'A' || S[right]>'z')
		{
			--right;
		}
	}
	return S;
}