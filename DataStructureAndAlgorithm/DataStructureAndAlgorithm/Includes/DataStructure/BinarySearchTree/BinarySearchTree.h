#pragma once
#include "DataStructure/BinarySearchTree/BinarySearchTreeNode.h"

template<typename ValueType>
class BinarySearchTree
{
private:
	std::shared_ptr<BinarySearchTreeNode<ValueType>> rootNodePtr;
private:
	std::shared_ptr<BinarySearchTreeNode<ValueType>> searchNodeInternal(ValueType val, std::shared_ptr<BinarySearchTreeNode<ValueType>> current);
	void insertNodeInternal(ValueType val, std::shared_ptr<BinarySearchTreeNode<ValueType>>& current, std::shared_ptr<BinarySearchTreeNode<ValueType>>& parent);
public:
	std::shared_ptr<BinarySearchTreeNode<ValueType>> searchNode(ValueType val);
	void insertNode(ValueType val);
	void deleteNode(ValueType val);
};

template<typename ValueType>
inline std::shared_ptr<BinarySearchTreeNode<ValueType>> BinarySearchTree<ValueType>::searchNodeInternal(ValueType val, std::shared_ptr<BinarySearchTreeNode<ValueType>> current)
{
	if (current.get() == nullptr)
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
inline void BinarySearchTree<ValueType>::insertNodeInternal(ValueType val, std::shared_ptr<BinarySearchTreeNode<ValueType>>& current, std::shared_ptr<BinarySearchTreeNode<ValueType>>& parent)
{
	if (current.get() == nullptr)
	{
		current = std::make_shared<BinarySearchTreeNode<ValueType>>(val);
		current->parent = parent;
		return;
	}

	if (current->value == val)
	{
		return;
	}

	if (current->value < val)
	{
		return insertNodeInternal(val, current->right, current);
	}

	if (current->value > val)
	{
		return insertNodeInternal(val, current->left, current);
	}
}

template<typename ValueType>
inline std::shared_ptr<BinarySearchTreeNode<ValueType>> BinarySearchTree<ValueType>::searchNode(ValueType val)
{
	return searchNodeInternal(val, rootNodePtr);
}

template<typename ValueType>
inline void BinarySearchTree<ValueType>::insertNode(ValueType val)
{
	if (rootNodePtr.get() == nullptr)
	{
		rootNodePtr = std::make_shared<BinarySearchTreeNode<ValueType>>(val);
		return;
	}

	if (rootNodePtr->value < val)
	{
		insertNodeInternal(val, rootNodePtr->right, rootNodePtr);
		return;
	}

	if (rootNodePtr->value > val)
	{
		insertNodeInternal(val, rootNodePtr->left, rootNodePtr);
		return;
	}
}

template<typename ValueType>
inline void BinarySearchTree<ValueType>::deleteNode(ValueType val)
{
	auto tobeDeleted = searchNode(val);
	if (tobeDeleted == nullptr)
	{
		return;
	}

	if (tobeDeleted->left.get() == nullptr && tobeDeleted->right.get() == nullptr)
	{
		//TODO: reset the original ptr
		if (tobeDeleted->parent.get() == nullptr) 
		{
			rootNodePtr = nullptr;
			return;
		}

		if (tobeDeleted->parent->left = tobeDeleted) 
		{
			tobeDeleted->parent->left = nullptr;
			return;
		}

		if (tobeDeleted->parent->right = tobeDeleted)
		{
			tobeDeleted->parent->right = nullptr;
			return;
		}
	}

	if (tobeDeleted->left.get() == nullptr)
	{
		tobeDeleted->parent->right = tobeDeleted->right;
		return;
	}

	if (tobeDeleted->right.get() == nullptr)
	{
		tobeDeleted->parent->left = tobeDeleted->left;
		return;
	}
}
