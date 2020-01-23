//8. ×Ö·û´®×ª»»ÕûÊı (atoi)
int myAtoi(char * str)
{
	int i = 0, sign = 0;
	long result = 0;
	if (str == NULL || str[0] == '\0')
		return 0;
	for (i = 0; str[i] == ' '; ++i);
	sign = (str[i] == '-') ? -1 : 1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if ((int)result != result)
		{
			return sign == 1 ? INT_MAX : INT_MIN;
		}
	}
	return result * sign;
}