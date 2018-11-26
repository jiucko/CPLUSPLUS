#pragma once
#include <iostream>

using namespace std;

template <typename T>
struct AVLTreeNode
{
	AVLTreeNode(T t) :val(t), hight(0), lchild(nullprt), rchild(nullptr) {}
	
	T val;
	int hight;
	AVLTreeNode<T>* lchild;
	AVLTreeNode<T>* rchild;
};

template <typename T>
class AVLTree
{
public:
	AVLTree();
	~AVLTree();

	void preOrder();
	void inOrder();
	void postOrder();

	void destory();
	void insert(T key);
private:
	void preOrder(AVLTreeNode<T>* p);
	void inOrder(AVLTreeNode<T>* p);
	void postOrder(AVLTreeNode<T>* p);
	void destory(AVLTreeNode<T>* p);

	void insert(AVLTreeNode<T>* p, T key);

	AVLTreeNode<T>* leftRotation(AVLTreeNode<T>* pnode);		//µ¥Ðý:×óÐý²Ù×÷
	AVLTreeNode<T>* rightRotation(AVLTreeNode<T>* pnode);		//µ¥Ðý:ÓÒÐý²Ù×÷
	AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* pnode);	//Ë«Ðý:ÏÈ×óÐýºóÓÒÐý²Ù×÷
	AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* pnode);	//Ë«Ðý:ÏÈÓÒÐýºó×óÐý²Ù×÷
private:
	AVLTreeNode<T>* root;

};

template <typename T>
AVLTree<T>::AVLTree():root(nullptr)
{

}

template <typename T>
AVLTree<T>::~AVLTree()
{

}

template <typename T>
void AVLTree<T>::preOrder()
{
	preOrder(root);
}

template <typename T>
void AVLTree<T>::preOrder(AVLTreeNode<T>* p)
{
	if (p)
	{
		cout << p->val;
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}

template <typename T>
void AVLTree<T>::inOrder()
{
	inOrder(root);
}

template <typename T>
void AVLTree<T>::inOrder(AVLTreeNode<T>* p)
{
	if (p)
	{
		inOrder(p->lchild);
		cout << p->val;
		inOrder(p->rchild);
	}
}

template <typename T>
void AVLTree<T>::postOrder()
{
	postOrder(root);
}

template <typename T>
void AVLTree<T>::postOrder(AVLTreeNode<T>* p)
{
	if (p)
	{
		postOrder(p->lchild);
		postOrder(p->rchild);
		cout << p->val;
	}
}

template <typename T>
void AVLTree<T>::destory()
{
	destory(root);
}

template <typename T>
void AVLTree<T>::destory(AVLTreeNode<T>* p)
{
	if (p)
	{
		destory(p->lchild);
		destory(p->rchild);
		delete p;
		p = nullptr;
	}
}

template <typename T>
void AVLTree<T> ::insert(T key)
{
	insert(root, key);
}

template <typename T>
void AVLTree<T>::insert(AVLTreeNode<T>* p, T key)
{

}

template <typename T>
AVLTreeNode<T>* leftRotation(AVLTreeNode<T>* pnode)
{

}