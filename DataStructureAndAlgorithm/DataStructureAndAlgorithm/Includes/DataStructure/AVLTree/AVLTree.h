#pragma once
#include "DataStructure/AVLTree/AVLTreeNode.h"

#define GET_MAX_SIZE(x,y) ((x)>(y)?(x):(y))

template<typename ValueType>
class AVLTree :public BinarySearchTree<ValueType>
{
private:
	void updateDepth(AVLTreeNode<ValueType>* root);
protected:
	void leftRotate(AVLTreeNode<ValueType>** rootPtr);
	void rightRotate(AVLTreeNode<ValueType>** rootPtr);
	void rebalanceInternal(AVLTreeNode<ValueType>** rootPtr, int threshold = 2);
	void insertNodeInternal(ValueType val, BinaryTreeNode<ValueType>** currentPtr) override;
	void deleteNodeInternal(ValueType val, BinaryTreeNode<ValueType>** currentPtr, BinaryTreeNode<ValueType>* parent) override;
	void traverseInternal(BinaryTreeNode<ValueType>* root) override;
public:
	void test();
	AVLTree();
};

template<typename ValueType>
inline void AVLTree<ValueType>::updateDepth(AVLTreeNode<ValueType>* root)
{
	if (root == nullptr)
	{
		return;
	}

	if (root->left == nullptr && root->right == nullptr)
	{
		root->depth = 1;
		return;
	}

	if (root->left == nullptr)
	{
		updateDepth((AVLTreeNode<ValueType>*)root->right);
		((AVLTreeNode<ValueType>*)root)->depth = ((AVLTreeNode<ValueType>*)(root->right))->depth + 1;
		return;
	}
	if (root->right == nullptr)
	{
		updateDepth((AVLTreeNode<ValueType>*)root->left);
		((AVLTreeNode<ValueType>*)root)->depth = ((AVLTreeNode<ValueType>*)(root->left))->depth + 1;
		return;
	}

	updateDepth((AVLTreeNode<ValueType>*)root->left);
	updateDepth((AVLTreeNode<ValueType>*)root->right);
	((AVLTreeNode<ValueType>*)root)->depth = GET_MAX_SIZE(((AVLTreeNode<ValueType>*)root->left)->depth, ((AVLTreeNode<ValueType>*)root->right)->depth) + 1;
}

template<typename ValueType>
inline void AVLTree<ValueType>::leftRotate(AVLTreeNode<ValueType>** rootPtr)
{
	auto root = *rootPtr;
	if (root == nullptr)
	{
		return;
	}
	auto pivot = root->right;
	if (pivot == nullptr)
	{
		return;
	}

	AVLTreeNode<ValueType>* tmpRoot;
	tmpRoot = root;
	*rootPtr = (AVLTreeNode<ValueType>*)pivot;
	tmpRoot->right = pivot->left;
	pivot->left = tmpRoot;
}

template<typename ValueType>
inline void AVLTree<ValueType>::rightRotate(AVLTreeNode<ValueType>** rootPtr)
{
	auto root = *rootPtr;
	if (root == nullptr)
	{
		return;
	}
	auto pivot = root->left;
	if (pivot == nullptr)
	{
		return;
	}

	AVLTreeNode<ValueType>* tmpRoot;
	tmpRoot = root;
	*rootPtr = (AVLTreeNode<ValueType>*)pivot;
	tmpRoot->left = pivot->right;
	pivot->right = tmpRoot;
}

template<typename ValueType>
inline void AVLTree<ValueType>::rebalanceInternal(AVLTreeNode<ValueType>** rootPtr, int threshold)
{
	auto root = *rootPtr;
	if (root == nullptr)
	{
		return;
	}

	int leftDepth = root->left == nullptr ? 0 : ((AVLTreeNode<ValueType>*)root->left)->depth;
	int rightDepth = root->right == nullptr ? 0 : ((AVLTreeNode<ValueType>*)root->right)->depth;
	int delta = leftDepth - rightDepth;
	if (delta <= -threshold)
	{
		rebalanceInternal((AVLTreeNode<ValueType>**)(&root->right), 1);
		leftRotate(rootPtr);
	}
	else if (delta >= threshold)
	{
		rebalanceInternal((AVLTreeNode<ValueType>**)(&root->left), 1);
		rightRotate(rootPtr);
	}
}


template<typename ValueType>
inline void AVLTree<ValueType>::insertNodeInternal(ValueType val, BinaryTreeNode<ValueType>** currentPtr)
{
	auto current = *currentPtr;
	if (current == nullptr)
	{
		*currentPtr = new AVLTreeNode<ValueType>(val, -1);
		return;
	}

	if (current->value == val)
	{
		return;
	}

	if (current->value > val)
	{
		insertNodeInternal(val, &current->left);
	}

	if (current->value < val)
	{
		insertNodeInternal(val, &current->right);
	}

	updateDepth((AVLTreeNode<ValueType>*)(*currentPtr));
	rebalanceInternal((AVLTreeNode<ValueType>**)currentPtr);
	updateDepth((AVLTreeNode<ValueType>*) (*currentPtr));
}

template<typename ValueType>
inline void AVLTree<ValueType>::deleteNodeInternal(ValueType val, BinaryTreeNode<ValueType>** currentPtr, BinaryTreeNode<ValueType>* parent)
{
}

template<typename ValueType>
inline void AVLTree<ValueType>::traverseInternal(BinaryTreeNode<ValueType>* root)
{
	if (root == nullptr)
	{
		return;
	}
	if (root->left != nullptr)
	{
		traverseInternal(root->left);
	}

	std::cout << root->value << " : <" << ((AVLTreeNode<ValueType>*)root)->depth << ">" << std::endl;

	if (root->right != nullptr)
	{
		traverseInternal(root->right);
	}
}

template<typename ValueType>
inline void AVLTree<ValueType>::test()
{
	auto root = (AVLTreeNode<ValueType>*)this->rootNodePtr;
	std::cout << "root depth: " << root->depth << std::endl;
}

template<typename ValueType>
inline AVLTree<ValueType>::AVLTree()
{
}
