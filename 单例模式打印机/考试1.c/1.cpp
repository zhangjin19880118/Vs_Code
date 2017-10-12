#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Printer
{
public:
	int getCount(){ return Count; }
	static Printer *getInstance()
	{
		return pPrinter; 
	}
	void print(const char *str)
	{
		++Count;
		cout << str << endl;
	}
private:
	Printer(){}
	Printer(const Printer &printer){}
	~Printer()
	{
		--Count;
	}
	static Printer *pPrinter;
	static int Count;
};
int Printer::Count = 0;
Printer *Printer::pPrinter = new Printer;

int main(void)
{
	Printer *p1 = Printer::getInstance();
	Printer *p2 = Printer::getInstance();
	p1->print("asdfas");
	p2->print("sdaag");
	cout << p1->getCount() << endl;
	system("pause");
	return 0;
}
