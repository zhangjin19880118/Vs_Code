/*ʵ��my_strstr()���������ܺ�strstr()����һ����
	a. �����в�ʹ���κβ����ַ����ĺ���(�磺strcpy��strcmp��)
    b. �����е��κεط���ʹ���±ꡣ



	���ܣ����ַ���haystack�в����ַ���needle���ֵ�λ��
	������
		haystack��Դ�ַ����׵�ַ
		needle��ƥ���ַ����׵�ַ
	����ֵ��
		�ɹ������ص�һ�γ��ֵ�needle��ַ
		ʧ�ܣ�NULL
	*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char *my_strstr(const char *haystack, const char *needle)
{
	char *start = needle;
	while (*haystack)
	{
		if (*start == *haystack)
			break;
		haystack++;
	}
	start = haystack;
	while(*needle)
	{
		if(*needle!=*haystack)
			return NULL;
		needle++;
		haystack++;
	}
	return start;
}

int main()
{
	char haystack[1024] = { 0 };
	char needle[1024] = { 0 };
	scanf("%s%s", haystack, needle);
	if (!my_strstr(haystack, needle))
		printf("�������������Ӵ�!\n");
	else
		printf("��һ�γ��ֵĵ�ַΪ:%s\n", my_strstr(haystack, needle));
	return 0;
}
