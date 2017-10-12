#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkList.h"

struct LinkNode
{
	void *data;
	struct LinkNode *next;
};

struct LList
{
	struct LinkNode header;
	int size;
	//struct LinkNode *rear;
};

struct LList *Init_LinkList()
{
	struct LList *list = (struct LList *)calloc(1, sizeof(struct LList));
	list->header.data = NULL;
	list->header.next = NULL;
	list->size = 0;
}

void Insert_LinkList(struct LList *list, int pos, void *data)
{
	if (NULL == list || NULL == data)
		return;
	if (pos < 0 || pos > list->size)
		pos = list->size;
	struct LinkNode  *pCur = &(list->header);
	for (int i = 0; i < pos; ++i)
		pCur = pCur->next;
	struct LinkNode  *pNew = (struct LinkNode  *)calloc(1, sizeof(struct LinkNode));
	pNew->data = data;
	pNew->next = NULL;

	pNew->next = pCur->next;
	pCur->next = pNew;
	list->size++;
}

void Remove_LinkList(struct LList *list, int pos)
{
	if (NULL == list)
		return;
	if (pos < 0 || pos > list->size)
		return;
	struct LinkNode  *pCur = &(list->header);
	for (int i = 0; i < pos; ++i)
		pCur = pCur->next;
	struct LinkNode *pDel = pCur->next;
	pCur->next = pDel->next;
	if (pDel != NULL)
	{
		free(pDel);
		pDel = NULL;
	}
	list->size--;
}

void Foreach_LinkList(struct LList *list, void (*myforeach)(void *data))
{
	if (NULL == list || NULL == myforeach)
		return;
	struct LinkNode  *pCur = list->header.next;
	for (int i = 0; i < list->size; ++i)
	{
		myforeach(pCur->data);
		pCur = pCur->next;
	}
}

void Destroy_LinkList(struct LList *list)
{
	if (NULL == list)
		return;
	struct LinkNode  *pCur = list->header.next;
	struct LinkNode *pDel = pCur;
	for (int i = 0; i < list->size; ++i)
	{
		pCur = pCur->next;
		if (pDel != NULL)
		{
			free(pDel);
			pDel = NULL;
		}
		pDel = pCur;
	}
	free(list);
	list = NULL;
}

int Size_LinkList(struct LList *list)
{
	if (NULL == list)
		return -1;
	return list->size;
}

void *Search_LinkList(struct LList *list, void *data, bool(*compare)(void *data1, void *data2))
{
	if (NULL == list || NULL==data || NULL==compare)
		return NULL;
	struct LinkNode  *pCur = list->header.next;
	for (int i = 0; i < list->size; ++i)
	{
		if (compare(data, pCur->data))
			break;
		pCur = pCur->next;
	}
	if (NULL == pCur)
		return NULL;
	return pCur->data;
}

void ReverseForeach_LinkList(struct LList *list, void(*myforeach)(void *data))
{
	if (NULL == list || NULL == myforeach)
		return;
	RecursionForeach(list->header.next, myforeach);
}

static void RecursionForeach(struct LinkNode *node, void(*myforeach)(void *data))
{
	if (NULL == node || NULL == myforeach)
		return;
	RecursionForeach(node->next,myforeach);
	myforeach(node->data);
}

void Reverse_LinkList(struct LList *list)
{
	if (NULL == list)
		return;
	struct LinkNode  *pPre = NULL;
	struct LinkNode  *pCur = list->header.next;
	struct LinkNode  *pNext = NULL;
	for (int i = 0; i < list->size; i++)
	{
		pNext = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = pNext;
	}
	list->header.next = pPre;
}

void Sort_LinkList(struct LList *list, int(*compare)(void *data1, void *data2))
{
	for (struct LinkNode *pCur = list->header.next; pCur->next != NULL; pCur = pCur->next)
	{
		struct LinkNode *pTemp = pCur;
		for (struct LinkNode *pNext = pCur->next; pNext != NULL; pNext = pNext->next)
		{
			if (compare(pTemp->data, pNext->data))
			{
				pTemp = pNext;
			}
		}
		if (pTemp != pCur)
		{
			void *temp = pCur->data;
			pCur->data = pTemp->data;
			pTemp->data = temp;
		}
	}
}
