#pragma once

template<class T>
struct LinkNode
{
	T data;
	LinkNode *next;
};

template<class T>
class LinkList
{
public:
	LinkList()
	{
		mHeader.next = NULL;
		mSize = 0;
	}

	void insert(int pos, T val)
	{
		if (pos < 0 || pos > this->mSize)
			pos = this->mSize;
		LinkNode<T> *pNew = new LinkNode<T>;
		pNew->data = val;
		pNew->next = NULL;
		LinkNode<T> *pCur = &mHeader;
		for (int i = 0; i < pos; ++i)
			pCur = pCur->next;
		pNew->next = pCur->next;
		pCur->next = pNew;
		++this->mSize;
	}

	void remove(int pos)
	{
		if (pos < 0 || pos >this->mSize - 1)
			return;
		LinkNode<T> *pPre = &mHeader;
		for (int i = 0; i < pos; ++i)
			pPre = pPre->next;
		LinkNode<T> *pDel = pPre->next;
		pPre->next = pDel->next;
		delete pDel;
		pDel = NULL;
		--this->mSize;
	}
	
	template<class ForeachPrint>
	void foreach(ForeachPrint fp)
	{
		cout << typeid(fp).name() << endl;
		LinkNode<T> *pCur = mHeader.next;
		for (int i = 0; i < this->mSize; ++i)
		{
			fp(pCur->data);
			pCur = pCur->next;
		}			
	}

	~LinkList()
	{
		LinkNode<T> *pDel = mHeader.next;
		while (pDel != NULL)
		{
			LinkNode<T> *pNext = pDel->next;
			delete pDel;
			pDel = NULL;
			pDel = pNext;
		}
	}

public:
	LinkNode<T> mHeader;
	int mSize;
};