#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		cout << "Base���캯��!" << endl;
	}
	virtual ~Base() = 0;
	virtual void func()
	{
		cout << "Base::fun!" << endl;
	}
};

Base::~Base()
{
	cout << "Base������������!" << endl;
}

class Derived : public Base
{
public:
	Derived()
	{
		cout << "Derived���캯��!" << endl;
	}
	~Derived()
	{
		cout << "Derived��������!" << endl;
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
