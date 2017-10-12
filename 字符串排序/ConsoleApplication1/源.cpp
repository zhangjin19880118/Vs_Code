#include <stdio.h>
#include <string.h>

void print_word1(char *words[], int n)//数组法
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%s ", words[i]);
	}
	printf("\n");
}

void print_word(char **words, int n)//指针法
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%s ", *(words+i));
	}
	printf("\n");
}

void sort_word1(char *words[], int n)//数组法
{
	int i = 0,j=0;
	char *temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (strcmp(words[j], words[j + 1])>0)
			{
				temp = words[j];
				words[j] = words[j + 1];
				words[j + 1] = temp;
			}
		}
	}
}

void sort_word(char **words, int n)//指针法
{
	int i = 0, j = 0;
	char *temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (strcmp(*(words + j), *(words + j+1))>0)
			{
				temp = *(words + j);
				*(words + j) = *(words + j + 1);
				*(words + j + 1) = temp;
			}
		}
	}
}

int main()
{
	char *words[] = { "city", "student", "tree", "bee" };
	int n = sizeof(words) / sizeof(words[0]);
	print_word(words, n);//指针法
	sort_word(words, n);
	print_word(words, n);
	//print_word1(words, n);//数组法
	//sort_word1(words, n);
	//print_word1(words, n);
	return 0;
}