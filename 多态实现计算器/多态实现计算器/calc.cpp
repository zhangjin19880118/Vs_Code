#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Calc
{
public:
	virtual int caculator(int a, int b) = 0;
};

class Puls : public Calc
{
public:
	int caculator(int a, int b)
	{
		return a + b;
	}
};

class Minux : public Calc
{
public:
	int caculator(int a, int b)
	{
		return a - b;
	}
};

class Modulo : public Calc
{
public:
	int caculator(int a, int b)
	{
		return a % b;
	}
};

void DoLogic(Calc *pCalc)
{
	cout<<pCalc->caculator(10, 20)<<endl;
}

int main(void)
{
	int a = 10, b = 20;

	Calc *pCalc = new Puls;
	cout << pCalc->caculator(a, b) << endl;

	pCalc = new Minux;
	cout << pCalc->caculator(a, b) << endl;

	pCalc = new Modulo;
	cout << pCalc->caculator(a, b) << endl;

	DoLogic(new Puls);

	system("pause");
	return 0;
}
