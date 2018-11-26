#pragma once


template <typename T>
class ArrayStack
{
public:
	ArrayStack(int cap);
	~ArrayStack();

	T top();
	void push(T t);
	T pop();
	bool isEmpty();
	int size();

private:
	int count;
	int capacity;
	T* data;
};

template <typename T>
ArrayStack<T>::ArrayStack(int cap)
{
	count = 0;
	capacity = cap;
	data = new T[cap];
}
template <typename T>
ArrayStack<T>::~ArrayStack()
{
	delete[]data;
}

template <typename T>
T ArrayStack<T>::top()
{
	return data[count - 1];
}
template <typename T>
void ArrayStack<T>::push(T t)
{
	if (count >= capacity)
		return;
	data[count] = t;
	count++;
}
template <typename T>
T ArrayStack<T>::pop()
{
	if (count <= 0)
	{
		return 0;
	}

	count--;
	return data[count];
}
template <typename T>
bool ArrayStack<T>::isEmpty()
{
	return count == 0;
}
template <typename T>
int ArrayStack<T>::size()
{
	return count;
}

