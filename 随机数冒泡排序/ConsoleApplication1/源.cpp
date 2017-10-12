#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int a[20], i = 0, j = 0, temp = 0;
	srand((unsigned int)time(NULL));
	for (i = 0; i < 20; i++)
	{
		a[i] = rand() % 100 + 1;
		printf("%d ", a[i]);
	}
	printf("\n");
	for (i = 0; i < 19; i++)
	{
		for (j = 0; j < 19 - i; j++)
		{
			if (a[j]>a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 20; i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}