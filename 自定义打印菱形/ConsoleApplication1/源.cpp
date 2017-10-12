#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void print(int num)
{
	int i = 0, j = 0, k = 0;
	for (i = 0; i < num; ++i)
	{
		for (j = 0; j < num - i - 1; ++j)
			putchar(' ');
		for (k = 0;k<2*i+1; ++k)
			putchar('*');
		putchar('\n');
	}
	for (i = num - 1; i>0;i--)
	{
		for (j = 0; j < num - i; ++j)
			putchar(' ');
		for (k = 0; k<2 * i - 1; ++k)
			putchar('*');
		putchar('\n');
	}
}

int main()
{
	int num = 0;
	printf("请输入要打印的菱形层数：");
	scanf("%d", &num);
	print(num);
	return 0;
}