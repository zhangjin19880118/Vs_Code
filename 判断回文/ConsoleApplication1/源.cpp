#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

bool Isstrh(char *str)
{
	char *start = str;
	char *end = str + strlen(str) - 1;
	while (start <= end)
	{
		if (*start != *end)
			return false;
		start++;
		end--;
	}
	return true;
}

int main()
{
	char buf[100];
	printf("请输入字符串:");
	scanf("%s", buf);
	if (Isstrh(buf))
		printf("该字符串是回文!\n");
	else
		printf("该字符串不是回文!\n");
	return 0;
}