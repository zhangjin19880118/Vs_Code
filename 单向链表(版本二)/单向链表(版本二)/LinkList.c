#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkList.h"

struct LinkList
{
	struct LinkNode header;
	int size;
};

struct LinkList *Init_LinkList()
{
	struct LinkList *list = (struct LinkList *)calloc(1, sizeof(struct LinkList));
	list->header.next = NULL;
	list->size = 0;
}

void Insert_LinkList(struct LinkList *list, int pos, void *data)
{
	if (NULL == list || NULL == data)
		return;
	if (pos < 0 || pos > list->size)
		pos = list->size;
	struct LinkNode *pCur = &(list->header);
	for (int i = 0; i < pos; ++i)
		pCur = pCur->next;
	struct LinkNode *pNew = (struct LinkNode *)data;
	pNew->next = pCur->next;
	pCur->next = pNew;
	list->size++;
}

void Remove_LinkList(struct LinkList *list, int pos)
{
	if (NULL == list)
		return;
	if (pos < 0 || pos > list->size)
		return;
	struct LinkNode *pCur = &(list->header);
	for (int i = 0; i < pos; ++i)
		pCur = pCur->next;
	struct LinkNode *pDel = pCur->next;
	pCur->next = pDel->next;
	list->size--;
}

void Foreach_LinkList(struct LinkList *list, void(*myforeach)(void *data))
{
	if (NULL == list || NULL == myforeach)
		return;
	struct LinkNode *pCur = list->header.next;
	for (int i = 0; i < list->size; ++i)
	{
		myforeach(pCur);
		pCur = pCur->next;
	}
}

void Destroy_LinkList(struct LinkList *list)
{
	if (NULL == list)
		return;
	free(list);
	list = NULL;
}