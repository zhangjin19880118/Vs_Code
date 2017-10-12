#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count(int n)
{
	int s;
	if (0 == n)
		s = 1;
	else
		s = 2 * count(n - 1);
	return s;
}

int main(void)
{
	double a = 1.0*count(23) / count(30);
	printf("%lf\n", a);

	printf("\n");
	system("pause");
	return 0;
}
