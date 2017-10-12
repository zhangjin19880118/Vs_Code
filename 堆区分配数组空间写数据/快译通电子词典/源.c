/*键盘输入一个数列，保存在用 malloc() 函数申请的堆空间里,
然后使用冒泡排序法对这个堆里的值进行排序,
将排序后结果在屏幕上打印出来,
并写入当前目录下a.txt文件内.*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10//后面没有分号

void sort(int *p, int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; ++i)
	{
		for (j = 0; j < n - 1 - i; ++j)
		{
			if (p[j]>p[j+1])
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

int main()
{
	int i = 0;
	FILE *fp = fopen("1.txt", "w");
	if (!fp)
	{
		perror("w open error!\n");
		return -1;
	}
	int *p = (int *)malloc(N*sizeof(int));
	printf("请输入数组:\n");
	for (i = 0; i < N; ++i)
		scanf("%d", p + i);
	sort(p, N);
	for (i = 0; i < N; ++i)
	{
		printf("%d ", *(p + i));
		fprintf(fp, "%d\n", *(p + i));
	}
	putchar('\n');
	fclose(fp);
	fp = NULL;
	return 0;
}
