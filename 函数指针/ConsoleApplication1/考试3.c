#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int(*pCompare)(int d1, int d2);

int pfunc(int d1, int d2)
{
	return d1 > d2 ? d1 : d2;
}

int Compare(void *d1, void *d2, pCompare pfunc)
{
	return pfunc(*(int *)d1, *(int *)d2);
}

int main(void)
{
	int d1, d2;
	printf("��������������:");
	scanf("%d", &d1);
	scanf("%d", &d2);
	printf("d1��d2�еĽϴ��Ϊ:%d\n", Compare(&d1, &d2, pfunc));
	printf("\n");
	system("pause");
	return 0;
}
