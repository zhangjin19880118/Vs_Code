#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LinkStack.h"

struct person
{
	char name[64];
	int age;
};

void test()
{
	//��ʼ��ջ
	struct LinkStack *stack = Init_LinkStack();
	//��������
	struct person p1 = { "aaa", 10 };
	struct person p2 = { "bbb", 20 };
	struct person p3 = { "ccc", 30 };
	//������ջ
	Push_LinkStack(stack, &p1);
	Push_LinkStack(stack, &p2);
	Push_LinkStack(stack, &p3);

	//���ջ������Ԫ��
	while (Size_LinkStack(stack) > 0)
	{
		//�Ȼ��ջ��Ԫ��
		struct person *p = (struct person *)Top_LinkStack(stack);
		printf("Name:%s Age:%d\n", p->name, p->age);
		//����ջ��Ԫ��
		Pop_LinkStack(stack);
	}

	//����ջ
	Destroy_LinkStack(stack);

}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}