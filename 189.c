//189. ��ת����
//����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����
/*
void rotate(int* nums, int numsSize, int k)
{
k %= numsSize;
while (k)
{
int temp = nums[numsSize - 1];
for (int i = numsSize - 1; i > 0; --i)
{
nums[i] = nums[i - 1];
}
nums[0] = temp;
--k;
}
}
*/
/*
void reverse(int *begin, int size)
{
int temp = 0;
while (begin < begin + size - 1)
{
temp = *begin;
*begin = *(begin + size - 1);
*(begin + size - 1) = temp;
++begin;
size -= 2;
}
}

void rotate(int* nums, int numsSize, int k)
{
k %= numsSize;
reverse(nums, numsSize);
reverse(nums, k);
reverse(nums + k, numsSize - k);
}
*/


void reverse(int *begin, int *end)
{
	int temp = 0;
	while (begin < end)
	{
		temp = *begin;
		*begin = *end;
		*end = temp;
		++begin;
		--end;
	}
}

void rotate(int* nums, int numsSize, int k)
{
	k %= numsSize;
	reverse(nums, nums + numsSize - 1);
	reverse(nums, nums + k - 1);
	reverse(nums + k, nums + numsSize - 1);
}
