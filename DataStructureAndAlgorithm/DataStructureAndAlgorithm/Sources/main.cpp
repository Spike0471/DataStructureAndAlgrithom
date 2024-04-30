#include "DataStructure/BinarySearchTree/BinarySearchTree.h"
#include <iostream>

int main() 
{
	BinarySearchTree<int> tree;
	tree.insertNode(1);
	tree.insertNode(3);
	tree.deleteNode(3);
	return 0;
}