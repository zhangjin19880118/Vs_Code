#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkList.h"

struct person
{
	struct LinkNode node;
	char name[64];
	int age;
};

void myprint(void *data)
{
	struct person *p = (struct person *)data;
	printf("Name:%s Age:%d\n", p->name, p->age);
}

void test()
{

	//≥ı ºªØ¡¥±Ì
	struct LinkList *list = Init_LinkList();

	struct person p1 = { NULL, "aaa", 10 };
	struct person p2 = { NULL, "bbb", 20 };
	struct person p3 = { NULL, "ccc", 30 };

	Insert_LinkList(list, 0, &p1);
	Insert_LinkList(list, 0, &p2);
	Insert_LinkList(list, 0, &p3);

	Foreach_LinkList(list, myprint);
}

int main(void)
{
	test();

	printf("\n");
	system("pause");
	return 0;
}