#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void rand_num(int a[],int n)
{
	int i = 0;
	srand((unsigned int)time(NULL));
	for (i = 0; i < n; ++i)
		a[i] = rand() % 100;
}

void read_file()
{
	char buf[100];
	int b[1024], i = 0;
	memset(buf, 0, sizeof(buf));
	FILE *fp = fopen("1.txt", "r");
	while (!feof(fp))
	{
		char *p = fgets(buf, sizeof(buf), fp);
		if (!p)
			break;
		sscanf(buf, "%d\n", &b[i]);
		printf("b[%d]=%d\n", i, b[i]);
		i++;
	}
	fclose(fp);
}

int main()
{
	int a[500] = { 0 }, i = 0, b[1024] = { 0 }, j = 0,temp=0;
	char buf[128];
	rand_num(a, 500);
	FILE *fp = fopen("1.txt","w");
	for (i = 0; i < 500; ++i)
	{
		sprintf(buf, "%d\n",a[i]);
		fputs(buf, fp);
	}
	fclose(fp);
	read_file();
	fp = fopen("1.txt", "w");
	if (!fp)
	{
		perror("w fopen error!\n");
		return;
	}
	for (i = 0; i < 499; ++i)
	{
		for (j = 0; j < 499 - i; ++j)
		{
			if (b[j]>b[j + 1])
			{
				temp = b[j];
				b[j] = b[j + 1];
				b[j + 1] = temp;
			}
		}
	}
	memset(buf, 0, sizeof(buf));
	for (i = 0; i < 500; ++i)
	{
		sprintf(buf, "%d\n", b[i]);
		fputs(buf, fp);
	}
	fclose(fp);
	fp = NULL;
	read_file();
	return 0;
}
