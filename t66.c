//66. ��һ
//����һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
//���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�
//����Լ���������� 0 ֮�⣬��������������㿪ͷ��


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