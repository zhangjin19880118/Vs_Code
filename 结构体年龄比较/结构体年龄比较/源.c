#include <stdio.h>
#include <string.h>

struct stu
{
	char name[50];
	unsigned int age;
	int score;
};

int main()
{
	int i = 0, j = 0;
	struct stu temp;
	struct stu obj[5] = {
		{ "mike", 18, 90 },
		{ "jiang", 18, 80 },
		{ "lily", 30, 70 },
		{ "lucy", 22, 88 },
		{ "lilei", 33, 60 }
	};
	for (i = 0; i < 5; ++i)
		printf("%s% d% d\n", obj[i].name, obj[i].age, obj[i].score);
	printf("\n");
	for (i = 0; i < 4; ++i)
	{
		for (j = 0; j < 4 - i; ++j)
		{
			if (obj[j].age>obj[j+1].age)
			{
				temp = obj[j];
				obj[j] = obj[j + 1];
				obj[j + 1] = temp;
			}
			else if (obj[j].age == obj[j + 1].age)
			{
				if (obj[j].score > obj[j + 1].score)
				{
					temp = obj[j];
					obj[j] = obj[j + 1];
					obj[j + 1] = temp;
				}
			}
		}
	}
	for (i = 0; i < 5; ++i)
		printf("%s% d% d\n", obj[i].name, obj[i].age, obj[i].score);
	return 0;
}