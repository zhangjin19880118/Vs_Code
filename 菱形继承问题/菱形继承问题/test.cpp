#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Animal
{
public:
	Animal()
	{
		mAge = 1;
		mSex = 2;
	}
	int mAge;
	int mSex;
};

class Sheep : virtual public Animal
{
public:
	int mWeight;
};

class Tuo : virtual public Animal
{
public:
	int mHeight;
};

class SheepTuo : public Sheep, public Tuo
{

};

int main(void)
{
	SheepTuo st;
	cout << st.mAge << endl;
	cout << ((Animal *)((char *)&st + *((int *)*(int *)&st + 1)))->mAge<< endl;
	cout << st.mSex << endl;
	cout << *(int *)((char *)&st + 8 + *((int *)*(int *)((char *)&st + 8) + 1) + 4) << endl;

	system("pause");
	return 0;
}
