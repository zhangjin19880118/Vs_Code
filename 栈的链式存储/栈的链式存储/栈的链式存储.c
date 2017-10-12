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
	//初始化栈
	struct LinkStack *stack = Init_LinkStack();
	//创建数据
	struct person p1 = { "aaa", 10 };
	struct person p2 = { "bbb", 20 };
	struct person p3 = { "ccc", 30 };
	//数据入栈
	Push_LinkStack(stack, &p1);
	Push_LinkStack(stack, &p2);
	Push_LinkStack(stack, &p3);

	//输出栈中所有元素
	while (Size_LinkStack(stack) > 0)
	{
		//先获得栈顶元素
		struct person *p = (struct person *)Top_LinkStack(stack);
		printf("Name:%s Age:%d\n", p->name, p->age);
		//弹出栈顶元素
		Pop_LinkStack(stack);
	}

	//销毁栈
	Destroy_LinkStack(stack);

}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}