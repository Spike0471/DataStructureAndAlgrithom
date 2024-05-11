#include <iostream>
#include "DataStructure/BinarySearchTree/BinarySearchTree.h"
#include "DataStructure/AVLTree/AVLTree.h"
int main() 
{
	AVLTree<int> tree;
	tree.insertNode(1);
	tree.insertNode(2);
	tree.insertNode(3);
	tree.insertNode(4);
	tree.insertNode(5);
	tree.insertNode(10);
	tree.insertNode(9);
	tree.insertNode(8);
	tree.insertNode(7);
	tree.insertNode(6);
	tree.insertNode(-1);
	tree.traverse();
	tree.test();
	return 0;
}