//443. Ñ¹Ëõ×Ö·û´®
int compress(char* chars, int charsSize)
{
	int i = 0, k = 0, count = 0;
	char tag;
	for (i = 0; i < charsSize; ++i)
	{
		if (count == 0)
		{
			tag = chars[i];
			++count;
		}
		else if (chars[i] == tag)
		{
			++count;
		}
		if (i == charsSize - 1 || chars[i] != tag)
		{
			if (count == 1)
			{
				chars[k++] = tag;
				count = 0;
				if (chars[i] != tag)
					--i;
			}
			else
			{
				int num = 0;
				chars[k++] = tag;
				if (chars[i] != tag)
					--i;
				while (count > 0)
				{
					int n = num;
					while (n)
					{
						chars[k + n] = chars[k + n - 1];
						--n;
					}
					chars[k] = '0' + count % 10;
					count /= 10;
					++num;
				}
				count = 0;

				k += num;
			}
		}
	}
	return k;
}