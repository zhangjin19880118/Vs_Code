/*使用结构体嵌套，存储学生的学号和姓名，以 及每个学生的C、MySQL和Python的成绩。
要求：允许从键盘输入任意数量的学生，以及学生的学号、姓名和各学科成绩。
最后只打印出总成绩最高的学生信息以及其各学科成绩。*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Score		// 保存每个学员的成绩
{
	float c;		// C 语言成绩
	float mysql;	// MySQL成绩
	float python;	// Python 成绩
};

typedef struct
{
	char *name;			// 学员的姓名
	char *id;			// 学员的学号
	struct Score ss;	// 学员的成绩 
} Student;

void sort(float *s, Student *p,  int n)
{
	int i = 0, j = 0;
	Student temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (*(s + j)>*(s + j + 1))
			{
				temp = *(p + j);
				*(p + j) = *(p + j + 1);
				*(p + j + 1) = temp;
			}
		}
	}
}

int main()
{
	int i = 0, n = 0;
	printf("请输入学生的数量:\n");
	scanf("%d", &n);
	Student *p = (Student *)malloc(n*sizeof(Student));
	float *s = (float *)malloc(n*sizeof(float));
	char buf1[20], buf2[20];
	for (i = 0; i < n; ++i)
	{
		printf("请输入第%d学员的姓名:\n",i+1);
		(p + i)->name = (char *)malloc(sizeof(buf1));
		scanf("%s", (p+i)->name);
		printf("请输入第%d学员的学号:\n", i+1);
		(p + i)->id = (char *)malloc(sizeof(buf2));
		scanf("%s", (p + i)->id);
		printf("请输入第%d学员的C语言成绩:\n", i+1);
		scanf("%f", &(p + i)->ss.c);
		printf("请输入第%d学员的MySQL成绩:\n", i+1);
		scanf("%f", &(p + i)->ss.mysql);
		printf("请输入第%d学员的Python成绩:\n", i+1);
		scanf("%f", &(p + i)->ss.python);
		*(s + i) = (p + i)->ss.c + (p + i)->ss.mysql + (p + i)->ss.python;
	}
	sort(s,p,n);
	printf("总成绩最高的学员的姓名:%s\n", (p + n-1)->name);
	printf("总成绩最高的学员的学号:%s\n", (p + n - 1)->id);
	printf("总成绩最高的学员的C语言成绩:%f\n", (p + n - 1)->ss.c);
	printf("总成绩最高的学员的MySQL成绩:%f\n", (p + n - 1)->ss.mysql);
	printf("总成绩最高的学员的Python成绩:%f\n", (p + n - 1)->ss.python);
	return 0;
}