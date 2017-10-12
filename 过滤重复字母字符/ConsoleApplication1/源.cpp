#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print_ch(char *str)
{
	char temp['z' - 'A' + 1] = {0},i = 0;
	while (*str)
	{
		if ((*str >= 'A'&&*str <= 'Z') || (*str >= 'a'&&*str <= 'z'))
			temp[*str-'A'] = *str;
		str++;
	}
	for (i = 0; i < 'z' - 'A' + 1; i++)
	{
		if (temp[i])
			printf("%c ", temp[i]);
	}
	printf("\n");
}

int main()
{
	char str[100];
	printf("ÇëÊäÈë×Ö·û´®:\n");
	scanf("%s", str);
	print_ch(str);
	return 0;
}