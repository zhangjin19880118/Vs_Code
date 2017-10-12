#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Person
{
public:
	Person(char *name, int age)
	{
		strcpy(this->mName, name);
		this->mAge = age;
	}
public:
	char mName[64];
	int mAge;
};

void readFile(vector<Person> &v, const char *path)
{
	ifstream ifs(path, ios::in);
	if (!ifs)
	{
		cerr << "文件读取失败!" << endl;
		return;
	}
	char buf[1024] = { 0 };
	while (ifs >> buf)
	{
		cout << buf << endl;
		char *name = strtok(buf, "#");
		int age = atoi(strtok(NULL, "#"));
		v.push_back(Person(name,age));
	}
	ifs.close();
}

void selectSort(vector<Person> &v)
{
	for (unsigned int i = 0; i < v.size() - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < v.size(); ++j)
		{
			if (v[min].mAge > v[j].mAge)
				min = j;
		}
		if (min != i)
		{
			Person temp = v[i];
			v[i] = v[min];
			v[min] = temp;
		}
	}
}

void writeFile(vector<Person> &v, const char *path)
{
	ofstream ofs(path, ios::out);
	if (!ofs)
	{
		cerr << "文件写入失败!" << endl;
		return;
	}
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		cout << v[i].mName << "#" << v[i].mAge << endl;
		ofs << v[i].mName << "#" << v[i].mAge << endl;
	}
	ofs.close();
}

int main(void)
{
	vector<Person> v;
	readFile(v, "./a.txt");
	selectSort(v);
	cout << "--------------------" << endl;
	writeFile(v, "./b.txt");

	system("pause");
	return 0;
}
