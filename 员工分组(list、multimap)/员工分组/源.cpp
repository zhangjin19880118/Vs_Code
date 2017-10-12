#define _CRT_SECURE_NO_WARNINGS
#define SALE_DEPATMENT 1 //销售部门
#define DEVELOP_DEPATMENT 2 //研发部门
#define FINACIAL_DEPATMENT 3 //财务部门
#include<iostream>
#include<list>
#include<string>
#include<map>
#include<ctime>
using namespace std;

class Employee
{
public:
	string mName;
	int mEmployee;
};

void createEmployees(list<Employee> &mylist)
{
	string mNameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; ++i)
	{
		Employee employee;
		employee.mName = "员工";
		employee.mName += mNameSeed[i];
		employee.mEmployee = 3000;
		mylist.push_back(employee);
	}
}

void setGroups(list<Employee> &mylist, multimap<int, Employee> &m)
{
	srand((unsigned int)time(NULL));
	for (list<Employee>::iterator it = mylist.begin(); it != mylist.end(); ++it)
	{
		int id = rand() % 3 + 1;
		m.insert(make_pair(id, *it));
	}
}

void showEmployeeID(multimap<int, Employee> &m,int id)
{
	auto pos = m.find(id);
	int nCount = m.count(id);
	for (int i = 0; i < nCount; ++i)
	{
		cout << pos->second.mName << " " << pos->second.mEmployee << endl;
		++pos;
	}
}

void showEmployeeByID(multimap<int, Employee> &m)
{
	cout << "销售部门人员名单:" << endl;
	showEmployeeID(m, SALE_DEPATMENT);
	cout << "研发部门人员名单:" << endl;
	showEmployeeID(m, DEVELOP_DEPATMENT);
	cout << "财务部门人员名单:" << endl;
	showEmployeeID(m, FINACIAL_DEPATMENT);
}

int main(void)
{
	list<Employee> mylist;
	multimap<int, Employee> m;
	createEmployees(mylist);
	setGroups(mylist, m);
	showEmployeeByID(m);

	system("pause");
	return 0;
}
