#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int my_strcmp(char s1[], char s2[])
{
	int i = 0;
	int count = 0;
	while (s1[i]!='\0'&& s2[i]!='\0')
	{
		if (s1[i] > s2[i])
			break;
		if (s1[i] < s2[i])
			break;
		if (s1[i] == s2[i])
			count++;
		i++;
	}
	if (s1[i] > s2[i])
		i = 1;
	if (s1[i] < s2[i])
		i = -1;
	if (strlen(s1) == strlen(s2) && count == strlen(s1))
		i = 0;
	return i;
}

int main()
{
	printf("%d\n", my_strcmp("abd", "abcd"));
	return 0;
}