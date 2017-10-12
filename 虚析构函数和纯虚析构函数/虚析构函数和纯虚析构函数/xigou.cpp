#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base构造函数!" << endl;
	}
	virtual ~Base() = 0;
	virtual void func()
	{
		cout << "Base::fun!" << endl;
	}
};

Base::~Base()
{
	cout << "Base纯虚析构函数!" << endl;
}

class Derived : public Base
{
public:
	Derived()
	{
		cout << "Derived构造函数!" << endl;
	}
	~Derived()
	{
		cout << "Derived析构函数!" << endl;
	}
	virtual void func()
	{
		cout << "Derived::fun!" << endl;
	}
};

int main(void)
{
	Base *b = new Derived;
	delete b;
	return 0;
}
