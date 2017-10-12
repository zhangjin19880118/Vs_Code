#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Fibonacci(int n)
{
	if (1 == n)
		return 1;
	else if (2 == n)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main(void)
{
	printf("%d\n", Fibonacci(6));

	printf("\n");
	system("pause");
	return 0;
}
