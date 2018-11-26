#pragma once
#include "ListStack.h"

template <typename T>
class ListQuene
{
public:
	ListQuene();
	~ListQuene();

	void push(T t);
	bool pop();
	T front();
	bool isEmpty();
	int size();
private:
	Node<T>* pHead;
	Node<T>* pEnd;
	int count;
};

template <typename T>
ListQuene<T>::ListQuene()
{
	count = 0;
	pHead = new Node<T>;
	pEnd = new Node<T>;
	pHead = pEnd;
}

template <typename T>
ListQuene<T>::~ListQuene()
{	
	Node<T>* pNode = pHead->pNext;
	while (pNode)
	{
		Node<T>* pTemp = pNode;
		pNode = pNode->pNext;
		delete pTemp;
	}
	delete pHead;
}

template <typename T>
void ListQuene<T>::push(T t)
{
	Node<T>* pNode = new Node<T>;
	pNode->value = t;
	pEnd->pNext = pNode;
	pEnd = pNode;
	count++;
}

template <typename T>
bool ListQuene<T>::pop()
{
	Node<T>* pNode = pHead->pNext;
	if (pNode)
	{
		pHead->pNext = pNode->pNext;
		delete pNode;
		count--;
		return true;
	}
	return false;
}

template <typename T>
T ListQuene<T>::front()
{
	if (isEmpty())
		return 0;
	return pHead->pNext->value;
}
template <typename T>
bool ListQuene<T>::isEmpty()
{
	return count == 0;
}

template <typename T>
int ListQuene<T>::size()
{
	return count;
}
