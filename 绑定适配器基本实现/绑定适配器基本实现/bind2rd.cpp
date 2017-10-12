#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

struct Print
{
	void operator()(int v,int param)
	{
		cout << v << " " << param << endl;
	}
};

class target
{
public:
	target(Print myPrint,int param)
	{
		this->mPrint = myPrint;
		this->mParam = param;
	}
	void operator()(int v)
	{
		this->mPrint(v, this->mParam);
	}
private:
	Print mPrint;
	int mParam;
};

target bind2rd(Print myPrint, int param)
{
	return target(myPrint, param);
}

int main(void)
{
	vector<int> v = { 1, 2, 3, 4, 5 };
	for_each(v.begin(), v.end(), bind2rd(Print(),200));

	system("pause");
	return 0;
}
