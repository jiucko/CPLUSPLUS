#pragma once
#include <string>
#define ALPHABET_SIZE (26)

struct TrieNode
{
	int count;
	char val;
	TrieNode* childNodes[ALPHABET_SIZE];
	TrieNode() :count(0)
	{
		for (int i = 0; i < ALPHABET_SIZE; i++)
		{
			childNodes[i] = nullptr;
		}
	}

};

class TrieTree
{
public:
	TrieTree();
	~TrieTree();
	void insert(std::string s);
	int search(std::string s);
	void print();
private:
	void print(TrieNode* pNode);
private:
	TrieNode* root;
};