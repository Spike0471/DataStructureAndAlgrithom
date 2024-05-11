#pragma once
#include "DataStructure/BinaryTreeNode.h"
#include <iostream>

template<typename ValueType>
class BinarySearchTree
{
protected:
	BinaryTreeNode<ValueType>* rootNodePtr;
protected:
	virtual BinaryTreeNode<ValueType>* searchNodeInternal(ValueType val, BinaryTreeNode<ValueType>* current);
	virtual void insertNodeInternal(ValueType val, BinaryTreeNode<ValueType>** currentPtr);
	virtual void deleteNodeInternal(ValueType val, BinaryTreeNode<ValueType>** currentPtr, BinaryTreeNode<ValueType>* parent);
	virtual void traverseInternal(BinaryTreeNode<ValueType>* root);
public:
	BinaryTreeNode<ValueType>* searchNode(ValueType val);
	virtual void insertNode(ValueType val);
	virtual void deleteNode(ValueType val);
	virtual void traverse();
	BinarySearchTree();
	virtual ~BinarySearchTree();
};

template<typename ValueType>
inline BinaryTreeNode<ValueType>* BinarySearchTree<ValueType>::searchNodeInternal(ValueType val, BinaryTreeNode<ValueType>* current)
{
	if (current == nullptr)
	{
		return current;
	}

	if (current->value == val)
	{
		return current;
	}

	if (current->value < val)
	{
		return searchNodeInternal(val, current->right);
	}

	if (current->value > val)
	{
		return searchNodeInternal(val, current->left);
	}
}

template<typename ValueType>
inline void BinarySearchTree<ValueType>::insertNodeInternal(ValueType val, BinaryTreeNode<ValueType>** currentPtr)
{
	auto current = *currentPtr;
	if (current == nullptr)
	{
		*currentPtr = new BinaryTreeNode<ValueType>(val);
		return;
	}

	if (current->value == val)
	{
		return;
	}

	if (current->value < val)
	{
		return insertNodeInternal(val, &current->right);
	}

	if (current->value > val)
	{
		return insertNodeInternal(val, &current->left);
	}
}

template<typename ValueType>
inline void BinarySearchTree<ValueType>::deleteNodeInternal(ValueType val, BinaryTreeNode<ValueType>** currentPtr, BinaryTreeNode<ValueType>* parent)
{
	auto current = *currentPtr;
	if (current == nullptr)
	{
		return;
	}

	if (current->value < val)
	{
		if (current->right == nullptr)
		{
			return;
		}
		return deleteNodeInternal(val, &current->right, current);
	}

	if (current->value > val)
	{
		if (current->left == nullptr)
		{
			return;
		}
		return deleteNodeInternal(val, &current->left, current);
	}

	if (current->value == val)
	{
		if (current->left == nullptr && current->right == nullptr)
		{
			delete current;
			*currentPtr = nullptr;
			return;
		}

		if (current->left == nullptr)
		{
			if (parent == nullptr)
			{
				rootNodePtr = current->right;
				delete current;
				return;
			}

			if (parent->right == current)
			{
				parent->right = current->right;
			}

			if (parent->left == current)
			{
				parent->left = current->right;
			}
			delete current;
			return;
		}

		if (current->right == nullptr)
		{
			if (parent == nullptr)
			{
				rootNodePtr = current->left;
				delete current;
				return;
			}

			if (parent->right == current)
			{
				parent->right = current->left;
			}

			if (parent->left == current)
			{
				parent->left = current->left;
			}

			delete current;
			return;
		}

		auto tmp = current->left;
		while (tmp->right != nullptr)
		{
			tmp = tmp->right;
		}

		tmp->right = current->right;

		if (parent == nullptr)
		{
			rootNodePtr = current->left;
			delete current;
			return;
		}

		if (parent->left == current)
		{
			parent->left = current->left;
		}
		else if (parent->right == current)
		{
			parent->right = current->left;
		}
		else
		{
			throw std::exception();
		}
		delete current;
		return;
	}
}

template<typename ValueType>
inline void BinarySearchTree<ValueType>::traverseInternal(BinaryTreeNode<ValueType>* root)
{
	if (root == nullptr)
	{
		return;
	}
	if (root->left != nullptr)
	{
		traverseInternal(root->left);
	}

	std::cout << root->value << std::endl;

	if (root->right != nullptr)
	{
		traverseInternal(root->right);
	}
}

template<typename ValueType>
inline BinaryTreeNode<ValueType>* BinarySearchTree<ValueType>::searchNode(ValueType val)
{
	return searchNodeInternal(val, rootNodePtr);
}

template<typename ValueType>
inline void BinarySearchTree<ValueType>::insertNode(ValueType val)
{
	insertNodeInternal(val, &rootNodePtr);
}

template<typename ValueType>
inline void BinarySearchTree<ValueType>::deleteNode(ValueType val)
{
	deleteNodeInternal(val, &rootNodePtr, nullptr);
}

template<typename ValueType>
inline void BinarySearchTree<ValueType>::traverse()
{
	traverseInternal(rootNodePtr);
}

template<typename ValueType>
inline BinarySearchTree<ValueType>::BinarySearchTree() :rootNodePtr(nullptr)
{
}

template<typename ValueType>
inline BinarySearchTree<ValueType>::~BinarySearchTree()
{
	if (rootNodePtr != nullptr)
	{
		rootNodePtr->deleteTree();
	}
}
