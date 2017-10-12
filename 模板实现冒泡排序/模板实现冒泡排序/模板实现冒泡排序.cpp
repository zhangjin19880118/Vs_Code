#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person(string name, int age) :mName(name), mAge(age){}
public:
	string mName;
	int mAge;
};

struct Compare
{
	bool operator()(int a, int b)
	{
		return a < b;
	}
	bool operator()(Person &p1, Person &p2)
	{
		return p1.mAge < p2.mAge;
	}
};

template<typename T>
void bubbleSort(T arr[], int n, Compare compare)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = 0; j < n - 1 - i; ++j)
		{
			if (compare(arr[j + 1], arr[j]))
			{
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main(void)
{
	int a[] = { 8, 2, 1, 3, 4, 6, 7, 9, 5, 0 };
	int n1 = sizeof(a) / sizeof(*a);
	bubbleSort(a, n1, Compare());
	for (int i = 0; i < n1; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "---------------------------------------" << endl;

	Person p[5] = { Person("aaa", 40), Person("bbb", 30), Person("ccc", 20), Person("ddd", 50), Person("eee", 10) };
	int n2 = sizeof(p) / sizeof(*p);
	bubbleSort(p, n2, Compare());
	for (int i = 0; i < n2; ++i)
	{
		cout << p[i].mAge << " " << p[i].mName << endl;
	}

	system("pause");
	return 0;
}
