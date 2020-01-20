//35. 搜索插入位置
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
//如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//你可以假设数组中无重复元素。
int searchInsert(int* nums, int numsSize, int target)
{
	int i = 0;
	while (i < numsSize)
	{
		if (nums[i] < target)
		{
			++i;
		}
		else
		{
			return i;
		}
	}
	return numsSize;
}