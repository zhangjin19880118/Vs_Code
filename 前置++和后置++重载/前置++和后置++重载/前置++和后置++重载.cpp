#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class MyInt
{
	friend ostream &operator<<(ostream &out, const MyInt &myint);
public:
	MyInt()
	{
		num = 0;
	}
	MyInt &operator++();
	MyInt operator++(int);
private:
	int num;
};

MyInt &MyInt::operator++()
{
	++this->num;
	return *this;
}

MyInt MyInt::operator++(int)
{
	MyInt temp(*this);
	++this->num;
	return temp;
}

ostream &operator<<(ostream &out, const MyInt &myint)
{
	out << myint.num;
	return out;
}

int main(void)
{
	MyInt myint;
	cout << ++myint << endl;
	cout << myint << endl;

	cout << myint++ << endl;
	cout << myint << endl;

	system("pause");
	return 0;
}
