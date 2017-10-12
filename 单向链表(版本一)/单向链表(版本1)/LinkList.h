#pragma once
#include <stdbool.h>

#ifdef __cplusplus
extern "C"{
#endif

	struct LList *Init_LinkList();
	void Insert_LinkList(struct LList *list, int pos, void *data);
	void Remove_LinkList(struct LList *list, int pos);
	void Foreach_LinkList(struct LList *list, void (*myforeach)(void *data));
	void Destroy_LinkList(struct LList *list);
	int Size_LinkList(struct LList *list);
	void *Search_LinkList(struct LList *list,void *data,bool (*compare)(void *data1,void *data2));
	void ReverseForeach_LinkList(struct LList *list, void(*myforeach)(void *data));
	static void RecursionForeach(struct LinkNode *node, void(*myforeach)(void *data));
	void Reverse_LinkList(struct LList *list);
	void Sort_LinkList(struct LList *list, int(*compare)(void *data1, void *data2));
#ifdef __cplusplus
}
#endif