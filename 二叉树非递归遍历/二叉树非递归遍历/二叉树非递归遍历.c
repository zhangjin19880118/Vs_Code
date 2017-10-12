#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include"SeqStack.h"

struct BiTreeNode
{
	char ch;
	struct BiTreeNode *lchild;
	struct BiTreeNode *rchild;
};

struct Info
{
	struct BiTreeNode *node;
	bool flag;
};

struct Info *CreateInfo(struct BiTreeNode *node, bool flag)
{
	struct Info *info = (struct Info *)calloc(1, sizeof(struct Info));
	info->node = node;
	info->flag = flag;
	return info;
}

void NonRecursion(struct BiTreeNode *root)
{
	if (NULL == root)
		return;
	struct SeqStack *stack = Init_SeqStack();
	Push_SeqStack(stack, CreateInfo(root, false));
	while (Size_SeqStack(stack))
	{
		struct Info *info = (struct Info *)Top_SeqStack(stack);
		Pop_SeqStack(stack);
		if (info->flag)
		{
			printf("%c ", info->node->ch);
			free(info);
			continue;
		}
		if (info->node->rchild)
			Push_SeqStack(stack, CreateInfo(info->node->rchild, false));
		if (info->node->lchild)
			Push_SeqStack(stack, CreateInfo(info->node->lchild, false));
		Push_SeqStack(stack, info);
		info->flag = true;
	}
	Destroy_SeqStack(stack);
}

int main(void)
{
	struct BiTreeNode nodeA = { 'A', NULL, NULL };
	struct BiTreeNode nodeB = { 'B', NULL, NULL };
	struct BiTreeNode nodeC = { 'C', NULL, NULL };
	struct BiTreeNode nodeD = { 'D', NULL, NULL };
	struct BiTreeNode nodeE = { 'E', NULL, NULL };
	struct BiTreeNode nodeF = { 'F', NULL, NULL };
	struct BiTreeNode nodeG = { 'G', NULL, NULL };
	struct BiTreeNode nodeH = { 'H', NULL, NULL };

	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeF;

	nodeB.rchild = &nodeC;

	nodeC.lchild = &nodeD;
	nodeC.rchild = &nodeE;

	nodeF.rchild = &nodeG;

	nodeG.lchild = &nodeH;

	NonRecursion(&nodeA);

	printf("\n");
	system("pause");
	return 0;
}
