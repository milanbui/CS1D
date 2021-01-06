/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #4: Binary Trees
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 20 February 2019
 ******************************************************************************/
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
BinaryTree::BinaryTree()
{
	root = NULL;
}

/*******************************************************************************
 * ~BinaryTree();
 * 	 Destructor; Deallocates the memory
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
BinaryTree::~BinaryTree()
{
	destroy(root);
}

/*******************************************************************************
 * destroyTree();
 * 	 Mutator; Destroys the tree/deallocates the memory
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
void BinaryTree::destroyTree()
{
	destroy(root);
}

/*******************************************************************************
 * destroy(Node* &leaf);
 * 	 Mutator; Destroys the tree/deallocates the memory recursively
 * 	 Parameters: leaf (Node) // PROC - node in binary tree
 * 	 Return: none
 *******************************************************************************/
void BinaryTree::destroy(Node* &leaf)
{
	if (leaf!= NULL)
	{
		destroy(leaf->left);
		destroy(leaf->right);
		destroy(leaf->parent);
		delete leaf;
		leaf = NULL;
	}
}


/*******************************************************************************
 * isEmpty()const;
 * 	 Accessor; Returns whether or not the tree is empty (true if empty).
 * 	 Parameters: none
 * 	 Return: true or false
 *******************************************************************************/
bool BinaryTree::isEmpty()const
{
	return(root == NULL);
}

/*******************************************************************************
 * inOrderTraversal()const;
 * 	 Accessor; Performs and displays the inOrderTraversal.
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
void BinaryTree::inOrderTraversal()const
{
	inOrder(root);
}

/*******************************************************************************
 * preOrderTraversal()const;
 * 	 Accessor; Performs and displays the pre order traversal.
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
void BinaryTree::preOrderTraversal()const
{
	preOrder(root);
}

/*******************************************************************************
 * postOrderTraversal()const;
 * 	 Accessor; Performs and displays the post order traversal.
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
void BinaryTree::postOrderTraversal()const
{
	postOrder(root);
}

/*******************************************************************************
 * inOrder(Node *leaf)const;
 * 	 Accessor; Performs and displays the in order traversal recursively
 * 	 Parameters: leaf (Node) // OUT - binary tree node
 * 	 Return: none
 *******************************************************************************/
void BinaryTree::inOrder(Node *leaf)const
{
	if(leaf != NULL)
	{
		inOrder(leaf->left);
		cout << leaf->value << " ";
		inOrder(leaf->right);
	}
}

/*******************************************************************************
 * preOrder(Node *leaf)const;
 * 	 Accessor; Performs and displays the pre order traversal recursively
 * 	 Parameters: leaf (Node) // OUT - binary tree node
 * 	 Return: none
 *******************************************************************************/
void BinaryTree::preOrder(Node *leaf)const
{
	if(leaf != NULL)
	{
		cout << leaf->value << " ";
		inOrder(leaf->left);
		inOrder(leaf->right);
	}
}

/*******************************************************************************
 * postOrder(Node *leaf)const;
 * 	 Accessor; Performs and displays the post order traversal recursively
 * 	 Parameters: leaf (Node) // OUT - binary tree node
 * 	 Return: none
 *******************************************************************************/
void BinaryTree::postOrder(Node *leaf)const
{
	if(leaf != NULL)
	{
		inOrder(leaf->left);
		inOrder(leaf->right);
		cout << leaf->value << " ";
	}
}

/*******************************************************************************
 * max(int x, int y) const;
 * 	 Accessor; Determines the larger of x and y.
 * 	 Parameters: none
 * 	 Return: x or y
 *******************************************************************************/
int BinaryTree::max(int x, int y) const
{
	if(x >= y)
	{
		return x;
	}
	else
	{
		return y;
	}
}

/*******************************************************************************
 * treeHeight()const;
 * 	 Accessor; Determines the height of a binary tree
 * 	 Parameters: none
 * 	 Return: height(root) - height of binary tree
 *******************************************************************************/
int BinaryTree::treeHeight()const
{
	return height(root);
}

/*******************************************************************************
 * treeHeight()const;
 * 	 Accessor; Determines the height of a binary tree
 * 	 Parameters: leaf (Node) // PROC - binary tree node
 * 	 Return: height of binary tree
 *******************************************************************************/
int BinaryTree::height(Node *leaf)const
{
	// If tree is empty
	if(leaf == NULL)
	{
		return 0;
	}
	else
	{
		// Add recursively to find height
		return (1 + max(height(leaf->left), height(leaf->right)));
	}
}

/*******************************************************************************
 * printLevel()const;
 * 	 Accessor; Displays the binary tree by level
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
void BinaryTree::printLevel()const
{
	// If tree is empty
	if(root == NULL)
	{
		return;
	}

	// Declare variables
	queue<Node*>temp;    // PROC/OUT - temporary variable for tree as a queue

	// Push the values in root(push the tree)
	temp.push(root);

	// While the tree is not empty
	while(temp.empty() == false)
	{
		// PROC - set the node count to the size of the tree
		int nodeCount = temp.size();

		// While there are still nodes to display
		while(nodeCount > 0)
		{
			// Sets node to the node at top of list
			Node *node = temp.front();

			// OUTPUT -- outputs the value of the node in the tree
			cout << node->value << " ";

			// PROC -- deletes node from queue
			temp.pop();

			// If there is a left child
			if(node->left != NULL)
			{
				// Add left child to back of queue
				temp.push(node->left);
			}
			// If there is a right child
			if(node->right != NULL)
			{
				// Add right child to back of queue
				temp.push(node->right);
			}

			// Decrement node count
			nodeCount--;
		}
		cout << endl;
	}
}

/*******************************************************************************
 * breadthOrderTraversal()const;
 * 	 Accessor; Performs and displays breadth first traversal
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
void BinaryTree::breadthOrderTraversal()const
{
	breadthOrder(root);
}

/*******************************************************************************
 * breadthOrderTraversal()const;
 * 	 Accessor; Performs and displays breadth first traversal
 * 	 Parameters: leaf (Node) // PROC - binary tree node
 * 	 Return: none
 *******************************************************************************/
void BinaryTree::breadthOrder(Node *leaf)const
{
	if(leaf != NULL)
	{
		// Declare variables
		queue<Node*> temp;  // PROC - temp variable for binary tree as queue

		// Adds the root node to the queue
		temp.push(root);

		// While the queue (tree) is not empty
		while(temp.empty() == false)
		{
			// Set node to node at front of queue
			Node *node = temp.front();

			// OUTPUT -- display value of node
			cout << node->value << " ";

			// PROC -- delete node from queue
			temp.pop();

			// If node has left child
			if(node->left != NULL)
			{
				// Add left child to queue
				temp.push(node->left);
			}
			// If node has right child
			if(node->right != NULL)
			{
				// Add right child to queue
				temp.push(node->right);
			}
		}
	}
}

/*******************************************************************************
 * displayRelationships()const;
 * 	 Accessor; Displays the parent-child relationships
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
void BinaryTree::displayRelationships()const
{
	if(root == NULL)
	{
		return;
	}

	// Declare variables
	queue<Node*>temp; // PROC - temp variable for binary tree as queue

	// Adds the root node to the queue
	temp.push(root);

	// If the queue/tree is not empty
	while(temp.empty() == false)
	{
		// Sets node count to sixe of queue/tree
		int nodeCount = temp.size();

		// While there are still nodes to display
		while(nodeCount > 0)
		{
			// Sets node to node at front of queue
			Node *node = temp.front();

			// OUTPUT -- displays the value of node
			cout << left << setw(5) << node->value << "";

			// OUTPUT -- outputs relationship

			// If node has no parent -> root
			if(node->parent == NULL)
			{
				cout << ": root" << endl;
			}
			// If node value is less than or equal to value of node's parent
			// -> left child
			else if(node->value <= node->parent->value)
			{
			cout << ": left child of " << node->parent->value << endl;
			}
			// If node value is greater than the value of node's parent -> right
			// child
			else
			{
				cout << ": right child of " << node->parent->value << endl;
			}

			// Delete node form queue
			temp.pop();

			// If node has left child
			if(node->left != NULL)
			{
				// Add left child to queue
				temp.push(node->left);
			}
			// If node has right child
			if(node->right != NULL)
			{
				// Add right child to queue
				temp.push(node->right);
			}

			// Decrement node count
			nodeCount--;
		}
	}
}

/*******************************************************************************
 * insert();
 * 	 Mutator; Adds integer to binary tree
 * 	 Parameters: insertItem (integer) // IN - integer being added to tree
 * 	 Return: none
 *******************************************************************************/
void BinaryTree::insert(const int& insertItem) // IN - integer being added to tree
{
	// Declare variables
	Node *current;      // Pointer to traverse the tree
	Node *trailCurrent; // Pointer behind current
	Node *newNode;      // Pointer to create the node

	// INPUT -- create new node
	newNode = new Node;
	newNode->value = insertItem;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;

	// If binary tree is empty
	if(root == NULL)
	{
		root = newNode;
	}
	else
	{
		current = root;

		// While current is not at the end of the tree/linked list
		while(current != NULL)
		{
			// Set trail current to current
			trailCurrent = current;

			// If the number being inserted is less than or equal to the current
			// node
			if(current->value >= insertItem)
			{
				// Set current to point to left child
				current = current->left;
			}
			// If the number being inserted is greater than the current node
			else
			{
				// Set current to point to left child
				current = current->right;
			}
		}

		// If the pointer behind current's value is greater than or equal to
		// the number being inserted
		if(trailCurrent->value >= insertItem)
		{
			// Set child of trail current to newNode
			trailCurrent->left = newNode;
			// Sets parent of left to trail current
			trailCurrent->left->parent = trailCurrent;
		}
		else
		{
			// Set child of trail current to newNode
			trailCurrent->right = newNode;
			// Sets parent of right to trail current
			trailCurrent->right->parent = trailCurrent;
		}
	}
}
