#include "DataStructure/BinarySearchTree/BinarySearchTree.h"
#include <iostream>

int main() 
{
	BinarySearchTree<int> tree;
	tree.insertNode(3);
	tree.insertNode(2);
	tree.insertNode(4);
	auto test = tree.searchNode(3);
	std::cout << test->value <<std::endl;
	return 0;
}