//414. 第三大的数
//给定一个非空数组，返回此数组中第三大的数。如果不存在，
//则返回数组中最大的数。要求算法时间复杂度必须是O(n)。

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