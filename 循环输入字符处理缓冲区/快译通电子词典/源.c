/*2.(20分)linux下
设计一个程序循环输入字母，
并将每个字母逐行保存到当前目录下a.txt文件里，
输入其他则退出循环。*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	FILE *fp = fopen("a.txt", "w");
	if (!fp)
	{
		perror("w open error!\n");
		return -1;
	}
	char ch;
	ch = getchar();
	while (ch >= 'A'&&ch <= 'Z' || ch >= 'a'&&ch <= 'z')
	{
		fprintf(fp, "%c\n", ch);
		getchar();//吃掉一个回车
		ch = getchar();
	}
	fclose(fp);
	fp = NULL;
}