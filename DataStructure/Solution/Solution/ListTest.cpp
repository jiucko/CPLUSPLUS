#include "stdafx.h"
#include "ListTest.h"
#include <iostream>

LinkList::LinkList()
{
	pHead = new ListNode(0);
	pHead->next = nullptr;
}

LinkList::~LinkList()
{
	delete pHead;
}

void LinkList::createLinkList(int size)
{
	if (size <= 0)
	{
		return;
	}
	ListNode* pTemp;
	pTemp = pHead;
	int i = 0;
	std::cout << "Cearte a LinkList With " << size << " element" << std::endl;
	while (size-- && std::cin >> i)
	{
		
		ListNode* pNode = new ListNode(i);
		pNode->next = nullptr;
		pTemp->next = pNode;
		pTemp = pNode;
	}
}


void LinkList::insertNode(int position, int data)
{
	
	//Determine if the length is appropriate
	if (position <= 0 || position > (this->getLinkListLength()+1))
	{
		return;
	}
	ListNode* pNode = pHead;
	position = position - 1;
	while (position--)
	{
		pNode = pNode->next;
	}

	ListNode *pNew = new ListNode(data);
	
	ListNode* pTemp = pNode->next;
	pNode->next = pNew;
	pNew->next = pTemp;
}
void LinkList::deleteNode(int position)
{
	//Determine if the length is appropriate
	if (position <= 0 || position >(this->getLinkListLength()-1))
	{
		return;
	}

	ListNode* pNode = pHead;
	position = position -1;
	while (position--)
	{
		pNode = pNode->next;
	}

	ListNode* pTemp = pNode->next;
	pNode->next = pNode->next->next;
	delete pTemp;
	
}
void LinkList::traverseLinkList()
{
	if (this->isEmpty())
	{
		return;
	}
	ListNode* pNode = pHead->next;
	while (pNode)
	{
		std::cout << pNode->val << "\t";
		pNode = pNode->next;
	}
	std::cout << std::endl;
}
bool LinkList::isEmpty()
{
	if (pHead->next == nullptr)
	{
		return true;
	}

	return false;
}
int LinkList::getLinkListLength()
{
	ListNode* pNode = pHead->next;
	int size = 0;
	while (pNode)
	{
		pNode = pNode->next;
		size++;
	}
	return size;
}
LinkList* LinkList::ReverseLinkList()
{
	LinkList* pRvs = new LinkList;
	ListNode* pNode = this->pHead->next;
	ListNode* pTemp = pRvs->pHead->next;
	while (pNode)
	{
		//pRvs->insertNode(1, pNode->data);

		ListNode* pNew = new ListNode(pNode->val);
		pRvs->pHead->next = pNew;
		pNew->next = pTemp;
		
		pTemp = pRvs->pHead->next;
		pNode = pNode->next;
	}
	return pRvs;
}
void LinkList::deleteLinkList()
{
	ListNode* pNode = pHead->next;
	while (pNode)
	{
		ListNode* pTemp = pNode;
		pNode = pNode->next;
		delete pTemp;
	}
	pHead->next = nullptr;
}