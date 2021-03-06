#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
using namespace std;

class Queue
{
public:
	//入队
	void Push(const int& val);
	//出队
	void Pop();
	//返回队首元素
	int& Front();
	//返回队尾元素
	int& Back();
	//判断队列是否为空
	bool Empty();
	//返回队列大小
	int Size();
private:
	stack<int> s1;
	stack<int> s2;
};
//入队
void Queue::Push(const int& val)
{
	this->s1.push(val);
}
//出队
void Queue::Pop()
{
	if (s2.empty())
	{
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}
	s2.pop();
}
//返回队首元素
int &Queue::Front()
{
	if (s2.empty())
	{
		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}
	}
	return s2.top();
}
//返回队尾元素
int &Queue::Back()
{
	if (s1.empty())
	{
		while (!s2.empty())
		{
			s1.push(s2.top());
			s2.pop();
		}
	}
	return s1.top();
}
//判断队列是否为空
bool Queue::Empty()
{
	return s1.empty() && s2.empty();
}
//返回队列大小
int Queue::Size()
{
	return s1.size() + s2.size();
}

int main(void)
{
	Queue q;
	for (int i = 0; i < 10; ++i)
	{
		q.Push(i);
	}
	cout << q.Size() << endl;//10
	cout << q.Front() << endl;//0
	cout << q.Back() << endl;//9
	q.Pop();
	cout << q.Front() << endl;//1
	cout << q.Size() << endl;//9
	cout << "---------------" << endl;
	while (!q.Empty())
	{
		cout << q.Front() << endl;//1-9
		q.Pop();
	}
	cout << q.Size() << endl;//0
	system("pause");
	return 0;
}

