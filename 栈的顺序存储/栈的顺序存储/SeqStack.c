#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"SeqStack.h"

struct SeqStack *Init_SeqStack()
{
	struct SeqStack *stack = (struct SeqStack *)calloc(1, sizeof(struct SeqStack));
	stack->size = 0;
}

void Push_SeqStack(struct SeqStack *stack, void *data)
{
	if (NULL == stack || NULL == data)
		return;
	if (MAXSIZE == stack->size)
		return;
	stack->data[stack->size] = data;
	stack->size++;
}

void Pop_SeqStack(struct SeqStack *stack)
{
	if (NULL == stack)
		return;
	if (0 == stack->size)
		return;
	stack->size--;
}

void *Top_SeqStack(struct SeqStack *stack)
{
	if (NULL == stack)
		return;
	if (0 == stack->size)
		return NULL;
	return stack->data[stack->size - 1];
}

int Size_SeqStack(struct SeqStack *stack)
{
	if (NULL == stack)
		return;
	return stack->size;
}

void Destroy_SeqStack(struct SeqStack *stack)
{
	if (NULL == stack)
		return;
	free(stack);
	stack = NULL;
}