//35. ��������λ��
//����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ����������������
//���Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�
//����Լ������������ظ�Ԫ�ء�
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