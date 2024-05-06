#include "DataStructure/BinarySearchTree/BinarySearchTree.h"
#include <iostream>

int main() 
{
	BinarySearchTree<int> tree;
	tree.insertNode(5);
	tree.insertNode(3);
	tree.insertNode(6);
	tree.insertNode(1);
	tree.insertNode(4);
	tree.insertNode(10);
	tree.insertNode(2);
	tree.insertNode(9);
	tree.insertNode(7);
	tree.insertNode(8);
	tree.deleteNode(6);
	tree.deleteNode(7);
	tree.deleteNode(8);
	tree.deleteNode(9);
	tree.deleteNode(1);
	tree.deleteNode(2);
	tree.deleteNode(3);
	tree.deleteNode(4);
	tree.deleteNode(10);
	tree.traverse();
	return 0;
}