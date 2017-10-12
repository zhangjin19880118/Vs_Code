/*��һ�����飬����Ԫ��û�з��������һ����������ָ��λ�ò���ָ��Ԫ�أ�ָ��λ��ɾ��Ԫ��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//a��������Ԫ�ص�ַ
//pos��ָ����λ��
//data����Ҫ�����Ԫ��
//size������ĳ��ȣ�����Ԫ�صĸ�������������Ĵ�С������Ԫ�أ���Ҫ����Ӧ�޸�
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

void print_array(int *a, int size) //��ӡ����
{
	int i = 0;
	for (i = 0; i < size; ++i)
		printf("%d ", a[i]);
	putchar('\n');
}

int main()
{

	int a[15] = { 1, 3, 5, 7, 9, 11, 13 };
	int size = 7; //���鳤�ȣ��Ѿ���Ԫ�صĸ���

	print_array(a, size); //��ӡ
	insert_array(a, 0, -1, &size); //��0��λ�ò���-1
	print_array(a, size); //��ӡ

	insert_array(a, 2, 8, &size); //��2��λ�ò���8
	print_array(a, size); //��ӡ

	insert_array(a, size, 250, &size); //��ĩβ��λ�ò���250
	print_array(a, size); //��ӡ

	print_array(a, size); //��ӡ
	remove_array(a, 0, &size); //ɾ����0��Ԫ��
	print_array(a, size); //��ӡ

	return 0;
}

