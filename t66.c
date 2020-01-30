//66. 加一
//给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
//最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
//你可以假设除了整数 0 之外，这个整数不会以零开头。


/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
	int *returnArray = (int*)malloc(sizeof(int)* (digitsSize + 1));
	returnArray[digitsSize - 1] = digits[digitsSize - 1] + 1;
	for (int i = digitsSize - 2; i >= 0; --i)
	{
		if (returnArray[i + 1] == 10)
		{
			returnArray[i + 1] = 0;
			returnArray[i] = digits[i] + 1;
			continue;
		}
		returnArray[i] = digits[i];
	}
	*returnSize = digitsSize;
	if (returnArray[0] == 10)
	{
		returnArray[0] = 1;
		returnArray[*returnSize] = 0;
		++(*returnSize);
	}
	return returnArray;
}