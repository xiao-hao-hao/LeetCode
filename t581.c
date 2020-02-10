//581. 最短无序连续子数组
int findUnsortedSubarray(int* nums, int numsSize)
{
	int temp[numsSize];
	int len = 0, left = 0, right = numsSize - 1;
	for (int i = 0; i < numsSize; ++i)
	{
		int j = 0;
		for (j = len - 1; j >= 0 && temp[j] > nums[i]; --j)
		{
			temp[j + 1] = temp[j];
		}
		temp[j + 1] = nums[i];
		++len;
	}
	while (left <= right && nums[left] == temp[left])
	{
		++left;
	}
	while (left < right && nums[right] == temp[right])
	{
		--right;
	}
	return right - left + 1;
}