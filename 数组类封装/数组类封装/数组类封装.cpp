#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "MyArray.h"


void test()
{
	MyArray arr1;
	MyArray arr2(30);

#if 0
	for (int i = 0; i < 20; ++i)
	{
		arr1.PushBack(i);
	}

	for (int i = 0; i < 30; ++i)
	{
		arr2.PushBack(i + 200);
	}
#endif

	arr1 << 10 << 20 << 30 << 40;
	arr2 << 100 << 200 << 300 << 400;

	cout << arr1 << endl;
	cout << arr2 << endl;

	MyArray arr3(arr2);
	cout << arr3 << endl;

	arr3 = arr1;
	cout << arr3 << endl;
}

int main(){

	test();

	system("pause");
	return EXIT_SUCCESS;
}