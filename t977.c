//977. ���������ƽ��
//����һ�����ǵݼ�˳��������������� A������ÿ������
//��ƽ����ɵ������飬Ҫ��Ҳ���ǵݼ�˳������
/**
* Note: The returned array must be malloced, assume caller calls free().
*/

int* sortedSquares(int* A, int ASize, int* returnSize)
{
	int *returnArray = (int*)malloc(sizeof(int)* ASize);
	int len = 0, i = 0, j = 0;
	for (i = 0; i < ASize; ++i)
	{
		int temp = A[i] * A[i];
		for (j = len - 1; j >= 0 && returnArray[j] > temp; --j)
		{
			returnArray[j + 1] = returnArray[j];
		}
		returnArray[j + 1] = temp;
		++len;
	}
	*returnSize = len;
	return returnArray;
}

/*
int* sortedSquares(int* A, int ASize, int* returnSize)
{
int *returnArray = (int*)malloc(sizeof(int) * ASize);
int len = 0, i = 0, j = 0, n = 0;
for (i = 0; i < ASize && A[i] < 0; ++i)
++n;
len = ASize - n;
for (i = 0; i < len; ++i)
returnArray[i] = A[i + n] * A[i + n];
for (i = 0; i < n; ++i)
{
int temp = A[i] * A[i];
for (j = len - 1; j >= 0 && returnArray[j] > temp; --j)
{
returnArray[j + 1] = returnArray[j];
}
returnArray[j + 1] = temp;
++len;
}
*returnSize = len;
return returnArray;
}
*/