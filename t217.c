//217. �����ظ�Ԫ��
//����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�
//����κ�ֵ�������г����������Σ��������� true��
//���������ÿ��Ԫ�ض�����ͬ���򷵻� false��

#include <algorithm>
class Solution {
public:
	bool containsDuplicate(vector<int>& nums)
	{
		if (nums.capacity() == 0)
			return false;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.capacity() - 1; ++i)
		{
			if (nums[i] == nums[i + 1])
				return true;
		}
		return false;
	}
};