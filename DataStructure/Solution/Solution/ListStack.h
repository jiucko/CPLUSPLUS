#pragma once

template <typename T>
struct Node
{
	Node(T t) : value(t), pNext(nullptr){};
	Node():pNext(nullptr) {};


	T value;
	Node* pNext;
};


template <typename T>
class ListStack
{
public:
	ListStack();
	~ListStack();

	T top();
	void push(T t);
	T pop();
	bool isEmpty();
	int size();

private:
	Node<T>* pHead;
};


template <typename T>
ListStack<T>::ListStack()
{
	pHead = new Node<T>;
}

template <typename T>
ListStack<T>::~ListStack()
{
	delete pHead;
}

template <typename T>
T ListStack<T>::top()
{
	Node<T>* pNode = pHead->pNext;
	T value;
	while (pNode)
	{
		value = pNode->value;
		pNode = pNode->pNext;
	}
	return value;
}

template <typename T>
void ListStack<T>::push(T t)
{
	Node<T>* pNode = pHead;
	while (pNode->pNext)
	{
		pNode = pNode->pNext;
	}

	Node<T>* pNew = new Node<T>;
	pNew->value = t;
	pNode->pNext = pNew;
}

template <typename T>
T ListStack<T>::pop()
{
	Node<T>* pNode = pHead->pNext;
	Node<T>* pTemp = pHead;

	while (pTemp->pNext && pNode->pNext)
	{
		pNode = pNode->pNext;
		pTemp = pTemp->pNext;
	}

	T value = pTemp->pNext->value;
	delete pTemp->pNext;
	pTemp->pNext = nullptr;

	return value;
}

template <typename T>
bool ListStack<T>::isEmpty()
{
	return pHead->pNext == nullptr;
}

template <typename T>
int ListStack<T>::size()
{
	Node<T>* pNode = pHead->pNext;
	int size = 0;
	while (pNode)
	{
		size++;
		pNode = pNode->pNext;
	}

	return size;
}