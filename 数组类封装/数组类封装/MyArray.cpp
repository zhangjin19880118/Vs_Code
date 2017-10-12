#include"MyArray.h"

MyArray::MyArray()
{
	this->mCapcity = 20;
	this->pArray = new int[this->mCapcity];
	this->mSize = 0;
}

MyArray::MyArray(int capcity)
{
	this->mCapcity = capcity;
	this->pArray = new int[this->mCapcity];
	this->mSize = 0;
}

MyArray::~MyArray()
{
	if (this->pArray != NULL)
	{
		delete[] this->pArray;
		this->pArray = NULL;
	}		
}
MyArray::MyArray(const MyArray &arr)
{
	this->mCapcity = arr.mCapcity;
	this->pArray = new int[this->mCapcity];
	this->mSize = arr.mSize;
	for (int i = 0; i < arr.mSize; ++i)
		this->pArray[i] = arr.pArray[i];
}

MyArray &MyArray::operator=(const MyArray &arr)
{
	if (this->pArray != NULL)
	{
		delete[] this->pArray;
		this->pArray = NULL;
	}
	this->mCapcity = arr.mCapcity;
	this->pArray = new int[this->mCapcity];
	this->mSize = arr.mSize;
	for (int i = 0; i < arr.mSize; ++i)
		this->pArray[i] = arr.pArray[i];
	return *this;
}

int &MyArray::operator[](int index)
{
	return this->pArray[index];
}

void MyArray::PushFront(int &val)
{
	if (this->mSize == this->mCapcity)
		return;
	for (int i = this->mSize - 1; i >= 0; --i)
		this->pArray[i + 1] = this->pArray[i];
	this->pArray[0] = val;
	this->mSize++;
}

void MyArray::PushBack(const int &val)
{
	if (this->mSize == this->mCapcity)
		return;
	this->pArray[this->mSize] = val;
	this->mSize++;
}

int &MyArray::at(int index)
{
	return this->pArray[index];
}

void MyArray::Remove(int index)
{
	if (index < 0 || index > this->mCapcity - 1)
		return;
	for (int i = index; i < this->mSize - 1; ++i)
		this->pArray[i] = this->pArray[i + 1];
	this->mSize--;
}

int MyArray::Size()
{
	return this->mSize;
}

MyArray &MyArray::operator<<(int val)
{
	PushBack(val);
	return *this;
}

std::ostream &operator<<(std::ostream &out, MyArray &arr)
{
	for (int i = 0; i < arr.mSize; ++i)
		out << arr.pArray[i] << " ";
	return out;
}

