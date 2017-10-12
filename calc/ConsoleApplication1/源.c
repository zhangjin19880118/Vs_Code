#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int add(int a,int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mux(int a, int b)
{
	return a * b;
}

int dive(int a, int b)
{
	return a / b;
}

int main()
{
	char name[20];
	int a, b;
	while (1)
	{
		printf("please input cmd: ");
		scanf("%s %d %d", name, &a, &b);
		if (!strcmp("add", name))
			printf("result = %d\n", add(a, b));
		else if (!strcmp("sub", name))
			printf("result = %d\n", sub(a, b));
		else if (!strcmp("mux", name))
			printf("result = %d\n", mux(a, b));
		else if (!strcmp("dive", name))
			printf("result = %d\n", dive(a, b));
	}
	return 0;
}