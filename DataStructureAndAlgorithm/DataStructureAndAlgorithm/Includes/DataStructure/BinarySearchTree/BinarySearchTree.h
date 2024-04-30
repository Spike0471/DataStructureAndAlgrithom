#pragma once
#include "DataStructure/BinarySearchTree/BinarySearchTreeNode.h"

template<typename ValueType>
class BinarySearchTree
{
private:
	std::shared_ptr<BinarySearchTreeNode<ValueType>> rootNodePtr;
private:
	std::shared_ptr<BinarySearchTreeNode<ValueType>> searchNodeInternal(ValueType val, std::shared_ptr<BinarySearchTreeNode<ValueType>> current);
	void insertNodeInternal(ValueType val, std::shared_ptr<BinarySearchTreeNode<ValueType>> &current);
public:
	std::shared_ptr<BinarySearchTreeNode<ValueType>> searchNode(ValueType val);
	void insertNode(ValueType val);
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
inline void BinarySearchTree<ValueType>::insertNodeInternal(ValueType val, std::shared_ptr<BinarySearchTreeNode<ValueType>> &current)
{
	if (current.get() == nullptr)
	{
		current = std::make_shared<BinarySearchTreeNode<ValueType>>(val);
		return;
	}

	if (current->value == val)
	{
		return;
	}

	if (current->value < val)
	{
		return insertNodeInternal(val, current->right);
	}

	if (current->value > val)
	{
		return insertNodeInternal(val, current->left);
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
	insertNodeInternal(val, rootNodePtr);
}