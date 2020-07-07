//151. ��ת�ַ�����ĵ���

/*
//����һ��ʹ��ջ���Ƚ���������ԣ���ÿ�����ʶ���ջ��Ȼ�����γ�ջ�ϲ����ɡ�
//ʱ�临�Ӷ�O(n)������Ŀռ临�Ӷ�O(n)
class Solution {
public:
string reverseWords(string s)
{
stack<string> strStack;
int strSize = s.size();
int index = 0;
while (index < strSize)
{
//�����ո�
while (index<strSize && s[index]==' ')
{
++index;
}
if (index >= strSize)
{
break;
}
//ȷ�����ʵ�β���±�
int endIndex = index;
while (endIndex<strSize && s[endIndex]!=' ')
{
++endIndex;
}
//��һ�����ʽ�ȡ����
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


//���������Ƚ������ַ�����ת��Ȼ��ת���ʣ���ȥ������Ŀո�
//ʱ�临�Ӷ�O(n)������Ŀռ临�Ӷ�O(1)
class Solution {
public:
	string reverseWords(string s)
	{
		int strSize = s.size();
		reverse(s.begin(), s.end());//���ַ���ȫ����ת
		s.erase(0, s.find_first_not_of(" "));//ȥ���ַ���ǰ����Ŀո�
		s += ' ';
		//���м�ĵ��ʷ�ת
		for (int i = 0, x = 0; i < s.size(); ++i)
		{
			if (s[i] == ' ')
			{
				reverse(s.begin() + x, s.begin() + i);
				x = i + 1;
				for (int j = i + 1; j < s.size(); ++j)
				{
					//�Ƴ�����ո�
					if (s[j] != ' ')
					{
						s.erase(i + 1, j - (i + 1));
						break;
					}
				}
			}
		}
		s.erase(s.find_last_not_of(" ") + 1);//ȥ���ַ���β������Ŀո�
		return s;
	}
};