/*有一个数组，假如元素没有放满，设计一个函数能在指定位置插入指定元素，指定位置删除元素*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//a：数组首元素地址
//pos：指定的位置
//data：需要插入的元素
//size：数组的长度，数组元素的个数，不是数组的大小，增加元素，需要做相应修改
void insert_array(int *a, int pos, int data, int *size)
{
	*size += 1;
	int *p = (int *)calloc(*size, sizeof(int));
	if (!pos)
	{
		*p = data;
		memcpy(p + 1, a, (*size-1)*sizeof(int));
	}
	else if (pos == *size-1)
	{
		memcpy(p, a, (*size - 1)*sizeof(int));
		*(p + *size-1) = data;
	}
	else if (pos > 0 && pos < *size-1)
	{
		memcpy(p, a, pos*sizeof(int));
		* (p + pos) = data;
		memcpy(p + pos + 1, a + pos, (*size - pos - 1)*sizeof(int));
	}
	memcpy(a, p, *size*sizeof(int));
	if (!p)
	{
		free(p);
		p = NULL;
	}
}

void remove_array(int *a, int pos, int *size)
{
	*size -= 1;
	int *p = (int *)calloc(*size - 1, sizeof(int));
	memcpy(p, a + 1, (*size - 1)*sizeof(int));
	memcpy(a, p, (*size-1)*sizeof(int));
	if (!p)
	{
		free(p);
		p = NULL;
	}
}

void print_array(int *a, int size) //打印数组
{
	int i = 0;
	for (i = 0; i < size; ++i)
		printf("%d ", a[i]);
	putchar('\n');
}

int main()
{

	int a[15] = { 1, 3, 5, 7, 9, 11, 13 };
	int size = 7; //数组长度，已经放元素的个数

	print_array(a, size); //打印
	insert_array(a, 0, -1, &size); //在0的位置插入-1
	print_array(a, size); //打印

	insert_array(a, 2, 8, &size); //在2的位置插入8
	print_array(a, size); //打印

	insert_array(a, size, 250, &size); //在末尾的位置插入250
	print_array(a, size); //打印

	print_array(a, size); //打印
	remove_array(a, 0, &size); //删除第0个元素
	print_array(a, size); //打印

	return 0;
}

