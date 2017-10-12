#pragma once

#ifdef __cplusplus
extern "C"{
#endif

	struct LinkQueue *Init_LinkQueue();
	void Push_LinkQueue(struct LinkQueue *queue,void *data);
	void Pop_LinkQueue(struct LinkQueue *queue);
	int Size_LinkQueue(struct LinkQueue *queue);
	void *Front_LinkQueue(struct LinkQueue *queue);
	void *Back_LinkQueue(struct LinkQueue *queue);
	void Destroy_LinkQueue(struct LinkQueue *queue);

#ifdef __cplusplus
}
#endif