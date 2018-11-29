// MaxHeap.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MaxHeap.h"

int main()
{
	MaxHeap<int> heap(12);
	int a[11] = { 1,2,3,4,5,6,7,8,9,10,11 };
	heap.createMaxHeap(a, 11);
	heap.print();
	heap.insert(20);
	heap.print();
	heap.remove(8);
	heap.print();
	return 0;
}

