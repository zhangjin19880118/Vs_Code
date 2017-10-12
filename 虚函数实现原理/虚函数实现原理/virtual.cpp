#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	virtual void func1()
	{
		cout << "Base::func1!" << endl;
	}
	virtual void func2()
	{
		cout << "Base::func2!" << endl;
	}
	void func3()
	{
		cout << "Base::func3!" << endl;
	}
public:
	int mA;
};

class Derive : public Base
{
public:
	virtual void func1()
	{
		cout << "Derive::func1!" << endl;
	}
public:
	int mB;
	int mC;
};

void doLogic(Base &b)
{
	b.func1();
}

int main(void)
{
	Base b;
	((void(*)())*((int *)*(int *)&b+1))();


	system("pause");
	return 0;
}
