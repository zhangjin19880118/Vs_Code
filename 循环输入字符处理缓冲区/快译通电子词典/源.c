/*2.(20��)linux��
���һ������ѭ��������ĸ��
����ÿ����ĸ���б��浽��ǰĿ¼��a.txt�ļ��
�����������˳�ѭ����*/
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
		getchar();//�Ե�һ���س�
		ch = getchar();
	}
	fclose(fp);
	fp = NULL;
}