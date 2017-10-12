#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyString
{
public:
	MyString(); //�޲ι��� 
	MyString(char *str);//����
	MyString(int n, char c); //�вι��죬ָ����С�ͳ�ʼֵ
	MyString(const MyString& str); //��������
	MyString& operator=(const MyString& str); //��ֵ���������
	MyString& operator=(const char* str); //��ֵ���������
	~MyString(); //��������


	MyString operator+(const MyString& str); //�Ӻ����������
	MyString operator+(const char *s); //�Ӻ����������

	MyString& operator+=(const MyString& str); //�ӵ����������
	MyString& operator+=(const char *s); //�ӵ����������

	char& operator[](int index); //�±����������
	int Size(); //�����ַ�������
	friend std::ostream& operator<<(std::ostream &out, MyString &str); //������������
	friend std::istream& operator >> (std::istream &in, MyString &str); //�������������
private:
	char* pAddress; //�ַ���ʵ�ʴ洢��ַ
	int mSize; //�ַ�����С
};

MyString::MyString()
{
	this->mSize = 0;
	this->pAddress = new char[1];
	this->pAddress[0] = '\0';
}

MyString::MyString(char *str)
{
	this->mSize = strlen(str);
	this->pAddress = new char[this->mSize + 1];
	memset(this->pAddress, 0, this->mSize + 1);
	strcpy(this->pAddress, str);
}

MyString::MyString(int n, char c)
{
	this->mSize = n;
	this->pAddress = new char[mSize + 1];
	memset(this->pAddress, 0, mSize + 1);
	for (int i = 0; i < mSize; ++i)
	{
		this->pAddress[i] = c;
	}
}

MyString::MyString(const MyString &str)
{
	this->mSize = str.mSize;
	this->pAddress = new char[this->mSize + 1];
	memset(this->pAddress, 0, this->mSize + 1);
	strcpy(this->pAddress, str.pAddress);
}

MyString &MyString::operator=(const MyString &str)
{
	if (this->pAddress != NULL)
	{
		delete[] this->pAddress;
		this->pAddress = NULL;
	}
	this->mSize = str.mSize;
	this->pAddress = new char[this->mSize + 1];
	memset(this->pAddress, 0, this->mSize + 1);
	strcpy(this->pAddress, str.pAddress);
	return *this;
}

MyString &MyString::operator=(const char *str)
{
	if (this->pAddress != NULL)
	{
		delete[] this->pAddress;
		this->pAddress = NULL;
	}
	this->mSize = strlen(str);
	this->pAddress = new char[this->mSize + 1];
	memset(this->pAddress, 0, this->mSize + 1);
	strcpy(this->pAddress, str);
	return *this;
}

MyString::~MyString()
{
	if (this->pAddress != NULL)
	{
		delete[] this->pAddress;
		this->pAddress = NULL;
	}
}

MyString MyString::operator+(const MyString &str)
{
	MyString temp;
	temp.mSize = this->mSize + str.mSize;
	temp.pAddress = new char[temp.mSize + 1];
	memset(temp.pAddress, 0, temp.mSize + 1);
	strcpy(temp.pAddress, this->pAddress);
	strcat(temp.pAddress, str.pAddress);
	return temp;
}

MyString MyString::operator+(const char *s)
{
	MyString temp;
	temp.mSize = this->mSize + strlen(s);
	temp.pAddress = new char[temp.mSize + 1];
	memset(temp.pAddress, 0, temp.mSize + 1);
	strcpy(temp.pAddress, this->pAddress);
	strcat(temp.pAddress, s);
	return temp;
}

MyString &MyString::operator+=(const MyString &str)
{
	MyString temp;
	temp.mSize = this->mSize + str.mSize;
	temp.pAddress = new char[temp.mSize + 1];
	memset(temp.pAddress, 0, temp.mSize + 1);
	strcpy(temp.pAddress, this->pAddress);
	strcat(temp.pAddress, str.pAddress);
	if (this->pAddress != NULL)
	{
		delete[] this->pAddress;
		this->pAddress = NULL;
	}
	this->mSize = temp.mSize;
	this->pAddress = new char[this->mSize + 1];
	memset(this->pAddress, 0, this->mSize + 1);
	strcpy(this->pAddress, temp.pAddress);
	return *this;
}

MyString &MyString::operator+=(const char *s)
{
	MyString temp;
	temp.mSize = this->mSize + strlen(s);
	temp.pAddress = new char[temp.mSize + 1];
	memset(temp.pAddress, 0, temp.mSize + 1);
	strcpy(temp.pAddress, this->pAddress);
	strcat(temp.pAddress, s);
	if (this->pAddress != NULL)
	{
		delete[] this->pAddress;
		this->pAddress = NULL;
	}
	this->mSize = temp.mSize;
	this->pAddress = new char[this->mSize + 1];
	memset(this->pAddress, 0, this->mSize + 1);
	strcpy(this->pAddress, temp.pAddress);
	return *this;
}

char&  MyString::operator[](int index)
{
	return this->pAddress[index];
}

int MyString::Size()
{
	return this->mSize;
}

std::ostream& operator<<(std::ostream &out, MyString &str)
{
	out << str.pAddress;
	return out;
}

std::istream& operator >> (std::istream &in, MyString &str)
{
	char buf[1024] = { 0 };
	in.getline(buf, 1024);
	if (str.pAddress != NULL)
	{
		delete[] str.pAddress;
		str.pAddress = NULL;
	}
	str.mSize = strlen(buf);
	str.pAddress = new char[str.mSize + 1];
	memset(str.pAddress, 0, str.mSize + 1);
	strcpy(str.pAddress, buf);
	return in;
}

int main(void)
{
	MyString s1;
	MyString s2(5, 'a');
	MyString s3(s2);
	cout << s2 << endl; //aaaaa
	cout << s3 << endl; //aaaaa
	s2 = "abc";
	s3 = s2;
	cout << s2 << endl; //abc
	cout << s3 << endl; //abc
	cout << s3 + s2 << endl;//abcabc
	cout << s3 << endl; //abc
	s3 += s2;
	cout << s3 << endl; //abcabc
	cout << s3[2] << endl; //c
	cout << s3.Size() << endl; //6
	cin >> s3;
	cout << s3 << endl;

	system("pause");
	return 0;
}
