#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
	int id;		//������
	struct Node *next;	//ָ����
}SLIST;

//1. �ѿ����ϵ�������Ļ�������������һ�顣
//����ͷ�ڵ㣬�����ͷ����ַ�ɺ���ֵ���ء�
SLIST *SListCreat()
{
	SLIST *head = (SLIST *)malloc(sizeof(SLIST));
	head->next = NULL;
	SLIST *pCur = head;
	SLIST *pNew = NULL;
	int data;
	while (1)
	{
		printf("����������: ");
		scanf("%d", &data);
		if (data < 0)
			break;
		pNew = (SLIST *)malloc(sizeof(SLIST));
		pNew->id = data;
		pNew->next = NULL;
		pCur->next = pNew;
		pCur = pNew;
	}
	return head;
}

//�����ڵ�
//˳�������������������������е�����
int SListPrint(SLIST *pHead)
{
	if (NULL == pHead || NULL == pHead->next)
		return -1;
	pHead = pHead->next;
	printf("head -> ");
	while (pHead!=NULL)
	{
		printf("%d -> ", pHead->id);
		pHead = pHead->next;
	}
	printf("NULL\n");
	return 0;
}

//��ֵΪx�Ľ��ǰ������ֵΪy�Ľ�㣻
//��ֵΪx�Ľ�㲻���ڣ�����ڱ�β
int SListNodeInsert(SLIST *pHead, int x, int y)
{
	SLIST *pPre = pHead;
	SLIST *pCur = pHead->next;
	SLIST *pNew = NULL;
	int flag = 0;
	if (NULL == pHead || NULL == pHead->next)
		return -1;
	while (pCur != NULL)
	{
		if (x == pCur->id)
		{
			pNew = (SLIST *)malloc(sizeof(SLIST));
			pNew->id = y;
			pPre->next = pNew;
			pNew->next = pCur;
			flag = 1;
			break;
		}
		pPre = pPre->next;
		pCur = pCur->next;
	}
	if (0 == flag)
	{
		pNew = (SLIST *)malloc(sizeof(SLIST));
		pNew->id = y;
		pPre->next = pNew;
		pNew->next = pCur;
	}
	return 0;
}

//ɾ����һ��ֵΪx�Ľ��
int SListNodeDel(SLIST *pHead, int x)
{
	SLIST *pPre = pHead;
	SLIST *pCur = pHead->next;
	if (NULL == pHead || NULL == pHead->next)
		return -1;
	while (pCur != NULL)
	{
		if (x == pCur->id)
		{
			pPre->next = pCur->next;
			free(pCur);
			pCur = NULL;
			break;
		}
		pPre = pPre->next;
		pCur = pCur->next;
	}
	return 0;
}

//�ͷ����нڵ�
int SListDestroy(SLIST *pHead)
{
	SLIST *pDel = pHead;
	SLIST *pCur = pHead;
	if (NULL == pHead || NULL == pHead->next)
		return -1;
	while (pCur != NULL)
	{
		pCur = pCur->next;
		free(pDel);
		pDel = pCur;
	}
	return 0;
}


//2. ������ϰ(����Ч���ο�<�����������.exe>)��
//ɾ��ֵΪx�����н��
int SListNodeDelPro(SLIST *pHead, int x)
{
	SLIST *pPre = pHead;
	SLIST *pCur = pHead->next;
	if (NULL == pHead || NULL == pHead->next)
		return -1;
	while (pCur != NULL)
	{
		if (x == pCur->id)
		{
			pPre->next = pCur->next;
			free(pCur);
			pCur = pPre->next;
			continue;
		}
		pPre = pPre->next;
		pCur = pCur->next;
	}
	return 0;
}

//����ڵ����򣬽�������������
int SListNodeSort(SLIST *pHead)
{
	SLIST *pPre = NULL;
	SLIST *pCur = NULL;
	int temp;
	if (NULL == pHead || NULL == pHead->next)
		return -1;
	for (pPre = pHead->next; pPre->next != NULL; pPre = pPre->next)
	{
		for (pCur = pPre->next; pCur != NULL; pCur = pCur->next)
		{
			if (pPre->id > pCur->id)
			{
				temp = pPre->id;
				pPre->id = pCur->id;
				pCur->id = temp;
			}
		}
	}
	return 0;
}
//ע�⣬����nextָ�뻹��Ҫ����
/*if (pPre->id > pCur->id) //����
{
	//�����ڵ�����
	tmp = *pCur;
	*pCur = *pPre;
	*pPre = tmp;

	//�����½���һ��nextָ����
	tmp.next = pCur->next;
	pCur->next = pPre->next;
	pPre->next = tmp.next;
}*/

//����ԭ�������������,��������½ڵ�
//���ܲ���ڵ������������������½ڵ�x
int SListNodeInsertPro(SLIST *pHead, int x)
{
	SLIST *pPre = pHead;
	SLIST *pCur = pHead->next;
	SLIST *pNew = NULL;
	int flag = 0;
	if (NULL == pHead || NULL == pHead->next)
		return -1;
	pPre = pPre->next;
	pCur = pCur->next;
	while (pCur != NULL)
	{
		if (x >= pPre->id && x <= pCur->id)
		{
			pNew = (SLIST *)malloc(sizeof(SLIST));
			pNew->id = x;
			pPre->next = pNew;
			pNew->next = pCur;
			flag = 1;
			break;
		}
		pPre = pPre->next;
		pCur = pCur->next;
	}
	if (0 == flag)
	{
		pNew = (SLIST *)malloc(sizeof(SLIST));
		pNew->id = x;
		pPre->next = pNew;
		pNew->next = pCur;
	}
	return 0;
}

//��ת����Ľڵ㣨���������Ƿ�ת������������ָ����
//���磺ԭ����ΪA->B->C->D,ʹ�������ó�ΪD->C->B->A
int SListNodeReverse(SLIST *pHead)
{
	SLIST *pPre = pHead;
	SLIST *pCur = pHead->next;
	SLIST *pTemp = NULL;
	pPre = pPre->next;
	pCur = pCur->next;
	if (NULL == pHead || NULL == pHead->next || NULL == pCur->next)
		return -1;
	while (pCur!=NULL)
	{
		pTemp = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = pTemp;
	}
	pHead->next->next = NULL;
	pHead->next = pPre;
}

int main(void)
{
	SLIST *pHead = NULL;

	pHead = SListCreat(); //����ͷ���
	printf("\n����ͷ����\n");
	SListPrint(pHead); //�������нڵ�

	SListNodeDelPro(pHead, 4);//ɾ������ֵΪ4�Ľ��
	printf("\nɾ������ֵΪ4�Ľ��\n");
	SListPrint(pHead); //�������нڵ�

	SListNodeSort(pHead);//����ڵ�����
	printf("\n����ڵ�����\n");
	SListPrint(pHead); //�������нڵ�

	SListNodeInsertPro(pHead, 5);//�������5
	printf("\n�������5��\n");
	SListPrint(pHead); //�������нڵ�

	//��ת����Ľڵ㣨���������Ƿ�ת��
	SListNodeReverse(pHead);
	printf("\n��ת����Ľڵ�\n");
	SListPrint(pHead); //�������нڵ�

	SListDestroy(pHead);//�ͷ����нڵ�
	pHead = NULL;

	printf("\n");
	system("pause");
	return 0;
}
