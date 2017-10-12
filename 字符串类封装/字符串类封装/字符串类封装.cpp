#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"MyString.h"


void test()
{
	MyString str1; //默认构造函数
	cout << "str1:" << str1 << endl;

	cin >> str1;
	cout << "str1:" << str1 << endl;

	MyString str2 = "hello world!";
	MyString str3(str2);
	cout << "str2:" << str2 << endl;
	cout << "str3:" << str3 << endl;
	str3 = str1;
	cout << "str3:" << str3 << endl;

}

void test02()
{
	MyString str1;
	str1 += "hello world";
	cout << "str1:" << str1 << endl;
	MyString str2 = "aaa";
	str2 += str1;
	cout << "str2:" << str2 << endl;

	MyString str3 = str1 + str2;
	cout << str3 << endl;

	cout << "size:" << str3.Size() << endl;

}

int main(){

	//test();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}