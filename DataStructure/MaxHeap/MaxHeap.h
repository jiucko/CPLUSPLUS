#pragma once
#include<iostream>

using namespace std;



template <typename T>
class MaxHeap
{
public:
	MaxHeap(int cap);
	~MaxHeap();

	bool insert(T val);
	bool remove(T val);
	void print();
	T top();
	bool createMaxHeap(T a[],int size);
private:
	int size;
	int capacity;
	T* heap;

private:
	void filterUp(int index);

	// 从begin所在节点开始，向end方向调整堆
	void filterDown(int begin, int end);
};

template <typename T>
MaxHeap<T>::MaxHeap(int cap) :capacity(cap), size(0), heap(nullptr)
{
	heap = new T[cap];
}

template <typename T>
MaxHeap<T>::~MaxHeap()
{
	delete[]heap;
}

template <typename T>
void MaxHeap<T>::print()
{
	for (int i = 0; i < size; i++)
	{
		cout << heap[i] << "	";
	}
	cout << endl;
}

template <typename T>
T MaxHeap<T>::top()
{
	if (size > 0)
		return heap[0];
	return 0;
}

template <typename T>
bool MaxHeap<T>::insert(T val)
{
	if (size == capacity)
		return false;
	heap[size] = val;
	
	filterUp(size);
	size++;
	this->print();
	return true;
}

template <typename T>
void MaxHeap<T>::filterUp(int index)
{
	T value = heap[index];
	while (index > 0)
	{
		int pIndex = (index-1) / 2;
		if (heap[pIndex] > value)
		{
			break;
		}
		else
		{
			heap[index] = heap[pIndex];
			index = pIndex;
		}
	}
	heap[index] = value;
	
}

template <typename T>
bool MaxHeap<T>::remove(T val)
{
	if (size == 0) return false;
	int index;
	for (index = 0; index < size; index++)
	{
	{
		if (heap[index] == val)
			break;
	}

	if (index == size)
		return false;
	heap[index] = heap[size - 1];
	filterDown(index, size--);
	return true;
}

template <typename T>
void MaxHeap<T>::filterDown(int current, int end)
{
	int child = current * 2 + 1;
	T value = heap[current];

	while (child <= end)
	{
		if (child < end && heap[child] < heap[child + 1])
			child++;
		if (value > heap[child])
		{
			break;
		}
		else
		{
			heap[current] = heap[child];
			current = child;
			child = child * 2 + 1;
		}
	}
	heap[current] = value;
}

template <typename T>
bool MaxHeap<T>::createMaxHeap(T a[], int s)
{
	if (s > capacity)
	{
		return false;
	}

	for (int i = 0; i < s; i++)
	{
		insert(a[i]);
	}
	return true;
}
