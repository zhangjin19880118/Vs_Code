#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Student
{
public:
	Student(int age)
	{
		mAge = age;
	}
public:
	int mAge;
};

class Person
{
public:
	Person(int a, int b)
	{
		cout << "带参构造函数!" << endl;
		mA = a;
		mB = b;
	}

	Person(const Person &person)
	{
		cout << "拷贝构造函数!" << endl;
		this->mA = person.mA;
		this->mB = person.mB;
	}

	//以成员函数的形式重载operator+
	Person operator+(Person &person)
	{
		Person newperson(0, 0);
		newperson.mA = this->mA + person.mA;
		newperson.mB = this->mB + person.mB;

		return newperson;
	}

	Person operator-(Person &person)
	{
		return Person(this->mA - person.mA, this->mB - person.mB);
	}

	Person operator+(int val)
	{
		Person newperson(this->mA + val, this->mB + val);

		return newperson;
	}

	Person operator+(Student &s)
	{
		Person newperson(this->mA + s.mAge, this->mB + s.mAge);

		return newperson;
	}


public:
	int mA;
	int mB;
};

#if 0
Person operator+(Person &p1, Person &p2)
{
	Person newperson(p1.mA + p2.mA, p1.mB + p2.mB);

	return newperson;
}
#endif
void test01()
{
	Person p1(10, 20);
	Person p2(30, 40);

	Person ret = p1 + p2; //p1.operator+(p2)
	cout << "A:" << ret.mA << " B:" << ret.mB << endl;
}

void test02()
{
	Person p1(10, 20);
	Person ret = p1 + 200; //p1.operator+(100);
	cout << "A:" << ret.mA << " B:" << ret.mB << endl;

}


Person operator+(int val, Person &p)
{
	Person newperson(p.mA + val, p.mB + val);
	return newperson;
}

void test03()
{
	Person p1(10, 20);
	Person ret = 200 + p1;
	cout << "A:" << ret.mA << " B:" << ret.mB << endl;
}

Student operator+(Student &s, Person &p)
{
	Student ss(s.mAge + p.mA + p.mB);

	return ss;
}

void test04()
{
	Person p(10, 20);
	Student s(100);

	Person ret = p + s; //p.operator+(s)
	Student sret = s + p; //s.operator+(p)  operator(s,p);
}

int main(){

	test01();
	//test02();
	//test03();

	system("pause");
	return EXIT_SUCCESS;
}