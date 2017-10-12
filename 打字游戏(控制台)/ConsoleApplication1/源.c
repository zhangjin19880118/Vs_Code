#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void print()
{
	char str1[] = "*******************************************";
	char str2[] = "* 输入过程中无法退出，输入出错则以 _ 表示!*";
	char str3[] = "* 按任意键开始测试，按下首字母时开始计时！*";
	char str4[] = "*******************************************";
	printf("\n%s\n%s\n%s\n%s\n\n", str1, str2, str3, str4);
}

void put_ch(char str[], int n)
{
	double s = 0;
	time_t start_time = time(NULL);
	for (int i = 0; i < n - 1; ++i)
	{
		if (str[i] == _getch())
		{
			printf("%c", str[i]);
			s++;
		}			
		else
			printf("_");
	}
	time_t end_time = time(NULL);
	putchar('\n');
	printf("完成输入!\n");
	printf("用时 %d 秒\n",end_time - start_time);
	printf("正确率%lf  %%\n", (s / 49)*100);
}

int main()
{
	char str[50],ch;
	do
	{
		system("cls");
		print();
		ch = _getch();
		srand((unsigned int)time(NULL));
		for (int i = 0; i < 49; ++i)
			str[i] = rand() % 26 + 'a';
		str[49] = '\0';
		system("cls");
		putchar('\n');
		printf("%s\n", str);
		put_ch(str, 50);
		printf("按下Esc退出，任意键继续!\n\n");
	} while (27 !=( ch = _getch()));
	return 0;
}