#pragma once

#include <memory>

template<typename ValueType>
class RedBlackTreeNode
{
private:
	bool isBlack;
	ValueType value;
public:
	std::shared_ptr<RedBlackTreeNode<ValueType>> left;
	std::shared_ptr<RedBlackTreeNode<ValueType>> right;
public:
	RedBlackTreeNode(ValueType val, bool black = true) { value = val; isBlack = black; }
	bool red();
	bool black();
	bool isLeaf();
	ValueType getValue();
};

template<typename ValueType>
ValueType RedBlackTreeNode<ValueType>::getValue()
{
	return value;
}

template<typename ValueType>
inline bool RedBlackTreeNode<ValueType>::red()
{
	return !isBlack;
}

template<typename ValueType>
inline bool RedBlackTreeNode<ValueType>::black()
{
	return isBlack;
}

template<typename ValueType>
inline bool RedBlackTreeNode<ValueType>::isLeaf()
{
	return left == nullptr && right == nullptr;
}
