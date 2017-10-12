#pragma once

#define MAXSIZE 1024

struct SeqQueue
{
	void *data[MAXSIZE];
	int size;
};

#ifdef __cplusplus
extern "C"{
#endif

	struct SeqQueue *Init_SeqQueue();
	void Push_SeqQueue(struct SeqQueue *queue, void *data);
	void Pop_SeqQueue(struct SeqQueue *queue);
	void *Front_SeqQueue(struct SeqQueue *queue);
	void *Back_SeqQueue(struct SeqQueue *queue);
	int Size_SeqQueue(struct SeqQueue *queue);
	void Destroy_SeqQueue(struct SeqQueue *queue);

#ifdef __cplusplus
}
#endif