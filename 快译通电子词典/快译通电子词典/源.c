#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dict
{
	char *key; //单词
	char *content; //单词对应的解析
}dict;

void format_string(char *str)//去掉字符串结尾的回车，空格字符
{
	size_t i;
	for (i = strlen(str) - 1; i >= 0; i--)
	{
		if (str[i] != '\n' && str[i] != ' ' && str[i] != '\r')
		{
			str[i + 1] = '\0';
			break;
		}
	}
}

int get_size()
{
	char buf1[2048],buf2[2048];
	FILE *fp = fopen("dict_gbk.txt", "rb");
	if (!fp)
	{
		perror("rb open error!\n");
		return -1;
	}
	int i = 0;
	while (!feof(fp))
	{
		memset(buf1, 0, sizeof(buf1));
		fgets(buf1, sizeof(buf1), fp);
		format_string(buf1);
		memset(buf2, 0, sizeof(buf2));
		fgets(buf2, sizeof(buf2), fp);
		format_string(buf2);
		if (!strlen(buf1))
			break;
		i++;
	}
	fclose(fp);
	fp = NULL;
	return i;
}

int search_dict(const struct dict *p, int size, const char *key, char *content)
{
	int i = 0;
	while (i<size)
	{
		if (!strcmp(key, p[i].key))
		{
			strcpy(content, p[i].content);
			return 1;
		}
		i++;
	}
	return 0;
}

int init_dict(dict **p)
{
	FILE *fp = fopen("dict_gbk.txt","rb");
	if (!fp)
	{
		perror("rb open error!\n");
		return -1;
	}
	*p = (dict *)malloc(get_size()*sizeof(dict));
	int i = 0;
	char buf1[2048],buf2[2048];
	while (!feof(fp))
	{
		memset(buf1,0,sizeof(buf1));
		fgets(buf1, sizeof(buf1), fp);
		format_string(buf1);
		memset(buf2, 0, sizeof(buf2));
		fgets(buf2, sizeof(buf2), fp);	
		format_string(buf2);
		if (!strlen(buf1))
			break;
		(*p)[i].key = (char *)malloc(strlen(buf1));
		(*p)[i].content = (char *)malloc(strlen(buf2));
		strcpy((*p)[i].key, &buf1[1]);
		strcpy((*p)[i].content, &buf2[1]);	
		i++;
	}
	fclose(fp);
	fp = NULL;
	return i;
}

int main()
{
	dict *p = NULL;
	int n = init_dict(&p);
	char key[2048], content[2048];
	scanf("%s", key);
	int flag = search_dict(p, n, key, content);
	if (0 == flag)
		printf("找不到对应的翻译!\n");
	else
		printf("%s\n", content);
	return 0;
}