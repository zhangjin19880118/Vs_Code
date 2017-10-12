#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include "LinkList.hpp"
#include <string>

class Person
{
public:
	Person(){}
	Person(string name, int age)
	{
		this->mName = name;
		this->mAge = age;
	}
public:
	string mName;
	int mAge;
};

//typedef void(*ForeachPrint)(int val);

void fp1(int val)
{
	cout << val << " ";
}

void fp2(Person &person)
{
	cout << "Name:" << person.mName << " Age:" << person.mAge << endl;
}

//struct ForeachPrint
//{
//	void operator()(int val)
//	{
//		cout << val << " ";
//	}
//	void operator()(Person &person)
//	{
//		cout << "Name:" << person.mName << " Age:" << person.mAge << endl;
//	}
//};

void test01()
{
	LinkList<int> list;
	list.insert(0, 1);
	list.insert(0, 2);
	list.insert(0, 3);
	list.insert(0, 4);
	list.insert(0, 5);

	list.foreach(fp1);
	cout << endl;

	list.remove(1);
	list.foreach(fp1);
	cout << endl;
}

void test02()
{
	LinkList<Person> list;

	list.insert(100, Person("aaa", 10));
	list.insert(100, Person("bbb", 20));
	list.insert(100, Person("ccc", 30));
	list.insert(100, Person("ddd", 40));
	list.insert(100, Person("eee", 50));
	list.insert(100, Person("fff", 60));

	list.foreach(fp2);
	cout << endl;
	list.remove(0);

	list.foreach(fp2);
	cout << endl;

}


//__cdecl CÓïÑÔµÄµ÷ÓÃ¹ßÀý
//__stdcall  windows api
//__thiscall
//__fastcall

int main(){

	//test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}