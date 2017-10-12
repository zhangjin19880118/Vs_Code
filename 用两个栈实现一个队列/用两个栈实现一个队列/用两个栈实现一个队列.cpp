#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stack>
using namespace std;

class Queue
{
public:
	//���
	void Push(const int& val);
	//����
	void Pop();
	//���ض���Ԫ��
	int& Front();
	//���ض�βԪ��
	int& Back();
	//�ж϶����Ƿ�Ϊ��
	bool Empty();
	//���ض��д�С
	int Size();
private:
	stack<int> s1;
	stack<int> s2;
};
//���
void Queue::Push(const int& val)
{
	this->s1.push(val);
}
//����
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
//���ض���Ԫ��
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
//���ض�βԪ��
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
//�ж϶����Ƿ�Ϊ��
bool Queue::Empty()
{
	return s1.empty() && s2.empty();
}
//���ض��д�С
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

