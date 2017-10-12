#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct man
{
	int no;
	struct man *next;
}man_t;

man_t *CreatLinkList()
{
	man_t *head = NULL;
	man_t *pNew = NULL;
	man_t *pCur = NULL;
	int data;
	head = (man_t *)malloc(sizeof(man_t));
	head->next = NULL;
	pCur = head;
	while (1)
	{
		printf("请输入数字：");
		scanf("%d", &data);
		if (data < 0)
			break;
		pNew = (man_t *)malloc(sizeof(man_t));
		pNew->no = data;
		pCur->next = pNew;
		pNew->next = NULL;
		pCur = pNew;
	}
	return head;
}

void insertHeadList(man_t *phead, int newno)
{
	man_t *pNew = (man_t *)calloc(1, sizeof(man_t));
	man_t *pCur = phead;
	if (NULL == phead)
		return;
	pNew->no = newno;
	pNew->next = NULL;
	pNew->next = pCur->next;
	pCur->next = pNew;
}

int main(void)
{
	int newno;
	man_t *head = CreatLinkList();
	printf("请输入新节点的数据:");
	scanf("%d", &newno);
	insertHeadList(head, newno);
	printf("新节点的数据为%d:",head->next->no);
	printf("\n");
	system("pause");
	return 0;
}
