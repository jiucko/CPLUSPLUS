#pragma once

template <typename T>
class ArrayQuene
{
public:
	ArrayQuene(int cap);
	~ArrayQuene();

	void push(T t);
	bool pop();
	T front();
	int size();
	bool isEmpty();


private:
	T* value;
	int count;
	int capacity;
};


template <typename T>
ArrayQuene<T>::ArrayQuene(int cap)
{
	count = 0;
	capacity = cap;
	value = new T[cap];
}

template <typename T>
ArrayQuene<T>::~ArrayQuene()
{
	delete []value;
}

template <typename T>
void ArrayQuene<T>::push(T t)
{
	if (count >= capacity)
	{
		return;
	}

	value[count] = t;
	count++;
}

template <typename T>
bool ArrayQuene<T>::pop()
{
	if (isEmpty())
	{
		return false;
	}

	for (int i = 0; i < count-1; i++)
	{
		value[i] = value[i + 1];
	}
	value[count] = 0;
	count--;
	return true;
}

template <typename T>
T ArrayQuene<T>::front()
{
	if (isEmpty())
	{
		return 0;
	}

	return value[0];
}

template <typename T>
bool ArrayQuene<T>::isEmpty()
{
	return count == 0;
}

template <typename T>
int ArrayQuene<T>::size()
{
	return count;
}