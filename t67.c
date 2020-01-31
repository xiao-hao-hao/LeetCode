//67. 二进制求和
char * addBinary(char * a, char * b)
{
	int tag = 0;
	int aLength = strlen(a);
	int bLength = strlen(b);
	int resultLen = (aLength > bLength ? aLength : bLength) + 2;
	char *result = (char*)malloc(sizeof(char)* resultLen);
	int i = resultLen - 3;//为result赋值的偏移量
	while (aLength > 0 || bLength > 0)
	{
		char sum;
		if (aLength > 0 && bLength > 0)
		{
			sum = '0' + (a[aLength - 1] - '0') + (b[bLength - 1] - '0') + tag;
			--aLength;
			--bLength;
		}
		else if (aLength > 0)
		{
			sum = '0' + (a[aLength - 1] - '0') + tag;
			--aLength;
		}
		else if (bLength > 0)
		{
			sum = '0' + (b[bLength - 1] - '0') + tag;
			--bLength;
		}
		if (sum > '1')
		{
			result[i--] = sum - 2;
			tag = 1;
		}
		else
		{
			result[i--] = sum;
			tag = 0;
		}
	}
	if (tag == 1)
	{
		result[resultLen - 1] = '\0';
		while (resultLen - 2)
		{
			result[resultLen - 2] = result[resultLen - 3];
			--resultLen;
		}
		result[0] = '1';
	}
	else
	{
		result[resultLen - 2] = '\0';
	}
	return result;
}