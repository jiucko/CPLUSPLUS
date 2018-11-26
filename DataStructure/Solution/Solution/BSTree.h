#pragma once
#include <iostream>

template <typename T>
struct BSNode 
{
	BSNode()
	{
		lchild = nullptr;
		rchild = nullptr;
		parent = nullptr;
	}

	T value;
	BSNode<T>* lchild;
	BSNode<T>* rchild;
	BSNode<T>* parent;
};


template <typename T>
class BSTree
{
public:
	BSTree();
	~BSTree();

	void preOrder();
	void inOrder();
	void postOrder();
	//void layerOrder();

	BSNode<T>* search_recursion(T key);
	BSNode<T>* search_Iterator(T key);

	T search_minimum();
	T search_maximun();

	//after
	BSNode<T>* sucessor(BSNode<T>* p);
	//before
	BSNode<T>* predecessor(BSNode<T>* p);


	void insert(T key);    //����ָ��ֵ�ڵ�
	void remove(T key);    //ɾ��ָ��ֵ�ڵ�
	void destory();        //���ٶ�����
	//void print();        //��ӡ������


private:
	BSNode<T>* root; //���ڵ�
private:
	BSNode<T>* search(BSNode<T>* & p, T key);
	void remove(BSNode<T>*  p, T key);
	void preOrder(BSNode<T>* p);
	void inOrder(BSNode<T>* p);
	void postOrder(BSNode<T>* p);
	T search_minimun(BSNode<T>* p);
	T search_maximum(BSNode<T>* p);
	void destory(BSNode<T>* &p);

};

template <typename T>
BSTree<T>::BSTree()
{
	//root = new BSNode<T>;
	root = nullptr;
}

template <typename T>
BSTree<T>::~BSTree()
{
	destory();
}

template <typename T>
void BSTree<T>::insert(T key)
{
	BSNode<T>* pNode = root;
	BSNode<T>* pParent = nullptr;
	while (pNode)
	{
		pParent = pNode;
		if (pNode->value < key)
		{
			pNode = pNode->rchild;
		}
		else if (pNode->value > key)
		{
			pNode = pNode->lchild;
		}
		else
		{
			break;
		}
	}

	pNode = new BSNode<T>(t);
	if (pParent == nullptr)
	{
		root = pNode;
	}
	else
	{
		if (key > pParent->value)
		{
			pParent->rchild = pNode;
		}

		if (key < pParent->value)
		{
			pParent->lchild = pNode;
		}
	}
	pnode->parent = pParent;	
}

template <typename T>
void BSTree<T>::remove(T key)
{
	remove(root, key);
}

template <typename T>
void BSTree<T>::remove(BSNode<T>*  p, T key)
{
	if (pnode != nullptr)
	{
		if (pnode->value == key)
		{
			BSNode<T>* pdel = nullptr;

			if (pnode->lchild == nullptr || pnode->rchild == nullptr)
				pdel = pnode;                    //�������������ɾ�ڵ�ֻ��������������������û�к���
			else
				pdel = predecessor(pnode);      //���һ����ɾ�ڵ�ͬʱ��������������ɾ���ýڵ��ǰ��

												//��ʱ����ɾ�ڵ�ֻ��һ�����ӣ���û�к��ӣ�.����ú���ָ��
			BSNode<T>* pchild = nullptr;
			if (pdel->lchild != nullptr)
				pchild = pdel->lchild;
			else
				pchild = pdel->rchild;

			//�ú���ָ��ɾ���ڵ�ĸ��ڵ�
			if (pchild != nullptr)
				pchild->parent = pdel->parent;

			//���Ҫɾ���Ľڵ���ͷ�ڵ㣬ע�����root��ֵ
			if (pdel->parent == nullptr)
				root = pchild;

			//���Ҫɾ���Ľڵ㲻��ͷ�ڵ㣬Ҫע���������˫�׽ڵ�ָ���µĺ��ӽڵ�
			else if (pdel->parent->lchild == pdel)
			{
				pdel->parent->lchild = pchild;
			}
			else
			{
				pdel->parent->rchild = pchild;
			}

			if (pnode->value != pdel->value)
				pnode->value = pdel->value;
			delete pdel;
		}
		//���еݹ�ɾ��
		else if (key > pnode->value)
		{
			remove(pnode->rchild, key);
		}
		else remove(pnode->lchild, key);
	}
}

template <typename T>
void BSTree<T>::preOrder()
{
	preOrder(root);
}
template <typename T>
void BSTree<T>::preOrder(BSNode<T>* p)
{
	if (p)
	{
		std::cout << p->value << std::endl;
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}

template <typename T>
void BSTree<T>::inOrder()
{
	inOrder(root);
}

template <typename T>
void BSTree<T>::inOrder(BSNode<T>* p)
{
	if (p != nullptr)
	{
		inOrder(p->lchild);
		std::cout << p->value << std::endl;
		inOrder(p->rchild);
	}
}

template <typename T>
void BSTree<T>::postOrder()
{
	postOrder(root);
}

template <typename T>
void BSTree<T>::postOrder(BSNode<T>* p)
{
	if (p != nullptr)
	{
		postOrder(p->lchild);
		std::cout << p->value << std::endl;
		postOrder(p->rchild);
	}
}

template <typename T>
BSNode<T>* BSTree<T>::search_recursion(T key)
{
	return search(root, key);
}

template <typename T>
BSNode<T>* BSTree<T>::search(BSNode<T>* & p, T key)
{
	if (p == nullptr)
		return nullptr;

	if (p->value == key)
		return p;

	if (p->value > key)
		return search(p->lchild, key);
	else
		return search(p->rchild, key);
}

template <typename T>
BSNode<T>* BSTree<T>::search_Iterator(T key)
{
	BSNode<T>* pNode = root;

	while (pNode)
	{
		if (pNode->value == key)
		{
			break;
		}
		else if (pNode->value > key)
		{
			pNode = pNode->lchild;
		}
		else
		{
			pNode = pNode->rchild;
		}
	}

	return pNode;
}

template <typename T>
T BSTree<T>::search_minimum()
{
	return search_minimun(root);
}

template <typename T>
T BSTree<T>::search_minimun(BSNode<T>* p)
{
	if (p == nullptr)
		return 0;
	if (p->lchild != nullptr)
	{
		return search_minimun(p->lchild);
	}

	return p->value;
}

template <typename T>
T BSTree<T>::search_maximun()
{
	return search_maximum(root);
}

template <typename T>
T BSTree<T>::search_maximum(BSNode<T>* p)
{
	if (p == nullptr)
		return 0;
	if (p->rchild)
	{
		return search_maxinum(p->rchild);
	}

	return p->value;
}

template <typename T>
BSNode<T>* BSTree<T>::predecessor(BSNode<T>* p)
{
	if (p == nullptr)
		return nullptr;

	BSNode<T>* pNode = nullptr;
	if (p->lchild)
	{
		pNode = search_maximum(p->lchild);
	}
	else
	{
		while (p->parent != nullptr)
		{
			if (p == p->parent->rchild)
			{
				pNode = p->parent;
				break;
			}
			p = p->parent;
		}
	}

	return pNode;
}

template <typename T>
BSNode<T>* BSTree<T>::sucessor(BSNode<T>* p)
{
	if (p == nullptr)
		return nullptr;

	BSNode<T>* pNode = nullptr;
	if (p->rchild)
	{
		pNode = search_minimum(rchild);
	}
	else
	{
		while (p->parent)
		{
			if (p->parent->lchild = p)
			{
				pNode = p->parent;
				break;
			}
			p = p->parent;
		}
	}
	return pNode;
}

template <typename T>
void BSTree<T>::destory()
{
	destory(root);
}

template <typename T>
void BSTree<T>::destory(BSNode<T>* &p)
{

}