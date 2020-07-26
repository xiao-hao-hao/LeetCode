//剑指 Offer 11. 旋转数组的最小数字
/*
class Solution {
public:
int minArray(vector<int>& numbers)
{
if (numbers.empty())
return 0;
for (int i = 0; i < numbers.size()-1; ++i)
{
if (numbers[i] > numbers[i+1])
return numbers[i+1];
}
return numbers[0];
}
};
*/


class Solution {
public:
	int minArray(vector<int>& numbers)
	{
		int left = 0;
		int right = numbers.size() - 1;
		int mid = 0;
		while (numbers[left] >= numbers[right])
		{
			if (left - right == 1)
			{
				mid = right;
				break;
			}
			mid = left + ((right - left) >> 1);
			//无法判定目标数据在mid左侧还是右侧，采用线性遍历方式
			if (numbers[mid] == numbers[left] && numbers[mid] == numbers[right])
			{
				int res = numbers[left];
				for (int i = )
			}
		}
	}
};



