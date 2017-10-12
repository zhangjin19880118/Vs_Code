#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int method1()
{
	for (int i = 6;; i += 5)
	{
		int temp = i;
		int j = 0;
		for (; j < 5; ++j)
		{
			if ((temp - 1) % 5 == 0)
			{
				temp = (temp - 1) / 5 * 4;
			}
			else
			{
				break;
			}
		}
		if (j == 5)
		{
			return i;
			break;
		}
	}
	return -1;
}

int Recursion1(int src, int n, int count)
{
	if (count == 0)
		return src;
	if ((n - 1) % 5 == 0)
	{
		return Recursion1(src, (n - 1) / 5 * 4, count - 1);
	}
	else
	{
		return Recursion1(src + 5, src + 5, 5);
	}
}

int count = 5;

int Recursion2(int n,int count)
{
	if (count == 0)
		return 1;
	if ((n - 1) % 5 == 0)
	{
		//--count;
		return Recursion2((n - 1) / 5 * 4,count-1);
	}
	else
	{
		//count = 5;
		return 0;
	}
}

int main(void)
{

	//printf("%d\n", method1());
	//printf("%d\n", Recursion1(6, 6, 5));

	for (int i = 6;; i += 5)
	{
		if (Recursion2(i, 5))
		{
			printf("%d\n", i);
			break;
		}
	}

	printf("\n");
	system("pause");
	return 0;
}
