#pragma once
#include "DataStructure/BinaryTreeNode.h"

template<typename ValueType>
class AVLTreeNode :public BinaryTreeNode<ValueType>
{
public:
	int depth;
public:
	AVLTreeNode(ValueType val, int dep);
};

template<typename ValueType>
inline AVLTreeNode<ValueType>::AVLTreeNode(ValueType val, int dep) :BinaryTreeNode<ValueType>()
{
	this->value = val;
	this->depth = dep;
}
