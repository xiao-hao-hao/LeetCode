//414. ���������
//����һ���ǿ����飬���ش������е������������������ڣ�
//�򷵻���������������Ҫ���㷨ʱ�临�Ӷȱ�����O(n)��

int thirdMax(int* nums, int numsSize)
{
	int first = 0, second = 0, third = 0, count = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		if (count == 0)
		{
			first = nums[i];
			++count;
		}
		if (count == 1)
		{
			if (nums[i] > first)
			{
				second = first;
				first = nums[i];
				++count;
			}
			if (nums[i] < first)
			{
				second = nums[i];
				++count;
			}
		}
		if (count == 2)
		{
			if (nums[i] > first)
			{
				third = second;
				second = first;
				first = nums[i];
				++count;
			}
			if (nums[i] < first && nums[i] > second)
			{
				third = second;
				second = nums[i];
				++count;
			}
			if (nums[i] < first && nums[i] < second)
			{
				third = nums[i];
				++count;
			}
		}
		if (count > 2)
		{
			if (nums[i] > first)
			{
				third = second;
				second = first;
				first = nums[i];
				++count;
			}
			if (nums[i] < first && nums[i] > second)
			{
				third = second;
				second = nums[i];
				++count;
			}
			if (nums[i] < first && nums[i] < second && nums[i] > third)
			{
				third = nums[i];
				++count;
			}
		}
	}
	if (count > 2)
		return third;
	return first;
}