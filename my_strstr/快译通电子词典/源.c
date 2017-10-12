/*实现my_strstr()函数，功能和strstr()函数一样。
	a. 函数中不使用任何操作字符串的函数(如：strcpy、strcmp等)
    b. 函数中的任何地方不使用下标。



	功能：在字符串haystack中查找字符串needle出现的位置
	参数：
		haystack：源字符串首地址
		needle：匹配字符串首地址
	返回值：
		成功：返回第一次出现的needle地址
		失败：NULL
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
		printf("不存在这样的子串!\n");
	else
		printf("第一次出现的地址为:%s\n", my_strstr(haystack, needle));
	return 0;
}
