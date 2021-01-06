/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #4: Binary Trees
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 20 February 2019
 ******************************************************************************/
#ifndef BINARYTREE_H_
#define BINARYTREE_H_

#include<iostream>
#include<iomanip>
#include<queue>
using namespace std;


struct Node
{
	int value;     // Integer being input in tree
	Node *parent;  // Parent of node
	Node *left;    // Left child of node
	Node *right;   // Right child of node
};

/*******************************************************************************
 * BinaryTree Class
 * 	 This class represents a BinaryTree object. It manages one attribute: *root
 *******************************************************************************/
class BinaryTree
{
public:
	/******************************
	 ** CONSTRUCTOR & DESTRUCTOR **
	 ******************************/
	BinaryTree();
	~BinaryTree();

	/***************
	 ** MUTATORS **
	 ***************/
	void destroyTree();
    void insert(const int& insertItem);

	/***************
	 ** ACCESSORS **
	 ***************/
	bool isEmpty()const;
	void inOrderTraversal()const;
	void postOrderTraversal()const;
	void preOrderTraversal()const;
	void inOrderTraversal(void(*visit) (int&))const;
	void breadthOrderTraversal()const;
	int treeHeight()const;
	void printLevel()const;
	void displayRelationships()const;

private:
	/***************
	 ** MUTATORS **
	 ***************/
	void destroy(Node* &leaf);

	/***************
	 ** ACCESSORS **
	 ***************/
	void inOrder(Node *leaf)const;
	void postOrder(Node *leaf)const;
	void preOrder(Node *leaf)const;
	int height(Node *leaf)const;
	int max(int x, int y)const;
	void breadthOrder(Node *leaf)const;

    Node *root;   // Root of binary tree (head of linked list)
};

/*******************************************************************************
 * BinaryTree();
 * 	 Constructor; Initializes attributes
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * ~BinaryTree();
 * 	 Destructor; Deallocates the memory
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * destroyTree();
 * 	 Mutator; Destroys the tree/deallocates the memory
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * destroy(Node* &leaf);
 * 	 Mutator; Destroys the tree/deallocates the memory recursively
 * 	 Parameters: leaf (Node) // PROC - node in binary tree
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * isEmpty()const;
 * 	 Accessor; Returns whether or not the tree is empty (true if empty).
 * 	 Parameters: none
 * 	 Return: true or false
 *******************************************************************************/

/*******************************************************************************
 * inOrderTraversal()const;
 * 	 Accessor; Performs and displays the inOrderTraversal.
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * preOrderTraversal()const;
 * 	 Accessor; Performs and displays the pre order traversal.
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * postOrderTraversal()const;
 * 	 Accessor; Performs and displays the post order traversal.
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * inOrder(Node *leaf)const;
 * 	 Accessor; Performs and displays the in order traversal recursively
 * 	 Parameters: leaf (Node) // OUT - binary tree node
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * preOrder(Node *leaf)const;
 * 	 Accessor; Performs and displays the pre order traversal recursively
 * 	 Parameters: leaf (Node) // OUT - binary tree node
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * postOrder(Node *leaf)const;
 * 	 Accessor; Performs and displays the post order traversal recursively
 * 	 Parameters: leaf (Node) // OUT - binary tree node
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * max(int x, int y) const;
 * 	 Accessor; Determines the larger of x and y.
 * 	 Parameters: none
 * 	 Return: x or y
 *******************************************************************************/

/*******************************************************************************
 * treeHeight()const;
 * 	 Accessor; Determines the height of a binary tree
 * 	 Parameters: none
 * 	 Return: height(root) - height of binary tree
 *******************************************************************************/

/*******************************************************************************
 * treeHeight()const;
 * 	 Accessor; Determines the height of a binary tree
 * 	 Parameters: leaf (Node) // PROC - binary tree node
 * 	 Return: height of binary tree
 *******************************************************************************/

/*******************************************************************************
 * printLevel()const;
 * 	 Accessor; Displays the binary tree by level
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * breadthOrderTraversal()const;
 * 	 Accessor; Performs and displays breadth first traversal
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * breadthOrderTraversal()const;
 * 	 Accessor; Performs and displays breadth first traversal
 * 	 Parameters: leaf (Node) // PROC - binary tree node
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * displayRelationships()const;
 * 	 Accessor; Displays the parent-child relationships
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * insert();
 * 	 Mutator; Adds integer to binary tree
 * 	 Parameters: insertItem (integer) // IN - integer being added to tree
 * 	 Return: none
 *******************************************************************************/


#endif /* BINARYTREE_H_ */
