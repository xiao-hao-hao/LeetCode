//剑指 Offer 43. 1～n整数中1出现的次数

/*
class Solution {
public:
int countOneNum(int n)
{
int ret = 0;
while (n > 0)
{
if (n % 10 == 1)
++ret;
n /= 10;
}
return ret;
}
int countDigitOne(int n)
{
int count = 0;
for (int i = 1; i <= n; ++i)
count += countOneNum(i);
return count;
}
};
*/
/*
class Solution {
public:
int countDigitOne(int n)
{
string s;
for (int i = 0; i <= n; ++i)
{
s += to_string(i);
}
return count(s.begin(), s.end(), '1');
}
};
*/
//时间复杂的O(log10(n))以10为底n的对数，空间复杂的O(1)
//https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/solution/mian-shi-ti-43-1n-zheng-shu-zhong-1-chu-xian-de-2/
class Solution {
public:
	int countDigitOne(int n)
	{
		int res = 0;
		long digit = 1;
		int high = n / 10, cur = n % 10, low = 0;
		while (high != 0 || cur != 0)//确保中间的某一位为0时也可以进入循环体
		{
			if (cur == 0)
				res += high * digit;
			else if (cur == 1)
				res += high * digit + low + 1;
			else
				res += (high + 1) * digit;
			low += cur * digit;
			cur = high % 10;
			high /= 10;
			digit *= 10;
		}
		return res;
	}
};