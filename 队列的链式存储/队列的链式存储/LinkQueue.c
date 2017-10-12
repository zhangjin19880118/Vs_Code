#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkQueue.h"

struct LinkNode
{
	void *data;
	struct LinkNode *next;
};

struct LinkQueue
{
	struct LinkNode header;
	int size;
	struct LinkNode *rear;
};

struct LinkQueue *Init_LinkQueue()
{
	struct LinkQueue *queue = (struct LinkQueue *)calloc(1, sizeof(struct LinkQueue));
	queue->header.data = NULL;
	queue->header.next = NULL;
	queue->rear = &(queue->header);
	queue->size = 0;
}

void Push_LinkQueue(struct LinkQueue *queue, void *data)
{
	if (NULL == queue || NULL == data)
		return;
	struct LinkNode *pNew = (struct LinkNode *)calloc(1,sizeof(struct LinkNode));
	pNew->data = data;
	pNew->next = NULL;
	queue->rear->next = pNew;
	queue->rear = pNew;
	queue->size++;
}

void Pop_LinkQueue(struct LinkQueue *queue)
{
	if (NULL == queue)
		return;
	if (0 == queue->size)
		return;
	struct LinkNode *pDel = queue->header.next;
	queue->header.next = pDel->next;
	free(pDel);
	if (1 == queue->size)
		queue->rear = &(queue->header);
	queue->size--;
}

int Size_LinkQueue(struct LinkQueue *queue)
{
	if (NULL == queue)
		return -1;
	return queue->size;
}
void *Front_LinkQueue(struct LinkQueue *queue)
{
	if (NULL == queue)
		return;
	return queue->header.next->data;
}
void *Back_LinkQueue(struct LinkQueue *queue)
{
	if (NULL == queue)
		return;
	return queue->rear->data;
}
void Destroy_LinkQueue(struct LinkQueue *queue)
{
	if (NULL == queue)
		return -1;
	struct LinkNode *pCur = queue->header.next;
	struct LinkNode *pDel = pCur;
	while (pCur!=NULL)
	{
		pCur = pCur->next;
		free(pDel);
		pDel = NULL;
		pDel = pCur;
	}
	free(queue);
}