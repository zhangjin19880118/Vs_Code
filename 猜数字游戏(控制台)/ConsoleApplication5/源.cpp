#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#pragma warning(disable:4996)


int main()
{
	printf("猜数字：系统会随机产生一个四位数字。\n\n");
	int num[4] = {0};
	srand((unsigned)time(NULL));
	int i = 0;
	for ( i = 0; i < 4; i++)
		num[i] = rand() % 10;
	int count = 0;
	int input=0,temp=0;

	char cinput[100] = {0};
	char chinput[4] = {0};
	
	int j = 0;
	while (count<4)
	{ 
		//printf("请输入一个4位数字：");
		//scanf("%s", cinput);
		do
		{
			count = 0;
			printf("请输入一个4位数字：");
			scanf("%s", cinput);
			for (i = 0; i < 4; i++)
			{
				if (cinput[i]>='0' && cinput[i]<='9')
					count++;
			}
		}while (count < 4);
		for (i = 0; i < 4; i++)
			chinput[i] = cinput[i];
		input = atoi(chinput);
		//scanf("%d", &input);
		count = 0;
		for (i = 0; i < 4;i++)
		{
			temp = input;
			for (j = 0; j<3 - i; j++)
				temp /= 10;
			if (temp % 10>num[i])
				printf("第%d位大于正确数字。\n",i+1);
			else if (temp % 10<num[i])
				printf("第%d位小于正确数字。\n", i + 1);
			else
			{
				printf("第%d位正确。\n", i + 1);	
				count++;
			}	
		}
		printf("\n");
	}
	return 0;
}