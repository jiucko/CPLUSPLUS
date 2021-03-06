// Sort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <thread>

#define NUM_THREADS 8

void bubbleSort(std::vector<int>& data)
{
	for (int i = 0; i < data.size()-1; i++)
	{
		for (int j = 0; j < data.size()-1-i; j++)
		{
			if (data[j] > data[j + 1])
			{
				int tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}
}

void selectionSort(std::vector<int>& data)
{
	for (int i = 0; i < data.size(); i++)
	{
		int tmp = INT_MAX;
		int index = 0;
		for (int j = i; j < data.size(); j++)
		{
			if (data[j] < tmp)
			{
				tmp = data[j];
				index = j;
			}
		}
		data[index] = data[i];
		data[i] = tmp;
	}
}

void insertionSort(std::vector<int>& data)
{
	for (int i = 0; i < data.size(); i++)
	{
		int tmp = data[i];
		for (int j = i-1; j >= 0; j--)
		{
			if (tmp < data[j])
			{
				data[j + 1] = data[j];
				data[j] = tmp;
			}
			else
			{
				break;
			}
		}
	}
}

void quickSort(std::vector<int>& data, int low, int high)
{
	if (low >= high)
		return;
	int left = low;
	int right = high;
	int key = data[left];
	while (left < right)
	{
		//找到第一个大于key的元素
		while (left < right && data[right] >= key)
		{
			right--;
		}
		data[left] = data[right];
		while (left < right && data[left] < key)
		{
			left++;
		}
		data[right] = data[left];
	}
	data[left] = key;
	quickSort(data, 0, left - 1);
	quickSort(data, left + 1, high);
}

void shellSort(std::vector<int>& data,int d)
{
	for (int inc = d; inc > 0; inc /= 2)
	{
		for (int i = inc; i < data.size(); i++)
		{
			int tmp = data[i];
			for (int j = i - inc; j >= 0; j-=inc)
			{
				if (tmp < data[j])
				{
					data[j + inc] = data[j];
					data[j] = tmp;
				}
				else
				{
					break;
				}
			}
		}
	}
}


void radixSort(std::vector<int>& data)
{
	
}
void mergearray(std::vector<int>& data, int first, int mid, int last, int tmp[])
{
	int i = first, j = mid + 1, k = 0;
	while (i <= mid && j <= last)
	{
		if (data[i] <= data[j])
			tmp[k++] = data[i++];
		else
			tmp[k++] = data[j++];
	}
	while (i <= mid)
		tmp[k++] = data[i++];

	while (j <= last)
		tmp[k++] = data[j++];

	for (i = 0; i < k; i++)
		data[first + i] = tmp[i];

}
void mergeSort(std::vector<int>& data,int first,int last,int tmp[])
{
	if (first < last)
	{	
		int mid = (first + last) / 2;
		mergeSort(data, first, mid, tmp);
		mergeSort(data, mid+1, last, tmp);
		mergearray(data, first,mid, last, tmp);
	}
}
inline void mergeBlocks(int* const pDataArray, int arrayLen, const int blockNum, int* const resultArray)
{
	std::cout << "hello world" << std::endl;
}

//多线程 归并
void mergeSort()
{
	int thread_num = 8;
	int block_num = thread_num;
	int data_num = 10000000;
	int *data = new int[data_num];
	int *result = new int[data_num];
	for (int i = 0; i < data_num; i++)
	{
		data[i] = rand();
	}
	
	std::thread myThread[NUM_THREADS];
	for (int i = 0; i < thread_num; ++i)
	{
		myThread[i] = std::thread(mergeBlocks, data, data_num, block_num, result);
	}
	
	for (int i = 0; i < thread_num; ++i)
	{
		myThread[i].join();
	}
	
}
int main()
{
	std::vector<int> data = { 1,3,5,7,2,7,9 };
	//bubbleSort(data);
	//selectionSort(data);
	//insertionSort(data);
	//quickSort(data, 0, data.size() - 1);
	//shellSort(data, 2);
	mergeSort();
	int* tmp = new int[data.size()];
	mergeSort(data, 0, data.size() - 1, tmp);
	for (auto it : data)
	{
		std::cout << it << "   ";
	}
	return 0;
}

