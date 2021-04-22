
#include "BST.h"
#include <stdio.h>
#include <string.h>

int main() {
	BST<int, string> *tree = new BST<int, string>;

	printf("\nTesting insert method to build tree\n");

	tree->insert(77, "seventy-seven");
	tree->insert(70, "seventy");
	tree->insert(75, "seventy-five");
	tree->insert(66, "sixty-six");
	tree->insert(79, "seventy-nine");
	tree->insert(68, "sixty-eight");
	tree->insert(67, "sixty-seven");
	tree->insert(69, "sixty-nine");
	tree->insert(90, "ninety");
	tree->insert(85, "eighty-five");
	tree->insert(83, "eighty-three");
	tree->insert(87, "eighty-seven");
	tree->insert(65, "sixty-five");

	printf("\nThe size of created tree is %i\n", tree->size());

	printf("\nTesting changes to print function (printHelp):\n");
	tree->print();

	printf("\nTesting inorder printing of tree (printInOrder):\n");
	tree->printInOrder();

	printf("\nTesting reverse order printing of tree (printReverse):\n");
	tree->printReverse();

    printf("\nPress Enter to exit");
	getchar();

	return 0;
}