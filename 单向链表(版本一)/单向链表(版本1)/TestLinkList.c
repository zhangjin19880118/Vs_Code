#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkList.h"

struct person
{
	char name[64];
	int age;
};

void myprint(void* data)
{
	struct person *person = (struct person *)data;
	printf("Name:%s Age:%d\n", person->name, person->age);
}

bool mycompare(void *d1, void *d2)
{
	struct person *p1 = (struct person *)d1;
	struct person *p2 = (struct person *)d2;

	return strcmp(p1->name, p2->name) == 0 && p1->age == p2->age;
}

int compare(void *d1, void *d2)
{
	struct person *p1 = (struct person *)d1;
	struct person *p2 = (struct person *)d2;
	return p1->age < p2->age;
}

int main(void)
{
	//测试数据
	struct person p1 = { "aaa", 10 };
	struct person p2 = { "bbb", 20 };
	struct person p3 = { "ccc", 30 };
	struct person p4 = { "ddd", 40 };
	struct person p5 = { "eee", 50 };
	struct person p6 = { "fff", 60 };

	//创建链表
	struct LList *list = Init_LinkList();

	//插入数据
	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);
	Insert_LinkList(list, 0, &p4);
	Insert_LinkList(list, 0, &p5);
	Insert_LinkList(list, 0, &p6);
	Foreach_LinkList(list, myprint);
	printf("------------------------\n");
	Sort_LinkList(list, compare);
	Foreach_LinkList(list, myprint);
	printf("-------------sort-----------\n");

	Reverse_LinkList(list);
	Foreach_LinkList(list, myprint);

	printf("------------------------\n");
	struct person p7 = { "fff", 60 };
	struct person *ret = (struct person *)Search_LinkList(list, &p7, mycompare);
	printf("ret -> Name:%s Age:%d\n", ret->name, ret->age);

	ReverseForeach_LinkList(list, myprint);

	printf("--------------------\n");

	Foreach_LinkList(list, myprint);

	//删除数据
	Remove_LinkList(list, 0);
	printf("-------------\n");
	Foreach_LinkList(list, myprint);
	Remove_LinkList(list, Size_LinkList(list) - 1);
	printf("-------------\n");
	Foreach_LinkList(list, myprint);

	//销毁链表
	Destroy_LinkList(list);
	printf("\n");
	system("pause");
	return 0;
}
