//43. 字符串相乘
//https://leetcode-cn.com/problems/multiply-strings/solution/you-hua-ban-shu-shi-da-bai-994-by-breezean/
/*
//将num2的每一位的与num1相乘，然后将结果相加
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
int sum = (x + y + flag) % 10;//去掉进位的和
res = (char)('0'+sum) + res;
flag = (x + y + flag) / 10;//进位
}
return res;
}
};
*/

//乘数num1位数为M,被乘数num2位数为N,res最大总位数为M+N,最小为M+N-1
//num1[i]*num2[j]的结果为tmp(位数为两位"0x","xy"两种情况)
//其第一位位于 res[i+j],第二位位于 res[i+j+1]
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