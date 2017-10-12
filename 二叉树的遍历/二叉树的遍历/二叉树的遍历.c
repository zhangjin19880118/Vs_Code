#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct BiNode
{
	char ch;
	struct BiNode *lchild;
	struct BiNode *rchild;
};

void RecursionForeach(struct BiNode *root)
{
	if (NULL == root)
		return;
	printf("%c ", root->ch);
	RecursionForeach(root->lchild);
	RecursionForeach(root->rchild);
}

void CalculateLeafNum(struct BiNode *root,int *num)
{
	if (NULL == root)
		return 0;
	if (NULL == root->lchild && NULL == root->rchild)
		(*num)++;
	CalculateLeafNum(root->lchild, num);
	CalculateLeafNum(root->rchild, num);
}

int GetBiTreeHeight(struct BiNode *root)
{
	if (NULL == root)
		return 0;
	int lHeight = GetBiTreeHeight(root->lchild);
	int rHeight = GetBiTreeHeight(root->rchild);
	return lHeight > rHeight ? lHeight + 1 : rHeight + 1;
}

struct BiNode *CopyBiTree(struct BiNode *root)
{
	if (NULL == root)
		return NULL;
	struct BiNode *NewLBiTree = CopyBiTree(root->lchild);
	struct BiNode *NewRBiTree = CopyBiTree(root->rchild);
	struct BiNode *NewBiTree = (struct BiNode *)calloc(1, sizeof(struct BiNode));
	NewBiTree->ch = root->ch;
	NewBiTree->lchild = NewLBiTree;
	NewBiTree->rchild = NewRBiTree;
	return NewBiTree;
}

void FreeBiTree(struct BiNode *root)
{
	if (NULL == root)
		return;
	FreeBiTree(root->lchild);
	FreeBiTree(root->rchild);
	printf("当前释放的节点为:%c\n", root->ch);
	free(root);
	root = NULL;
}

int main(void)
{
	struct BiNode nodeA = { 'A', NULL, NULL };
	struct BiNode nodeB = { 'B', NULL, NULL };
	struct BiNode nodeC = { 'C', NULL, NULL };
	struct BiNode nodeD = { 'D', NULL, NULL };
	struct BiNode nodeE = { 'E', NULL, NULL };
	struct BiNode nodeF = { 'F', NULL, NULL };
	struct BiNode nodeG = { 'G', NULL, NULL };
	struct BiNode nodeH = { 'H', NULL, NULL };

	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeF;

	nodeB.rchild = &nodeC;

	nodeC.lchild = &nodeD;
	nodeC.rchild = &nodeE;

	nodeF.rchild = &nodeG;
	
	nodeG.lchild = &nodeH;

	RecursionForeach(&nodeA);

	int num = 0;
	CalculateLeafNum(&nodeA, &num);
	printf("\n叶子节点的数目:%d\n", num);

	int treeHeight = GetBiTreeHeight(&nodeA);
	printf("树的高度是:%d\n", treeHeight);

	struct BiNode *NewBiTree = CopyBiTree(&nodeA);
	RecursionForeach(NewBiTree);

	putchar('\n');

	FreeBiTree(NewBiTree);

	printf("\n");
	system("pause");
	return 0;
}
