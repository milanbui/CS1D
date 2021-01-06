/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #4: Binary Trees
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 20 February 2019
 * SCORE        : 10/10
 ******************************************************************************/
#include <iostream>
#include "binaryTree.h"
#include "printHeader.h"
using namespace std;
/*******************************************************************************
 * BINARY SEARCH TREE AND TRAVERSALS
 * _____________________________________________________________________________
 *
 * This program will create binary search tree, perform and display traversals
 * (in order, post order, pre order, breadth first), display the binary tree by
 * level, and display the parent-child relationships.
 * _____________________________________________________________________________
 * INPUT:
 *	    treeRoot - binary tree object
 *
 * OUTPUT:
 *      treeRoot - binary tree object
 *
 ******************************************************************************/
int main()
{
	// Declare variables
	BinaryTree treeRoot;  // PROC/OUT - binary tree object

	// OUTPUT -- display the class header and program description
	cout << printHeader("Binary Trees", 4);
	cout << "THIS PROGRAM WILL:" << endl;
	cout << "1. Create a binary search tree" << endl;
	cout << "2. Perform and display an in order traversal" << endl;
	cout << "3. Perform and display an pre order traversal" << endl;
	cout << "4. Perform and display an post order traversal" << endl;
	cout << "5. Perform and display an breadth first traversal" << endl;
	cout << "6. Display the binary tree by level" << endl;
	cout << "7. Display the parent-child relationships" << endl << endl << endl;

	// INPUT -- inserting numbers into binary search tree
	treeRoot.insert(109);
	treeRoot.insert(55);
	treeRoot.insert(118);
	treeRoot.insert(89);
	treeRoot.insert(33);
	treeRoot.insert(1001);
	treeRoot.insert(18);
	treeRoot.insert(44);
	treeRoot.insert(88);
	treeRoot.insert(12);
	treeRoot.insert(24);
	treeRoot.insert(49);
	treeRoot.insert(7);
	treeRoot.insert(25);
	treeRoot.insert(59);
	treeRoot.insert(28);
	treeRoot.insert(19);
	treeRoot.insert(13);
	treeRoot.insert(888);


	// OUTPUT -- outputs the traversals, the tree by level, and the parent-child
	//           relationships
	cout << "IN ORDER TRAVERSAL:" << endl;
	treeRoot.inOrderTraversal();
	cout << endl;
	cout << endl;

	cout << "PRE ORDER TRAVERSAL:" << endl;
	treeRoot.preOrderTraversal();
	cout << endl;
	cout << endl;

	cout << "POST ORDER TRAVERSAL:" << endl;
	treeRoot.postOrderTraversal();
	cout << endl;
	cout << endl;

	cout << "BREADTH FIRST TRAVERSAL:" << endl;
	treeRoot.breadthOrderTraversal();
	cout << endl;
	cout << endl;

	cout << "PRINT TREE BY LEVEL:" << endl;
	treeRoot.printLevel();
	cout << endl;

	cout << "DISPLAY PARENT-CHILD RELATIONSHIPS:" << endl;
	treeRoot.displayRelationships();
	cout << endl;
	cout << endl;


	return 0;
}


