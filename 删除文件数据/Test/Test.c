#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student
{
	char name[20];
	int age;
}student;

void print_menu()
{
	printf("**************************\n");
	printf("* 1 输入信息\n");
	printf("* 2 查询信息\n");
	printf("* 3 删除用户\n");
	printf("* 4 清除屏幕\n");
	printf("* 5 退出程序\n");
	printf("**************************\n");
}

void write_file()
{
	student stu = {0};
	FILE *fp = fopen("demo.txt","ab");
	if (!fp)
	{
		perror("ab fopen error!\n");
		return;
	}
	while (1)
	{		
		printf("please input name:");
		scanf("%s", stu.name);
		printf("please input age:");
		scanf("%d", &stu.age);
		if (stu.age < 0)
			break;
		fwrite(&stu, sizeof(student), 1, fp);
		memset(&stu, 0, sizeof(student));
	} 
	fclose(fp);
	fp = NULL;
}

void read_file()
{
	student stu = { 0 };
	FILE *fp = fopen("demo.txt", "rb");
	if (!fp)
	{
		perror("rb fopen error!\n");
		return;
	}
	printf("name\tage\n");
	while (1)
	{
		fread(&stu,sizeof(student),1,fp);
		if (feof(fp))
			break;
		printf("%s\t%d\n",stu.name,stu.age);
		memset(&stu, 0, sizeof(student));
	}
	fclose(fp);
	fp = NULL;
}

void del_struct()
{
	FILE *fp = fopen("demo.txt", "rb");
	if (!fp)
	{
		perror("rb fopen error!\n");
		return;
	}
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	int n = size / sizeof(student);
	student *p = (student *)calloc(n, sizeof(student));
	fread(p, 1, n*sizeof(student), fp);
	fclose(fp);
	fp = NULL;
	fp = fopen("demo.txt", "wb");
	if (!fp)
	{
		perror("wb fopen error!\n");
		return;
	}
	char buf[128] = { 0 };
	printf("please input name:");
	scanf("%s", buf);
	for (int i = 0; i < n; ++i)
	{
		if (strcmp(buf, (p + i)->name))
			fwrite(p + i,sizeof(student),1,fp);
	}
	fclose(fp);
	fp = NULL;
	printf("%s删除成功\n", buf);
	read_file(); //显示信息
}

int main(void)
{
	int num=0;
	while (1)
	{
		print_menu();
		printf("cmd:");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			write_file();
			break;
		case 2:
			read_file();
			break;
		case 3:
			del_struct();
			break;
		case 4:
			system("cls");
			break;
		case 5:
			return 0;
			break;
		default:
			break;
		}
	}


	printf("\n");
	system("pause");
	return 0;
}

