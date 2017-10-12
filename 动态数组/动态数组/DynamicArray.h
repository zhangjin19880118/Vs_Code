#pragma once

#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

	struct DArray *Init_DynamicArray();
	void Insert_DynamicArray(struct DArray *arr, int pos, void *data);
	void Remove_DynamicArray(struct DArray *arr, int pos);
	void Foreach_DynamicArray(struct DArray *arr, void(*myforeach)(void *data));
	void Destory_DynamicArray(struct DArray *arr);

#ifdef __cplusplus
}
#endif // __cplusplus