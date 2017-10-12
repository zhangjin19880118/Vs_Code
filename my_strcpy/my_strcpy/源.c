#include <stdio.h>

void my_strcpy(char dst[], char src[])//���鷨
{
	int i = 0;
	while (dst[i] != '\0' && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void my_strcpy1(char dst[], char src[])//ָ�뷨
{
	int i = 0;
	char *p1 = dst, *p2 = src;
	while (*(p1 + i) != '\0' && *(p2 + i) != '\0')
	{
		*(p1 + i) = *(p2 + i);
		i++;
	}
	*(p1 + i) = '\0';
}

int main()
{
	char src[100] = "hello";
	char dst[100]; //��src�����ݿ�����dst
	//my_strcpy(dst, "hello");//���鷨
	//printf("dst=%s\n", dst);
	my_strcpy1(dst, "hello");
	printf("dst=%s\n", dst);//ָ�뷨
	return 0;
}