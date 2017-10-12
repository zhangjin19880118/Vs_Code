#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _tag_listnode
{
	int data;
	struct _tag_listnode *next;
}ListNode;

ListNode *CreatLinkList()
{
	ListNode *head = NULL;
	ListNode *pNew = NULL; 
	ListNode *pCur = NULL; 
	int data;
	head = (ListNode *)malloc(sizeof(ListNode));
	head->next = NULL;
	pCur = head;
	while (1)
	{
		printf("���������֣�");
		scanf("%d", &data);
		if (data < 0)
			break;
		pNew = (ListNode *)malloc(sizeof(ListNode));
		pNew->data = data;
		pCur->next = pNew;
		pNew->next = NULL;
		pCur = pNew;
	}
	return head;
}

void Reverse_LinkList(ListNode *head)
{
	ListNode *pPre = NULL;
	ListNode  *pCur = head->next;
	ListNode  *pNext = NULL;
	if (NULL == head)
		return;
	while (pCur!=NULL)
	{
		pNext = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = pNext;	
	}
	head->next = pPre;
}

int findLastKNode(ListNode *head,int k)
{
	for (int i = 0; i < k; ++i)
	{
		head = head->next;
		if (NULL == head)
		{
			printf("�����kֵԽ��!\n");
			return -1;
		}
	}
		
	printf("%d\n", head->data);
	return 0;
}

int main(void)
{
	int k;
	ListNode *head = CreatLinkList();
	Reverse_LinkList(head);
	printf("������Ҫ���ҵĵ����ڼ����ڵ�:");
	scanf("%d", &k);
	findLastKNode(head, k);

	printf("\n");
	system("pause");
	return 0;
}
