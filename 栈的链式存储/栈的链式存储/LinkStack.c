#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkStack.h"

struct LinkNode
{
	void *data;
	struct LinkNode *next;
};

struct LinkStack
{
	struct LinkNode header;
	int size;
	//struct LinkNode *rear;
};

struct LinkStack *Init_LinkStack()
{
	struct LinkStack *stack = (struct LinkStack *)calloc(1, sizeof(struct LinkStack));
	stack->header.data = NULL;
	stack->header.next = NULL;
	stack->size = 0;
}

void Push_LinkStack(struct LinkStack *stack, void *data)
{
	if (NULL == stack || NULL == data)
		return;
	struct LinkNode *pNew = (struct LinkNode *)calloc(1, sizeof(struct LinkNode));
	pNew->data = data;
	pNew->next = NULL;
	struct LinkNode *pCur = &(stack->header);
	pNew->next = pCur->next;
	pCur->next = pNew;
	stack->size++;
}

void Pop_LinkStack(struct LinkStack *stack)
{
	if (NULL == stack)
		return;
	if (0 == stack->size)
		return;
	struct LinkNode *pCur = stack->header.next;
	stack->header.next = pCur->next;
	stack->size--;
}

void *Top_LinkStack(struct LinkStack *stack)
{
	if (NULL == stack)
		return NULL;
	if (0 == stack->size)
		return NULL;
	return (stack->header.next)->data;
}

int Size_LinkStack(struct LinkStack *stack)
{
	if (NULL == stack)
		return;
	return stack->size;
}

void Destroy_LinkStack(struct LinkStack *stack)
{
	if (NULL == stack)
		return;
	struct LinkNode *pCur = stack->header.next;
	struct LinkNode *pDel = pCur;
	for (int i = 0; i < stack->size; ++i)
	{
		pCur = pCur->next;
		stack->header.next = pCur;
		if (pDel != NULL)
		{
			free(pDel);
			pDel = NULL;
		}
		pDel = pCur;
	}
	free(stack);
}
