#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"SeqQueue.h"

struct person
{
	char name[64];
	int age;
};

void test()
{
	struct SeqQueue *queue = Init_SeqQueue();
	struct person p1 = { "aaa", 10 };
	struct person p2 = { "bbb", 20 };
	struct person p3 = { "ccc", 30 };
	struct person p4 = { "ddd", 40 };

	Push_SeqQueue(queue, &p1);
	Push_SeqQueue(queue, &p2);
	Push_SeqQueue(queue, &p3);
	Push_SeqQueue(queue, &p4);

	struct person *pFront = (struct person *)Front_SeqQueue(queue);
	struct person *pBack = (struct person *)Back_SeqQueue(queue);
	printf("Front Name:%s Age:%d\n", pFront->name, pFront->age);
	printf("Back Name:%s Age:%d\n", pBack->name, pBack->age);

	while (Size_SeqQueue(queue))
	{
		pFront = (struct person *)Front_SeqQueue(queue);
		printf("Name:%s Age:%d\n", pFront->name, pFront->age);
		Pop_SeqQueue(queue);
	}
	
	Destroy_SeqQueue(queue);
}

int main()
{
	test();
	system("pause");
	return EXIT_SUCCESS;
}