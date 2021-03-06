// Test.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "BaseClass.h"

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {};

};
ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	if (head == nullptr)
		return nullptr;

	ListNode* first = head;
	ListNode* behind = head;
	
	while (first->next)
	{		
		if (n < 0)
		{
			behind = behind->next;
		}
		n--;
		first = first->next;
	}

	//remove behind->next
	ListNode* tmp = behind->next;
	if (behind->next)
	{
		behind->next = tmp->next;
		delete tmp;
	}

	return head;
}



int main()
{
	A a;
	return 0;
}

