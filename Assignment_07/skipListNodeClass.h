/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #7: Dictionary - Skip List
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 25 March 2019
 ******************************************************************************/
#ifndef SKIPLISTNODECLASS_H_
#define SKIPLISTNODECLASS_H_

#include<iostream>
#include<cstring>
using namespace std;

/*******************************************************************************
 * SkipListNode Class
 * 	 This class represents a SkipListNode object. It manages four attributes:
 * 	 position, key, value, forwads.
 *******************************************************************************/
class SkipListNode
{
public:
	/*******************************
	 ** CONSTRUCTORS & DESTRUCTOR **
	 *******************************/
	SkipListNode(int _key, string _value, int level, int _pos);
	SkipListNode(int _key, int level, int _pos);
	~SkipListNode();

	int position;            // Position of entry
	int key;                 // Key of entry
	string value;            // Value of entry
	SkipListNode** forwards; // Array of pointers (holds nodes of diff levels)
};

/*******************************************************************************
 * SkipListNode(int _key, string _value, int level, int _pos);
 * 	 Constructor; Initializes variables
 * 	 Parameters: _key   (int)    // IN - Key of entry
 * 	             _value (string) // IN - Value of entry
 * 	             level  (int)    // IN - Level of entry
 * 	             _pos   (int)    // IN - Position of entry
 * 	 Return: none
 *******************************************************************************/
SkipListNode::SkipListNode(int _key,      // IN - Key of entry
		                   string _value, // IN - Value of entry
						   int level,     // IN - Level of entry
						   int _pos)      // IN - Position of entry
{

	key = _key;
	value = _value;
	position = _pos;

	// Allocates memory to forwards
	forwards = new SkipListNode*[level+1];

	// Initializes forwards array with 0 (NULL)
	memset(forwards, 0, sizeof(SkipListNode*)*(level+1));
}

/*******************************************************************************
 * SkipListNode(int _key, int level, int _pos);
 * 	 Constructor; Initializes variables
 * 	 Parameters: _key   (int)    // IN - Key of entry
 * 	             level  (int)    // IN - Level of entry
 * 	             _pos   (int)    // IN - Position of entry
 * 	 Return: none
 *******************************************************************************/
SkipListNode::SkipListNode(int _key,      // IN - Key of entry
		                   int level,     // IN - Level of entry
		                   int _pos)      // IN - Position of entry
{
	key = _key;
	position = _pos;

	// Allocates memory to forwards
	forwards = new SkipListNode*[level+1];

	// Initializes forwards array with 0 (NULL)
	memset(forwards, 0, sizeof(SkipListNode*)*(level+1));
}

/*******************************************************************************
 * ~SkipListNode();
 * 	 Destructor; Deallocates memory
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
SkipListNode::~SkipListNode()
{
	delete []forwards;
}



#endif /* SKIPLISTNODECLASS_H_ */
