#pragma once
#include<iostream>

class MyArray
{
	friend std::ostream &operator<<(std::ostream &out, MyArray &arr);
public:
	MyArray();
	MyArray(int capcity);
	~MyArray();
	MyArray(const MyArray &arr);
	MyArray &operator=(const MyArray &arr);
	int &operator[](int index);
	void PushFront(int &val);
	void PushBack(const int &val);
	int &at(int index);
	void Remove(int index);
	int Size();
	MyArray &operator<<(int val);
private:
	int *pArray;
	int mCapcity;
	int mSize;
};