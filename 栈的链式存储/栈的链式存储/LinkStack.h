#pragma once

#ifdef __cplusplus
extern "C" {
#endif
	
	struct LinkStack *Init_LinkStack();
	void Push_LinkStack(struct LinkStack *stack,void *data);
	void Pop_LinkStack(struct LinkStack *stack);
	void *Top_LinkStack(struct LinkStack *stack);
	int Size_LinkStack(struct LinkStack *stack);
	void Destroy_LinkStack(struct LinkStack *stack);

#ifdef __cplusplus
}
#endif