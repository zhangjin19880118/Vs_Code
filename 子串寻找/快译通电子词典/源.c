/*ʵ��func(str, buf)�����ж�������ַ���(���ִ�Сд)�Ƿ���str�ַ������Ӵ���
���磺����"jKLMno"--->�Ӵ�
�������Ѹ�����*/
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
		printf("���Ӵ�");
	}
	else
	{
		printf("�Ӵ�");
	}
	while (1);
	return 0;
}
