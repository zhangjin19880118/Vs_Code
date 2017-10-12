#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<deque>
#include<string>
#include<algorithm>
#include<ctime>
using namespace std;

class Student
{
public:
	bool operator<(const Student &stu)
	{
		return this->score < stu.score;
	}
public:
	string mName;
	double score;
};

void creatVector(vector<Student> &v)
{
	string mNameSeed = "ABCDE";
	for (int i = 0; i < 5; ++i)
	{
		Student stu;
		stu.mName = "Ñ§Éú";
		stu.mName += mNameSeed[i];
		stu.score = 0;
		v.push_back(stu);
	}
}

void setScore(vector<Student> &v)
{
	srand((unsigned int)time(NULL));
	for (vector<Student>::iterator it = v.begin(); it != v.end(); ++it)
	{
		deque<double> dScore;
		for (int i = 0; i < 10; ++i)
		{
			double score = rand() % 50 + 50;
			dScore.push_back(score);
		}
		sort(dScore.begin(), dScore.end());
		dScore.pop_front();
		dScore.pop_back();
		double totalScore = 0;
		for (deque<double>::iterator ite = dScore.begin(); ite != dScore.end(); ++ite)
			totalScore += *ite;
		double aveScore = totalScore / dScore.size();
		it->score = aveScore;
	}
}

void showStudens(vector<Student> &v)
{
	sort(v.begin(), v.end());
	for (vector<Student>::reverse_iterator rit = v.rbegin(); rit != v.rend(); ++rit)
		cout << "score:" << rit->score << "\tname:" << rit->mName << endl; 
}

int main(void)
{
	vector<Student> v;
	creatVector(v);
	setScore(v);
	showStudens(v);
	system("pause");
	return 0;
}
