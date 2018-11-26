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

	void preOrder();    //前序遍历AVL树
	void InOrder();        //中序遍历AVL树   
	void postOrder();    //后序遍历AVL树

	void print();        //打印AVL树
	void destory();        //销毁AVL树

	void insert(T key);    //插入指定值的节点
	void remove(T key);    //移除指定值的节点

	AVLTreeNode<T>* search_recurse(T key);    //利用递归算法进行指定值的查找
	AVLTreeNode<T>* search_iterator(T key);    //利用迭代算法进行指定值的查找
	T minimum();        //返回AVL中的最小值
	T maximum();        //返回AVL中的最大值

	int height();        //返回树的高度

private:
	AVLTreeNode<T>* root;    //AVL树的根节点

private:
	void preOrder(AVLTreeNode<T>* pnode) const;
	void inOrder(AVLTreeNode<T>* pnode) const;
	void postOrder(AVLTreeNode<T>* pnode) const;

	void print(AVLTreeNode<T>* pnode, T key, int direction) const;
	void destory(AVLTreeNode<T>* & pnode);
	int height(AVLTreeNode<T>* & pnode);

	AVLTreeNode<T>* insert(AVLTreeNode<T>* &pnode, T key);
	AVLTreeNode<T>* remove(AVLTreeNode<T>* & pnode, AVLTreeNode<T>* pdel); //删除AVL树中节点pdel，并返回被删除的节点

	AVLTreeNode<T>* minimum(AVLTreeNode<T>*pnode)const;
	AVLTreeNode<T>* maximum(AVLTreeNode<T>*pnode)const;

	AVLTreeNode<T>* search_recurse(AVLTreeNode<T>* pnode, T key) const;
	AVLTreeNode<T>* search_iterator(AVLTreeNode<T>* pnode, T key) const;

	AVLTreeNode<T>* leftRotation(AVLTreeNode<T>* pnode);        //单旋:左旋操作
	AVLTreeNode<T>* rightRotation(AVLTreeNode<T>* pnode);        //单旋:右旋操作
	AVLTreeNode<T>* leftRightRotation(AVLTreeNode<T>* pnode);    //双旋:先左旋后右旋操作
	AVLTreeNode<T>* rightLeftRotation(AVLTreeNode<T>* pnode);    //双旋:先右旋后左旋操作
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

	proot->height = max(height(proot->lchild), height(proot->rchild)) + 1;     //更新节点的高度值
	prchild->height = max(height(prchild->lchild), height(prchild->rchild)) + 1; //更新节点的高度值

	return prchild;
}

template <typename T>
AVLTreeNode<T>* AVLTree<T>::rightRotation(AVLTreeNode<T>* proot)       //单旋:右旋操作
{
	AVLTreeNode<T>* plchild = proot->lchild;
	proot->lchild = plchild->rchild;
	plchild->rchild = proot;

	proot->height = max(height(proot->lchild), height(proot->rchild)) + 1;     //更新节点的高度值
	plchild->height = max(height(plchild->lchild), height(plchild->rchild)) + 1; //更新节点的高度值

	return plchild;
}