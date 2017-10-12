/*实现func(str, buf)函数判断输入的字符串(不分大小写)是否是str字符串的子串。
例如：输入"jKLMno"--->子串
主函数已给出：*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int func(char *str, char *buf)
{
	char *start = buf;
	while (*start)
	{
		if (*start >= 'A'&&*start <= 'Z')
			*start += 32;
		start++;
	}
	start = buf;
	while (*str)
	{
		if (*start == *str)
			break;
		str++;
	}
	if (!strncmp(start, str, strlen(buf)))
		return 0;
	return 1;
}
int main()
{
	char* str = "abcdefghijklmnopqrstuvwxyz";
	char buf[1024] = { 0 };
	scanf("%s", buf);
	if (func(str, buf))
	{
		printf("非子串");
	}
	else
	{
		printf("子串");
	}
	while (1);
	return 0;
}
