#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LinkQueue.h"

struct person
{
	char name[64];
	int age;
};

void test()
{
	struct LinkQueue *queue = Init_LinkQueue();
	struct person p1 = { "aaa", 10 };
	struct person p2 = { "bbb", 20 };
	struct person p3 = { "ccc", 30 };
	struct person p4 = { "ddd", 40 };

	Push_LinkQueue(queue, &p1);
	Push_LinkQueue(queue, &p2);
	Push_LinkQueue(queue, &p3);
	Push_LinkQueue(queue, &p4);

	struct person *pFront = Front_LinkQueue(queue);
	struct person *pBack = Back_LinkQueue(queue);
	printf("Front Name:%s Age:%d\n", pFront->name, pFront->age);
	printf("Back Name:%s Age:%d\n", pBack->name, pBack->age);


	while (Size_LinkQueue(queue) > 0)
	{
		struct person *p = (struct person *)Front_LinkQueue(queue);
		printf("Name:%s Age:%d\n", p->name, p->age);
		Pop_LinkQueue(queue);
	}

	Destroy_LinkQueue(queue);
}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}