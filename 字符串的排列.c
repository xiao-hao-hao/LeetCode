//�ַ���������
/*
//ʱ�临�ӵ�O(n!) �ռ临�Ӷ�O(n)
class Solution {
public:
void dfs(string &s1, string &s2, string &temp, int len, bool &isInclude, vector<int> &book)
{
if (len == s1.size())
{
if (s2.find(temp) != string::npos)
isInclude = true;
return;
}
for (int i = 0; i < s1.size(); ++i)
{
if (book[i] == 0)
{
temp += s1[i];
book[i] = 1;
dfs(s1, s2, temp, len+1, isInclude, book);
if (isInclude == 1)
return;
book[i] = 0;
temp.pop_back();
}
}
}
bool checkInclusion(string s1, string s2)
{
string temp = "";
bool isInclude = false;
vector<int> book(s1.size(), 0);
dfs(s1, s2, temp, 0, isInclude, book);
return isInclude;
}
};
*/

//�������ڷ�
//���ڵĴ�С����s1�ĳ��ȣ���s2����ƶ�����ƥ��
//������s2�е��ַ���s1�ַ����ִ�����ȼ�Ϊƥ��ɹ�
//����������ƣ�ֱ�������ұ߽糬��s2���ұ߽������
//���ƶ�������Ҫע�ⴰ����Ԫ�صı仯
//ʱ�临�ӵ�O(26*(l2-l1)+l1) �ռ临�Ӷ�O(1)
class Solution {
public:
	bool checkInclusion(string s1, string s2)
	{
		if (s1.size() > s2.size())
			return false;
		vector<int> diff(26, 0);//������������������ַ�������Ľ��
		//�������ڣ����ڴ�СΪs1�ĳ���
		for (int i = 0; i < s1.size(); ++i)
		{
			++diff[s1[i] - 'a'];
			--diff[s2[i] - 'a'];
		}
		for (int i = s1.size(); i < s2.size(); ++i)
		{
			if (isSame(diff))
				return true;
			//�Դ��ڽ����ƶ�
			++diff[s2[i - s1.size()] - 'a'];
			--diff[s2[i] - 'a'];
		}
		return isSame(diff);//�ж����һ�������Ƿ�ƥ��
	}
	bool isSame(vector<int> diff)
	{
		for (int i = 0; i < diff.size(); ++i)
		{
			if (diff[i] != 0)
				return false;
		}
		return true;
	}
};