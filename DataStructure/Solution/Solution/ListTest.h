#pragma once
//template <typename T>
//class  ListNode<T>
//{
//	T data;
//	ListNode* next;
//};


struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};


class LinkList
{
public:
	LinkList();
	~LinkList();

	void createLinkList(int size);
	void insertNode(int position, int data);
	void deleteNode(int position);
	void traverseLinkList();
	bool isEmpty();
	int getLinkListLength();
	LinkList* ReverseLinkList();
	void deleteLinkList();
	ListNode *getHead() { return pHead; }
	void setHead(ListNode *head) { pHead = head; }
private:
	ListNode * pHead;

};

