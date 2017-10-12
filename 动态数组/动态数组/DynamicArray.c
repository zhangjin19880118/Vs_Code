#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"DynamicArray.h"

struct DArray
{
	void **pArray;
	int capacity;
	int size;
};

struct DArray *Init_DynamicArray()
{
	struct DArray *p = (struct DArray *)calloc(1, sizeof(struct DArray));
	p->capacity = 5;
	p->pArray = (void **)calloc(1, p->capacity*sizeof(void *));
	p->size = 0;
}

void Insert_DynamicArray(struct DArray *arr, int pos, void *data)
{
	if (NULL == arr || NULL == data)
		return;
	if (pos<0 || pos>arr->size)
		pos = arr->size;
	if (arr->size == arr->capacity)
	{
		int newcapacity = 2 * arr->capacity;
		void **newspace = (void **)realloc(arr->pArray, newcapacity*sizeof(void *));
		arr->pArray = newspace;
		arr->capacity = newcapacity;
	}
	for (int i = arr->size - 1; i >= pos; i--)
		arr->pArray[i + 1] = arr->pArray[i];
	arr->pArray[pos] = data;
	arr->size++;
}

void Remove_DynamicArray(struct DArray *arr, int pos)
{
	if (NULL == arr)
		return;
	if (pos<0 || pos>arr->size)
		return;
	for (int i = pos; i < arr->size - 1; i++)
		arr->pArray[i] = arr->pArray[i+1];
	arr->size--;
}
void Foreach_DynamicArray(struct DArray *arr, void(*myforeach)(void *data))
{
	if (NULL == arr || NULL == myforeach)
		return;
	for (int i = 0; i < arr->size; i++)
		myforeach(arr->pArray[i]);
}
void Destory_DynamicArray(struct DArray *arr)
{
	if (NULL == arr)
		return;
	if (arr->pArray != NULL)
	{
		free(arr->pArray);
		arr->pArray = NULL;
		arr->capacity = 0;
		arr->size = 0;
	}
	free(arr);
	arr = NULL;
}

