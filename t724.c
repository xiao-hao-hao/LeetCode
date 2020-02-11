﻿//724. 寻找数组的中心索引
//给定一个整数类型的数组 nums，请编写一个能够返回数组“中心索引”的方法。
//我们是这样定义数组中心索引的：数组中心索引的左侧所有元素相加的和等于右侧所有元素相加的和。
//如果数组不存在中心索引，那么我们应该返回 - 1。如果数组有多个中心索引，那么我们应该返回最靠近左边的那一个。


int pivotIndex(int* nums, int numsSize)
{
	if (numsSize == 0 || nums == NULL)
		return -1;
	int leftSum = 0, numsSum = 0;
	for (int i = 0; i < numsSize; ++i)
		numsSum += nums[i];
	for (int i = 0; i < numsSize; ++i)
	{
		if (leftSum == numsSum - leftSum - nums[i])
			return i;
		leftSum += nums[i];
	}
	return -1;
}