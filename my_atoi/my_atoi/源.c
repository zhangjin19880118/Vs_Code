#include <stdio.h>

int my_atoi(char *str)
{
	int n = 0, a[100] = {0}, i = 0, num = 0, k = 1;
	if ('+' == *str)
		str++;
	else if ('-' == *str)
	{
		k *= -1;
		str++;
	}
	while (*str)
	{
		a[n] = *str - '0';
		n++;
		str++;
	}
	for (i = n-1; i >=0; i--)
	{		
		num += a[i]*k;
		k *= 10;
	}
	return num;
}

int main()
{
	printf("%d\n", my_atoi("+123"));
	printf("%d\n", my_atoi("-123"));
	printf("%d\n", my_atoi("123"));
	return 0;
}