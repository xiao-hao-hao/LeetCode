//905. ����ż��������
//����һ���Ǹ��������� A������һ�����飬�ڸ������У� 
//A ������ż��Ԫ��֮�������������Ԫ�ء�
//����Է���������������κ�������Ϊ�𰸡�

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