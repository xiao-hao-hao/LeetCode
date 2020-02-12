//905. 按奇偶排序数组
//给定一个非负整数数组 A，返回一个数组，在该数组中， 
//A 的所有偶数元素之后跟着所有奇数元素。
//你可以返回满足此条件的任何数组作为答案。

/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* sortArrayByParity(int* A, int ASize, int* returnSize)
{
	int *returnArray = (int*)malloc(sizeof(int)* ASize);
	int i = 0, left = 0, right = ASize - 1;
	for (i = 0; i < ASize; ++i)
	{
		if (A[i] % 2 == 0)
			returnArray[left++] = A[i];
		else
			returnArray[right--] = A[i];
	}
	*returnSize = ASize;
	return returnArray;
}