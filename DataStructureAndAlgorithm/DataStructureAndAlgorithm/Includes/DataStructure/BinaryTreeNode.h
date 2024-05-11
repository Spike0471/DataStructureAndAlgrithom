#pragma once
#include <memory>

template<typename ValueType>
class BinaryTreeNode
{
public:
	ValueType value;
	BinaryTreeNode<ValueType>* left;
	BinaryTreeNode<ValueType>* right;
public:
	BinaryTreeNode(ValueType val);
	BinaryTreeNode();
	void deleteTree();
};

template<typename ValueType>
inline BinaryTreeNode<ValueType>::BinaryTreeNode(ValueType val) :BinaryTreeNode()
{
	value = val;
}

template<typename ValueType>
inline BinaryTreeNode<ValueType>::BinaryTreeNode()
{
	left = nullptr;
	right = nullptr;
}

template<typename ValueType>
inline void BinaryTreeNode<ValueType>::deleteTree()
{
	if (left != nullptr) 
	{
		left->deleteTree();
		left = nullptr;
	}

	if (right != nullptr) 
	{
		right->deleteTree();
		right = nullptr;
	}

	delete this;
}
