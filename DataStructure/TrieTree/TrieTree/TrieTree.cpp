// TrieTree.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "TrieTree.h"

#include <iostream>

TrieTree::TrieTree()
{
	root = new TrieNode;
}
TrieTree::~TrieTree()
{
	//delete root;
}
void TrieTree::insert(std::string s)
{
	TrieNode* pNode = root;
	
	int i = 0;
	while (i<s.size())
	{
		char p = s[i];
		if (pNode->childNodes[p - 'a'] == nullptr)
		{
			TrieNode* pNew = new TrieNode;
			pNew->val = p;
			pNode->childNodes[p - 'a'] = pNew;
		}
		pNode = pNode->childNodes[p - 'a'];
		i++;
	}
	pNode->count++;
}
int TrieTree::search(std::string s)
{
	TrieNode* pNode = root;
	int i = 0;
	while (i < s.size()&&pNode)
	{
		char p = s[i];
		if (pNode->childNodes[p - 'a'] == nullptr)
		{
			break;
		}
		pNode = pNode->childNodes[p - 'a'];
		i++;
	}

	if (pNode == nullptr)
		return 0;
	else
		return pNode->count;

}
void TrieTree::print()
{
	print(this->root);
}

void TrieTree::print(TrieNode* pNode)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (pNode->childNodes[i] != nullptr)
		{
			std::cout << pNode->childNodes[i]->val;
			print(pNode->childNodes[i]);
		}
	}
}




int main()
{
	TrieTree* p = new TrieTree;
	p->insert("hello");
	p->insert("hi");
	p->insert("ingress");
	p->insert("intel");
	std::cout << p->search("hi") << std::endl;
	p->print();
	
	return 0;
}

