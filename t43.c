//43. �ַ������
//https://leetcode-cn.com/problems/multiply-strings/solution/you-hua-ban-shu-shi-da-bai-994-by-breezean/
/*
//��num2��ÿһλ����num1��ˣ�Ȼ�󽫽�����
class Solution {
public:
string multiply(string num1, string num2)
{
if (num1=="0" || num2=="0")
return "0";
string res = "";
for (int i=num2.size()-1; i>=0; --i)
{
string temp = "";
int flag = 0;
for (int j=num1.size()-1; j>=0 || flag!=0; --j)
{
int n1  = j<0 ? 0 : num1[j]-'0';
int mul = (n1*(num2[i]-'0')+flag) % 10;
flag = (n1*(num2[i]-'0')+flag) / 10;
temp = (char)('0'+mul) + temp;
}
for (int k = 0; k < num2.size()-i-1; ++k)
temp += '0';
res = addStrings(res, temp);
}
return res;
}
string addStrings(string num1, string num2)
{
int flag = 0;
string res = "";
int i=num1.size()-1, j=num2.size()-1;
for (; i>=0 || j>=0 || flag!=0; --i, --j)
{
int x = i<0 ? 0 : num1[i]-'0';
int y = j<0 ? 0 : num2[j]-'0';
int sum = (x + y + flag) % 10;//ȥ����λ�ĺ�
res = (char)('0'+sum) + res;
flag = (x + y + flag) / 10;//��λ
}
return res;
}
};
*/

//����num1λ��ΪM,������num2λ��ΪN,res�����λ��ΪM+N,��СΪM+N-1
//num1[i]*num2[j]�Ľ��Ϊtmp(λ��Ϊ��λ"0x","xy"�������)
//���һλλ�� res[i+j],�ڶ�λλ�� res[i+j+1]
class Solution {
public:
	string multiply(string num1, string num2)
	{
		if (num1 == "0" || num2 == "0")
			return "0";
		vector<int> res(num1.size() + num2.size(), 0);
		for (int i = num1.size() - 1; i >= 0; --i)
		{
			int n1 = num1[i] - '0';
			for (int j = num2.size() - 1; j >= 0; --j)
			{
				int n2 = num2[j] - '0';
				int sum = (res[i + j + 1] + n1*n2);
				res[i + j] += sum / 10;
				res[i + j + 1] = sum % 10;
			}
		}
		string ret = "";
		for (int i = 0; i < res.size(); ++i)
		{
			if (i == 0 && res[i] == 0)
				continue;
			ret += res[i] + '0';
		}
		return ret;
	}
};