#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"SeqStack.h"

struct person
{
	char name[64];
	int age;
};

void test()
{
	//��ʼ��ջ
	struct SeqStack *stack = Init_SeqStack();
	//��������
	struct person p1 = { "aaa", 10 };
	struct person p2 = { "bbb", 20 };
	struct person p3 = { "ccc", 30 };
	//������ջ
	Push_SeqStack(stack, &p1);
	Push_SeqStack(stack, &p2);
	Push_SeqStack(stack, &p3);

	//���ջ������Ԫ��
	while (Size_SeqStack(stack) > 0)
	{
		//�Ȼ��ջ��Ԫ��
		struct person *p = (struct person *)Top_SeqStack(stack);
		printf("Name:%s Age:%d\n", p->name, p->age);
		//����ջ��Ԫ��
		Pop_SeqStack(stack);
	}

	//����ջ
	Destroy_SeqStack(stack);

}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}