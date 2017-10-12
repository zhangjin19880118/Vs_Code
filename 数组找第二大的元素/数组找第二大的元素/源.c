#include <stdio.h>

int main()
{
	int a[] = { 5, 100, 32, 45, 21, 67, 32, 68, 41, 99, 13, 71 }, *p = a, i = 0, j = 0, temp = 0, n = sizeof(a) / sizeof(a[0]);
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (*(p + j)>*(p + j + 1))
			{
				temp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = temp;
			}
		}
	}
	printf("倒数第二大的元素为%d\n", *(p + n - 2));
	return 0;
}
