/*1.(20��)linux��
���һ������ͳ�Ƶ�ǰĿ¼��a.txt �ı��ļ����ݵ�������*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void format_string(char *str)
{
	size_t i;
	for (i = strlen(str) - 1; i >= 0; i--)
	{
		if (str[i] != '\r'&&str[i] != '\n'&&str[i] != ' ')
		{
			str[i + 1] = '\0';
			break;
		}
	}
}

int get_line()
{
	FILE *fp = fopen("a.txt", "r");
	if (!fp)
	{
		perror("r open error!\n");
		return -1;
	}
	char buf[2048] = {0};
	int i = 0;
	while (!feof(fp))
	{
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), fp);
		format_string(buf);
		if (!strlen(buf))//û������
			break;
		i++;
	}
	fclose(fp);
	fp = NULL;
	return i;
}

int main()
{
	printf("��ǰĿ¼��a.txt�ı��ļ����ݵ�����Ϊ:%d\n", get_line());
	return 0;
}