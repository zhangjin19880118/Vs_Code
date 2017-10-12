#pragma once
#include <iostream>

class MyString
{
	friend std::ostream &operator<<(std::ostream &out,const MyString &str);
	friend std::istream &operator>>(std::istream &in, MyString &str);
public:
	MyString();
	MyString(char *str);
	~MyString();
	MyString(const MyString &str);
	MyString &operator=(const MyString &str);
	MyString &operator=(const char *str);
	MyString operator+(const MyString &str);
	MyString operator+(const char *str);
	MyString &operator+=(const MyString &str);
	MyString &operator+=(const char *str);
	int Size();
private:
	char *pString;
	int mSize;
};