//������ʽƥ��

/*
//�ݹ�
class Solution {
public:
bool isMatch(string s, string p)
{
if (p.empty())
return s.empty();
bool first_match = !s.empty() && (p[0]==s[0] || p[0]=='.');//�жϵ�һ���ַ��ɲ�����ƥ��
if (p.size()>=2 && p[1]=='*')//����ڶ����ַ���*�����
return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
else//����ڶ����ַ�����*�����
return first_match && isMatch(s.substr(1), p.substr(1));
}
};
*/

/*
//�ݹ��Ż�
class Solution {
public:
bool isMatch(string s, string p)
{
return isMatch(s.c_str(), p.c_str());
}
bool isMatch(const char *s, const char *p)
{
if (*p == 0)
return *s == 0;
bool first_match = *s && (*s==*p || *p=='.');
if (*(p+1) == '*')
return isMatch(s, p+2) || (first_match && isMatch(++s, p));
else
return first_match && isMatch(++s, ++p);
}
};
*/

/*
//�ݹ��ٴ��Ż����ӱ���¼�����ص�����������
class Solution {
public:
bool isMatch(string s, string p)
{
vector<vector<int>> memo(s.size()+1, vector<int>(p.size()+1, -1));//������Ҫ��1����ֹ����Խ��
return isMatch(s.c_str(), p.c_str(), memo, 0, 0);
}
bool isMatch(const char *s, const char *p, vector<vector<int>> &memo, int i, int j)
{
if (memo[i][j] != -1)//�����Խ��
return memo[i][j];
if (*p == 0)
return memo[i][j] = (*s==0);
int first_match = *s && (*s==*p || *p=='.');
if (*(p+1) == '*')
return memo[i][j]=(isMatch(s, p+2, memo, i, j+2)||(first_match && isMatch(++s, p, memo, i+1, j)));
else
return memo[i][j]=(first_match && isMatch(++s, ++p, memo, i+1, j+1));
}
};
*/


//dp[i][j]��ʾs[i:]��p[j:]�Ƿ����ƥ��
//ע�⣺��Ŀ�в�����ֶ��*���������
//��̬�滮
class Solution {
public:
	bool isMatch(string s, string p)
	{
		vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
		dp[s.size()][p.size()] = true;//base case �պͿ�һ������ƥ�䣬s��Ϊ��pΪ��һ������ƥ��
		for (int i = s.size(); i >= 0; --i)
		{
			for (int j = p.size() - 1; j >= 0; --j)
			{
				//��ƥ������У�����ʵ�ʲ����õ�p��*��ͷ����������������һ���ַ���*������dpֵ��Ӱ����
				bool first_match = i<s.size() && (s[i] == p[j] || p[j] == '.');//�ж����ַ��Ƿ�ƥ��
				if (j<p.size() - 1 && p[j + 1] == '*')//��p�ĵ����ڶ����ַ���ʼ�ж���һ���ַ��ǲ���*
					dp[i][j] = (first_match && (dp[i + 1][j] || dp[i][j + 2])) || (!first_match && dp[i][j + 2]);
				else//�����һ���ַ�����*
					dp[i][j] = first_match && dp[i + 1][j + 1];
			}
		}
		return dp[0][0];
	}
};