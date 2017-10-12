#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
	int id;		//数据域
	struct Node *next;	//指针域
}SLIST;

//1. 把课堂上单向链表的基本操作重新敲一遍。
//创建头节点，链表的头结点地址由函数值返回。
SLIST *SListCreat()
{
	SLIST *head = (SLIST *)malloc(sizeof(SLIST));
	head->next = NULL;
	SLIST *pCur = head;
	SLIST *pNew = NULL;
	int data;
	while (1)
	{
		printf("请输入数据: ");
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

//遍历节点
//顺序输出单向链表各项结点数据域中的内容
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

//在值为x的结点前，插入值为y的结点；
//若值为x的结点不存在，则插在表尾
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

//删除第一个值为x的结点
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

//释放所有节点
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


//2. 链表练习(运行效果参考<链表基本操作.exe>)。
//删除值为x的所有结点
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

//链表节点排序，交换的是数据域
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
//注意，排序，next指针还需要交换
/*if (pPre->id > pCur->id) //升序
{
	//交换节点整体
	tmp = *pCur;
	*pCur = *pPre;
	*pPre = tmp;

	//再重新交换一下next指针域
	tmp.next = pCur->next;
	pCur->next = pPre->next;
	pPre->next = tmp.next;
}*/

//假如原来链表是升序的,升序插入新节点
//不能插入节点后再排序，是升序插入新节点x
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

//翻转链表的节点（不是排序，是翻转），交换的是指针域
//例如：原链表为A->B->C->D,使链表逆置成为D->C->B->A
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

	pHead = SListCreat(); //创建头结点
	printf("\n创建头结点后\n");
	SListPrint(pHead); //遍历所有节点

	SListNodeDelPro(pHead, 4);//删除所有值为4的结点
	printf("\n删除所有值为4的结点\n");
	SListPrint(pHead); //遍历所有节点

	SListNodeSort(pHead);//链表节点排序
	printf("\n链表节点排序\n");
	SListPrint(pHead); //遍历所有节点

	SListNodeInsertPro(pHead, 5);//升序插入5
	printf("\n升序插入5后\n");
	SListPrint(pHead); //遍历所有节点

	//翻转链表的节点（不是排序，是翻转）
	SListNodeReverse(pHead);
	printf("\n翻转链表的节点\n");
	SListPrint(pHead); //遍历所有节点

	SListDestroy(pHead);//释放所有节点
	pHead = NULL;

	printf("\n");
	system("pause");
	return 0;
}
