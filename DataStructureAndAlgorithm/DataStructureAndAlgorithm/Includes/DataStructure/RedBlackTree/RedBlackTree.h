#pragma once
#include "RedBlackTreeNode.h"

template<typename ValueType>
class RedBlackTree
{
private:
	std::shared_ptr<RedBlackTreeNode<ValueType>> rootNodePtr;
private:
	std::shared_ptr<RedBlackTreeNode<ValueType>> searchInNode(std::shared_ptr<RedBlackTreeNode<ValueType>> root, ValueType val);
	void insertInNode(std::shared_ptr<RedBlackTreeNode<ValueType>> nodePtr, std::shared_ptr<RedBlackTreeNode<ValueType>>& currentNodePtr);
public:
	std::shared_ptr<RedBlackTreeNode<ValueType>> search(ValueType val);
	void insertNode(std::shared_ptr<RedBlackTreeNode<ValueType>> nodePtr);
};

template<typename ValueType>
std::shared_ptr<RedBlackTreeNode<ValueType>> RedBlackTree<ValueType>::searchInNode(std::shared_ptr<RedBlackTreeNode<ValueType>> root, ValueType val)
{
	if (root == nullptr)
	{
		return nullptr;
	}

	if (root->getValue() == val)
	{
		return rootNodePtr;
	}

	if (root->getValue() < val)
	{
		return searchInNode(root->right, val);
	}

	if (root->getValue() > val)
	{
		return searchInNode(root->left, val);
	}

	return nullptr;
}

template<typename ValueType>
inline void RedBlackTree<ValueType>::insertInNode(std::shared_ptr<RedBlackTreeNode<ValueType>> nodePtr, std::shared_ptr<RedBlackTreeNode<ValueType>>& currentNodePtr)
{
	if (currentNodePtr.get() == nullptr)
	{
		currentNodePtr = nodePtr;
		return;
	}

	if (nodePtr->getValue() == currentNodePtr->getValue())
	{
		return;
	}

	if (nodePtr->getValue() < currentNodePtr->getValue())
	{
		return insertInNode(nodePtr, currentNodePtr->left);
	}

	if (nodePtr->getValue() > currentNodePtr->getValue())
	{
		return insertInNode(nodePtr, currentNodePtr->right);
	}
}

template<typename ValueType>
std::shared_ptr<RedBlackTreeNode<ValueType>> RedBlackTree<ValueType>::search(ValueType val)
{
	return searchInNode(rootNodePtr, val);
}

template<typename ValueType>
void RedBlackTree<ValueType>::insertNode(std::shared_ptr<RedBlackTreeNode<ValueType>> nodePtr)
{
	insertInNode(nodePtr, rootNodePtr);
}
