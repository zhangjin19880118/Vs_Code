#pragma once

struct LinkNode
{
	struct LinkNode *next;
};

#ifdef __cplusplus
extern "C"{
#endif

	struct LinkList *Init_LinkList();
	void Insert_LinkList(struct LinkList *list,int pos,void *data);
	void Remove_LinkList(struct LinkList *list, int pos);
	void Foreach_LinkList(struct LinkList *list, void(*myforeach)(void *data));
	void Destroy_LinkList(struct LinkList *list);

#ifdef __cplusplus
}
#endif