#pragma once

template <typename T>
struct AVLNode
{
	int hight;
	T val;
	AVLNode<T>* lchild;
	AVLNode<T>* rchild;

	AVLNode(T x) :val(x), lchild(nullptr), rchild(nullptr)
	{
		hight = 0;
	}
};

template <typename T>
class AVLTree
{
	AVLTree();
	~AVLTree();

	void preOrder();    //ǰ�����AVL��
	void InOrder();        //�������AVL��   
	void postOrder();    //�������AVL��

	void print();        //��ӡAVL��
	void destory();        //����AVL��

	void insert(T key);    //����ָ��ֵ�Ľڵ�
	void remove(T key);    //�Ƴ�ָ��ֵ�Ľڵ�

	AVLTreeNode<T>* search_recurse(T key);    //���õݹ��㷨����ָ��ֵ�Ĳ���
	AVLTreeNode<T>* search_iterator(T key);    //���õ����㷨����ָ��ֵ�Ĳ���
	T minimum();        //����AVL�е���Сֵ
	T maximum();        //����AVL�е����ֵ

	int height();        //�������ĸ߶�

private:
	AVLTreeNode<T>* root;    //AVL���ĸ��ڵ�

private:
	void preOrder(AVLTreeNode<T>* pnode) const;
	void inOrder(AVLTreeNode<T>* pnode) const;
	void postOrder(AVLTreeNode<T>* pnode) const;

	void print(AVLTreeNode<T>* pnode, T key, int direction) const;
	void destory(AVLTreeNode<T>* & pnode);
	int height(AVLTreeNode<T>* & pnode);

	AVLTreeNode<T>* insert(AVLTreeNode<T>* &pnode, T key);
	AVLTreeNode<T>* remove(AVLTreeNode<T>* & pnode, AVLTreeNode<T>* pdel); //ɾ��AVL���нڵ�pdel�������ر�ɾ���Ľڵ�

	AVLTreeNode<T>* minimum(AVLTreeNode<T>*pnode)const;
	AVLTreeNode<T>* maximum(AVLTreeNode<T>*pnode)const;

	AVLTreeNode<T>* search_recurse(AVLTreeNode<T>* pnode, T key) const;
	AVLTreeNode<T>* search_iterator(AVLTreeNode<T>* pnode, T key) const;

	AVLTreeNode<T>* leftRotation(AVLTreeNode<T>* pnode);        //����:��������
	AVLTreeNode<T>* rightRotation(AVLTreeNode<T>* pnode);        //����:��������
	AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* pnode);    //˫��:����������������
	AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* pnode);    //˫��:����������������
};

template <typename T>
AVLTre<T>::AVLTree()
{
	root = nullptr;
}

template <typename T>
AVLTree<T>::~AVLTree()
{
	destory();
}

template <typename T>
int AVLTree<T>::height()
{
	height(root);
}

template <typename T>
int AVLTree<T>::height(AVLTreeNode<T>* & pNode)
{
	if (pNode != nullptr)
	{
		return pNode->height;
	}
	else
	{
		return 0;
	}
}

template <typename T>
AVLTreeNode<T>* AVLTree<T>::leftRotation(AVLTreeNode<T>* proot)
{	
	AVLTreeNode<T>* prchild = proot->rchild;
	proot->rchild = prchild->lchild;
	prchild->lchild = proot;

	proot->height = max(height(proot->lchild), height(proot->rchild)) + 1;     //���½ڵ�ĸ߶�ֵ
	prchild->height = max(height(prchild->lchild), height(prchild->rchild)) + 1; //���½ڵ�ĸ߶�ֵ

	return prchild;
}

template <typename T>
AVLTreeNode<T>* AVLTree<T>::rightRotation(AVLTreeNode<T>* proot)       //����:��������
{
	AVLTreeNode<T>* plchild = proot->lchild;
	proot->lchild = plchild->rchild;
	plchild->rchild = proot;

	proot->height = max(height(proot->lchild), height(proot->rchild)) + 1;     //���½ڵ�ĸ߶�ֵ
	plchild->height = max(height(plchild->lchild), height(plchild->rchild)) + 1; //���½ڵ�ĸ߶�ֵ

	return plchild;
}