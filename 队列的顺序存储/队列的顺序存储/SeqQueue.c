#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqQueue.h"

struct SeqQueue *Init_SeqQueue()
{
	struct SeqQueue *queue = (struct SeqQueue *)calloc(1,sizeof(struct SeqQueue));
	queue->size = 0;
	return queue;
}

void Push_SeqQueue(struct SeqQueue *queue, void *data)
{
	if (NULL == queue || NULL == data)
		return;
	if (MAXSIZE == queue->size)
		return;
	queue->data[queue->size] = data;
	queue->size++;
}

void Pop_SeqQueue(struct SeqQueue *queue)
{
	if (NULL == queue)
		return;
	if (0 == queue->size)
		return;
	for (int i = 0; i < queue->size; ++i)
		queue->data[i] = queue->data[i + 1];
	queue->size--;
}

void *Front_SeqQueue(struct SeqQueue *queue)
{
	if (NULL == queue)
		return;
	return queue->data[0];
}

void *Back_SeqQueue(struct SeqQueue *queue)
{
	if (NULL == queue)
		return;
	return queue->data[queue->size-1];
}
int Size_SeqQueue(struct SeqQueue *queue)
{
	if (NULL == queue)
		return -1;
	return queue->size;
}

void Destroy_SeqQueue(struct SeqQueue *queue)
{
	if (NULL == queue)
		return;
	free(queue);
	queue = NULL;
}