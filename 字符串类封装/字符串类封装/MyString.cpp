#define _CRT_SECURE_NO_WARNINGS
#include"MyString.h"

MyString::MyString()
{
	this->mSize = 0;
	this->pString = new char[1];
	this->pString[0] = '\0';
}

MyString::MyString(char *str)
{
	this->mSize = strlen(str);
	this->pString = new char[this->mSize + 1];
	memset(this->pString, 0, this->mSize + 1);
	strcpy(this->pString,str);
}

MyString::~MyString()
{
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}
}

MyString::MyString(const MyString &str)
{
	this->mSize = str.mSize;
	this->pString = new char[this->mSize + 1];
	memset(this->pString, 0, this->mSize + 1);
	strcpy(this->pString, str.pString);
}

MyString &MyString::operator=(const MyString &str)
{
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}
	this->mSize = str.mSize;
	this->pString = new char[this->mSize + 1];
	memset(this->pString, 0, this->mSize + 1);
	strcpy(this->pString, str.pString);
	return *this;
}

MyString &MyString::operator=(const char *str)
{
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}
	this->mSize = strlen(str);
	this->pString = new char[this->mSize + 1];
	memset(this->pString, 0, this->mSize + 1);
	strcpy(this->pString, str);
	return *this;
}

MyString MyString::operator+(const MyString &str)
{
	MyString temp;
	temp.mSize = this->mSize + str.mSize;
	temp.pString = new char[temp.mSize + 1];
	memset(temp.pString, 0, temp.mSize + 1);
	strcpy(temp.pString, this->pString);
	strcat(temp.pString, str.pString);
	return temp;
}

MyString MyString::operator+(const char *str)
{
	MyString temp;
	temp.mSize = this->mSize + strlen(str);
	temp.pString = new char[temp.mSize + 1];
	memset(temp.pString, 0, temp.mSize + 1);
	strcpy(temp.pString, this->pString);
	strcat(temp.pString, str);
	return temp;
}

MyString &MyString::operator+=(const MyString &str)
{
	MyString temp;
	temp.mSize = this->mSize + str.mSize;
	temp.pString = new char[temp.mSize + 1];
	memset(temp.pString, 0, temp.mSize + 1);
	strcpy(temp.pString, this->pString);
	strcat(temp.pString, str.pString);
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}
	this->mSize = temp.mSize;
	this->pString = new char[this->mSize + 1];
	memset(this->pString, 0, this->mSize + 1);
	strcpy(this->pString, temp.pString);
	return *this;
}

MyString &MyString::operator+=(const char *str)
{
	MyString temp;
	temp.mSize = this->mSize + strlen(str);
	temp.pString = new char[temp.mSize + 1];
	memset(temp.pString, 0, temp.mSize + 1);
	strcpy(temp.pString, this->pString);
	strcat(temp.pString, str);
	if (this->pString != NULL)
	{
		delete[] this->pString;
		this->pString = NULL;
	}
	this->mSize = temp.mSize;
	this->pString = new char[this->mSize + 1];
	memset(this->pString, 0, this->mSize + 1);
	strcpy(this->pString, temp.pString);
	return *this;
}

int MyString::Size()
{
	return this->mSize;
}

std::ostream &operator<<(std::ostream &out, const MyString &str)
{
	out << str.pString;
	return out;
}

std::istream &operator>>(std::istream &in, MyString &str)
{
	char buf[1024] = {0};
	in.getline(buf, 1024);
	if (str.pString != NULL)
	{
		delete[] str.pString;
		str.pString = NULL;
	}
	str.mSize = strlen(buf);
	str.pString = new char[str.mSize + 1];
	memset(str.pString, 0, str.mSize + 1);
	strcpy(str.pString, buf);
	return in;
}