#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student
{
	char *name;
	int id;
	int name_len;
}Stu;

void write_file(Stu s)
{
	FILE *fp = fopen("1.txt", "w");
	if (!fp)
	{
		perror("w open 1.txt error!\n");
		return ;
	}
	fwrite(&s, 1, sizeof(Stu), fp);
	fwrite(s.name, 1, s.name_len+1, fp);
	if (!s.name)
	{
		free(s.name);
		s.name = NULL;
	}
	fclose(fp);
	fp = NULL;
}

void read_file()
{
	Stu st;
	FILE *fp = fopen("1.txt", "r");
	if (!fp)
	{
		perror("r open 1.txt error!\n");
		return;
	}
	fread(&st, 1, sizeof(st), fp);
	st.name = (char *)malloc(st.name_len+1);
	fread(st.name, 1, st.name_len+1, fp);
	printf("%s,%d,%d\n",st.name, st.id, st.name_len);
	if (!st.name)
	{
		free(st.name);
		st.name = NULL;
	}
	fclose(fp);
	fp = NULL;
}

int main()
{
	Stu s;
	s.id = 1;
	s.name_len = strlen("mike");
	s.name = (char *)malloc(s.name_len + 1);
	strcpy(s.name, "mike");
	write_file(s);
	read_file();
	return 0;
}