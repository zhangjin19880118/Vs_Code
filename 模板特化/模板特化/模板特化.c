#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

//ģ��
template<class T = void>
struct myLess
{
	bool operator()(T a, T b)
	{
		return a < b;
	}
};

//�ػ�
template<>
struct myLess<void>
{

	template<class T>
	bool operator()(T a, T b)
	{
		return a < b;
	}
};


int main(void)
{
	myLess<>()(10, 20);


	system("pause");
	return 0;
}
