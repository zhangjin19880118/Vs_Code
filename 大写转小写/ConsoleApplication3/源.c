#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *transform(char *str)
{
	char *start = str;
	while (*start != '\0')
	{
		if (*start >= 'a' && *start <= 'z')
			*start -= 32;
		++start;
	}
	return str;
}

int main(void)
{
	char buf[] = "abcd%$@#sdfASDF";

	printf("%s\n", transform(buf));
	system("pause");
	return 0;
}
