//34. 在排序数组中查找元素的第一个和最后一个位置
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
	int left = 0, right = numsSize - 1, mid = 0, tag = 0;
	int *result = (int*)malloc(sizeof(int)* 2);
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (nums[mid] < target)
			left = mid + 1;
		else if (nums[mid] > target)
			right = mid - 1;
		else
		{
			tag = 1;
			break;
		}
	}
	if (tag == 1)
	{
		for (left = mid; left >= 0 && nums[left] == nums[mid]; --left);
		for (right = mid; right < numsSize && nums[right] == nums[mid]; ++right);
		result[0] = left + 1;
		result[1] = right - 1;
	}
	else
	{
		result[0] = -1;
		result[1] = -1;
	}
	*returnSize = 2;
	return result;
}