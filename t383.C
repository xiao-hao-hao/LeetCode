//383. �����
//����һ������� (ransom) �ַ�����һ����־(magazine)�ַ������жϵ�һ���ַ���ransom�ܲ���
//�ɵڶ����ַ���magazines������ַ����ɡ�������Թ��ɣ����� true �����򷵻� false��
//ע�⣺����Լ��������ַ�����ֻ����Сд��ĸ
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