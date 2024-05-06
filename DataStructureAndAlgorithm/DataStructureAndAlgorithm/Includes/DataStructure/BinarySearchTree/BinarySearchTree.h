#pragma once
#include "DataStructure/BinaryTreeNode.h"
#include <iostream>

template<typename ValueType>
class BinarySearchTree
{
private:
	std::shared_ptr<BinaryTreeNode<ValueType>> rootNodePtr;
private:
	std::shared_ptr<BinaryTreeNode<ValueType>> searchNodeInternal(ValueType val, std::shared_ptr<BinaryTreeNode<ValueType>> current);
	void insertNodeInternal(ValueType val, std::shared_ptr<BinaryTreeNode<ValueType>>& current);
	void deleteNodeInternal(ValueType val, std::shared_ptr<BinaryTreeNode<ValueType>>& current, std::shared_ptr<BinaryTreeNode<ValueType>>& parent);
	void traverseInternal(std::shared_ptr<BinaryTreeNode<ValueType>> root);
public:
	std::shared_ptr<BinaryTreeNode<ValueType>> searchNode(ValueType val);
	void insertNode(ValueType val);
	void deleteNode(ValueType val);
	void traverse();
};

template<typename ValueType>
inline std::shared_ptr<BinaryTreeNode<ValueType>> BinarySearchTree<ValueType>::searchNodeInternal(ValueType val, std::shared_ptr<BinaryTreeNode<ValueType>> current)
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
inline void BinarySearchTree<ValueType>::insertNodeInternal(ValueType val, std::shared_ptr<BinaryTreeNode<ValueType>>& current)
{
	if (current.get() == nullptr)
	{
		current = std::make_shared<BinaryTreeNode<ValueType>>(val);
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
inline void BinarySearchTree<ValueType>::deleteNodeInternal(ValueType val, std::shared_ptr<BinaryTreeNode<ValueType>>& current, std::shared_ptr<BinaryTreeNode<ValueType>>& parent)
{
	if (current.get() == nullptr)
	{
		return;
	}

	if (current->value < val)
	{
		if (current->right.get() == nullptr)
		{
			return;
		}
		return deleteNodeInternal(val, current->right, current);
	}

	if (current->value > val)
	{
		if (current->left.get() == nullptr)
		{
			return;
		}
		return deleteNodeInternal(val, current->left, current);
	}

	if (current->value == val)
	{
		if (current->left.get() == nullptr && current->right.get() == nullptr)
		{
			current.reset();
			return;
		}

		if (current->left.get() == nullptr)
		{
			if (parent.get() == nullptr)
			{
				rootNodePtr = current->right;
				return;
			}

			if (parent->right.get() == current.get())
			{
				parent->right = current->right;
			}

			if (parent->left.get() == current.get())
			{
				parent->left = current->right;
			}
			return;
		}

		if (current->right.get() == nullptr)
		{
			if (parent.get() == nullptr)
			{
				rootNodePtr = current->left;
				return;
			}

			if (parent->right.get() == current.get())
			{
				parent->right = current->left;
			}

			if (parent->left.get() == current.get())
			{
				parent->left = current->left;
			}
			return;
		}

		auto tmp = current->left;
		while (tmp->right.get() != nullptr)
		{
			tmp = tmp->right;
		}

		tmp->right = current->right;

		if (parent.get() == nullptr)
		{
			rootNodePtr = current->left;
			return;
		}

		if (parent->left.get() == current.get())
		{
			parent->left = current->left;
		}
		else if (parent->right.get() == current.get())
		{
			parent->right = current->left;
		}
		else
		{
			throw std::exception();
		}
		return;
	}
}

template<typename ValueType>
inline void BinarySearchTree<ValueType>::traverseInternal(std::shared_ptr<BinaryTreeNode<ValueType>> root)
{
	if (root.get() == nullptr)
	{
		return;
	}
	if (root->left.get() != nullptr)
	{
		traverseInternal(root->left);
	}

	std::cout << root->value << std::endl;

	if (root->right.get() != nullptr)
	{
		traverseInternal(root->right);
	}
}

template<typename ValueType>
inline std::shared_ptr<BinaryTreeNode<ValueType>> BinarySearchTree<ValueType>::searchNode(ValueType val)
{
	return searchNodeInternal(val, rootNodePtr);
}

template<typename ValueType>
inline void BinarySearchTree<ValueType>::insertNode(ValueType val)
{
	if (rootNodePtr.get() == nullptr)
	{
		rootNodePtr = std::make_shared<BinaryTreeNode<ValueType>>(val);
		return;
	}

	if (rootNodePtr->value < val)
	{
		insertNodeInternal(val, rootNodePtr->right);
		return;
	}

	if (rootNodePtr->value > val)
	{
		insertNodeInternal(val, rootNodePtr->left);
		return;
	}
}

template<typename ValueType>
inline void BinarySearchTree<ValueType>::deleteNode(ValueType val)
{
	std::shared_ptr<BinaryTreeNode<ValueType>> parent;
	deleteNodeInternal(val, rootNodePtr, parent);
}

template<typename ValueType>
inline void BinarySearchTree<ValueType>::traverse()
{
	traverseInternal(rootNodePtr);
}
