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
	printf("�������ַ���:");
	scanf("%s", buf);
	if (Isstrh(buf))
		printf("���ַ����ǻ���!\n");
	else
		printf("���ַ������ǻ���!\n");
	return 0;
}