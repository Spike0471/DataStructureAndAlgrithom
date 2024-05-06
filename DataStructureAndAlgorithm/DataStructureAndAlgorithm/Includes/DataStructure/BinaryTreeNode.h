#pragma once
#include <memory>

template<typename ValueType>
class BinaryTreeNode
{
public:
	ValueType value;
	std::shared_ptr<BinaryTreeNode<ValueType>> left;
	std::shared_ptr<BinaryTreeNode<ValueType>> right;
public:
	BinaryTreeNode(ValueType val);
};

template<typename ValueType>
inline BinaryTreeNode<ValueType>::BinaryTreeNode(ValueType val)
{
	value = val;
}
