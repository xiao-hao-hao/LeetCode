//27. 移除元素
//给定一个数组 nums 和一个值 val，你需要原地移除所有数值等于 val 的元素，返回移除后数组的新长度。
//不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
//元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int removeElement(int* nums, int numsSize, int val)
{
	int *pos = nums + numsSize - 1;
	while (nums <= pos)
	{
		if (*nums == val)
		{
			swap(nums, pos);
			--numsSize;
			--pos;
		}
		else
		{
			++nums;
		}
	}
	return numsSize;
}

/*
int removeElement(int* nums, int numsSize, int val){
//k记录不等于val的个数
int k=0;
for (int i=0;i<numsSize;i++)
{
if (nums[i]!=val)
{
nums[k] = nums[i];
k++;
}
}
return k;//新的顺序表的长度
}
*/