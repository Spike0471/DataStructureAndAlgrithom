#pragma once
#include <memory>

template<typename ValueType>
class BinarySearchTreeNode
{
public:
	ValueType value;
	std::shared_ptr<BinarySearchTreeNode> parent;
	std::shared_ptr<BinarySearchTreeNode> left;
	std::shared_ptr<BinarySearchTreeNode> right;
public:
	BinarySearchTreeNode(ValueType val);
};

template<typename ValueType>
inline BinarySearchTreeNode<ValueType>::BinarySearchTreeNode(ValueType val)
{
	value = val;
}
