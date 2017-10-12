#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"DynamicArray.h"

struct person
{
	char name[64];
	int age;
};

void print(void *data)
{
	struct person *p = (struct person *)data;
	printf("Name:%s Age:%d\n", p->name, p->age);
}

void test()
{
	struct DArray *arr = Init_DynamicArray();
	struct person p1 = { "aaa", 10 };
	struct person p2 = { "bbb", 20 };
	struct person p3 = { "ccc", 30 };
	struct person p4 = { "ddd", 40 };
	struct person p5 = { "eee", 50 };
	struct person p6 = { "fff", 60 };

	Insert_DynamicArray(arr, 0, &p1);
	Insert_DynamicArray(arr, 0, &p2);
	Insert_DynamicArray(arr, 666, &p3);
	Insert_DynamicArray(arr, 1, &p4);
	Insert_DynamicArray(arr, 2, &p5); //20 40 60 50 10 30
	Insert_DynamicArray(arr, 2, &p6);


	Foreach_DynamicArray(arr, print);
	printf("--------------\n");


	//删除指定位置
	Remove_DynamicArray(arr, 5);
	Foreach_DynamicArray(arr, print);

	//释放内存
	Destory_DynamicArray(arr);
}

int main(void)
{
	test();

	printf("\n");
	system("pause");
	return 0;
}
