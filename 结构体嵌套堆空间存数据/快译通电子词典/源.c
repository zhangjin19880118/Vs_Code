/*ʹ�ýṹ��Ƕ�ף��洢ѧ����ѧ�ź��������� ��ÿ��ѧ����C��MySQL��Python�ĳɼ���
Ҫ������Ӽ�����������������ѧ�����Լ�ѧ����ѧ�š������͸�ѧ�Ƴɼ���
���ֻ��ӡ���ܳɼ���ߵ�ѧ����Ϣ�Լ����ѧ�Ƴɼ���*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Score		// ����ÿ��ѧԱ�ĳɼ�
{
	float c;		// C ���Գɼ�
	float mysql;	// MySQL�ɼ�
	float python;	// Python �ɼ�
};

typedef struct
{
	char *name;			// ѧԱ������
	char *id;			// ѧԱ��ѧ��
	struct Score ss;	// ѧԱ�ĳɼ� 
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
	printf("������ѧ��������:\n");
	scanf("%d", &n);
	Student *p = (Student *)malloc(n*sizeof(Student));
	float *s = (float *)malloc(n*sizeof(float));
	char buf1[20], buf2[20];
	for (i = 0; i < n; ++i)
	{
		printf("�������%dѧԱ������:\n",i+1);
		(p + i)->name = (char *)malloc(sizeof(buf1));
		scanf("%s", (p+i)->name);
		printf("�������%dѧԱ��ѧ��:\n", i+1);
		(p + i)->id = (char *)malloc(sizeof(buf2));
		scanf("%s", (p + i)->id);
		printf("�������%dѧԱ��C���Գɼ�:\n", i+1);
		scanf("%f", &(p + i)->ss.c);
		printf("�������%dѧԱ��MySQL�ɼ�:\n", i+1);
		scanf("%f", &(p + i)->ss.mysql);
		printf("�������%dѧԱ��Python�ɼ�:\n", i+1);
		scanf("%f", &(p + i)->ss.python);
		*(s + i) = (p + i)->ss.c + (p + i)->ss.mysql + (p + i)->ss.python;
	}
	sort(s,p,n);
	printf("�ܳɼ���ߵ�ѧԱ������:%s\n", (p + n-1)->name);
	printf("�ܳɼ���ߵ�ѧԱ��ѧ��:%s\n", (p + n - 1)->id);
	printf("�ܳɼ���ߵ�ѧԱ��C���Գɼ�:%f\n", (p + n - 1)->ss.c);
	printf("�ܳɼ���ߵ�ѧԱ��MySQL�ɼ�:%f\n", (p + n - 1)->ss.mysql);
	printf("�ܳɼ���ߵ�ѧԱ��Python�ɼ�:%f\n", (p + n - 1)->ss.python);
	return 0;
}