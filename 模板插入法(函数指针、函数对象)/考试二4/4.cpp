#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->mName = name;
		this->mAge = age;
	}
public:
	string mName;
	int mAge;
};

bool myCompare1(int d1, int d2)
{
	return d1 < d2;
}

bool myCompare2(const Person &p1, const Person &p2)
{
	return p1.mAge < p2.mAge;
}

//struct Compare
//{
//	bool operator()(int d1, int d2)
//	{
//		return d1 < d2;
//	}
//	bool operator()(const Person &p1, const Person &p2)
//	{
//		return p1.mAge < p2.mAge;
//	}
//};

template<class T1,class T2>
void mySort(T1 arr[], int len,T2 compare)
{
	for (int i = 1; i < len; ++i)
	{
		if (compare(arr[i], arr[i - 1]))
		{
			T1 temp = arr[i];
			int j = i - 1;
			for (; j >= 0 && compare(temp, arr[j]); --j)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}

template<class T>
void printArray(T arr[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(void)
{
	int a[] = { 6, 3, 4, 5, 2, 1 };
	int len = sizeof(a) / sizeof(*a);
	printArray(a, len);
	mySort(a, len, myCompare1);
	printArray(a, len);

	char b[] = "gfdad";
	len = strlen(b);
	printArray(b, len);
	mySort(b, len, myCompare1);
	printArray(b, len);

	Person p[3] = { Person("zhangsan", 20), Person("lisi", 23), Person("wangwu", 18) };
	mySort(p, 3, myCompare2);
	for (int i = 0; i < 3; ++i)
	{
		cout << p[i].mName << "," << p[i].mAge << endl;
	}


	system("pause");
	return 0;
}
