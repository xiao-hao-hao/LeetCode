//709. ת����Сд��ĸ
//ʵ�ֺ��� ToLowerCase()���ú�������һ���ַ������� str��������
//�ַ����еĴ�д��ĸת����Сд��ĸ��֮�󷵻��µ��ַ���
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