#pragma once
#define MAXSIZE 1024

struct SeqStack
{
	void *data[MAXSIZE];
	int size;
};

#ifdef __cplusplus
extern "C"{
#endif

	struct SeqStack *Init_SeqStack();
	void Push_SeqStack(struct SeqStack *stack, void *data);
	void Pop_SeqStack(struct SeqStack *stack);
	void *Top_SeqStack(struct SeqStack *stack);
	int Size_SeqStack(struct SeqStack *stack);
	void Destroy_SeqStack(struct SeqStack *stack);

#ifdef __cplusplus
}
#endif