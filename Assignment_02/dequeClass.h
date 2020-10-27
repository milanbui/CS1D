/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #2: Stacks, Queues, and Deques
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 4 February 2019
 ******************************************************************************/
#ifndef DEQUECLASS_H_
#define DEQUECLASS_H_

// PREPROCESSING DIRECSTIVES
#include <iostream>
using namespace std;

//GLOABAL CONSTANTS

//TYPE DEFINITIONS AND ENUMERATED TYPES
template<class Type>
struct DequeNode
{
	Type info;             // Information (any type of input)
	DequeNode<Type> *next; // Pointer pointing to next element
	DequeNode<Type> *prev; // Pointer pointing to previous element
};

/*******************************************************************************
 * Deque Class
 * 	 This class represents a Deque object. It manages two attributes: *head and
 * 	 *tail
 *******************************************************************************/
template<class Type>
class Deque
{
public:
	/******************************
	 ** CONSTRUCTOR & DESTRUCTOR **
	 ******************************/
	Deque();
	~Deque();

	/***************
	 ** MUTATORS **
	 ***************/
	void insertFront(Type newItem);
	void insertBack(Type newItem);
	void removeFront();
	void removeBack();

	/***************
	 ** ACCESSORS **
	 ***************/
	bool isEmpty()const;
	Type viewFront()const;
	Type viewBack()const;
	void displayDeque()const;
private:
	DequeNode<Type> *head; // Pointer pointing to front of the deque
	DequeNode<Type> *tail; // Pointer pointing to back of the deque
};

/*******************************************************************************
 * Deque();
 * 	 Constructor; Initializes attributes
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
template<class Type>
Deque<Type>::Deque()
{
	head = NULL;
	tail = NULL;
}

/*******************************************************************************
 * ~Deque();
 * 	 Destructor; Deallocates the memory (destroys deque)
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
template<class Type>
Deque<Type>::~Deque()
{
	DequeNode<Type> *temp;

	while(head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}

	tail = NULL;
}

/*******************************************************************************
 * insertFront(Type newItem);
 * 	 Mutator; Adds a new element to the front of the deque
 * 	 Parameters: newItem (Type) // IN - new item being added
 * 	 Return: none
 *******************************************************************************/
template<class Type>
void Deque<Type>::insertFront(Type newItem)
{
	// Declare variable
	DequeNode<Type> *temp; // PROC - temporary pointer pointing to new item

	// Initialize variable
	temp = NULL;
	temp = new DequeNode<Type>;

	// INPUT -- inputting new item
	temp->info = newItem;

	// PROC -- putting element in front
	temp->next = head;
	temp->prev = NULL;

	// If list is empty
	if(head == NULL)
	{
		tail = temp;
	}
	// If list isn't empty
	else
	{
		head->prev = temp;
	}

	head = temp;

	temp = NULL;
}

/*******************************************************************************
 * insertBack(Type newItem);
 * 	 Mutator; Adds element to the back of the deque
 * 	 Parameters: newItem (Type) // PROC - new element being added
 * 	 Return: none
 *******************************************************************************/
template<class Type>
void Deque<Type>::insertBack(Type newItem)
{
	// Declare Variables
	DequeNode<Type> *temp; // PROC - temp pointer pointing to new item

	// Initialize Variables
	temp = new DequeNode<Type>;
	temp->info = newItem;

	// Add item to back
	temp->next = NULL;

	// If deque is empty
	if(head == NULL)
	{
		head = temp;
		tail = temp;
		temp->prev = NULL;
	}
	// If deque isn't empty
	else
	{
		temp->prev = tail;
		tail->next = temp;
		tail = tail->next;
	}

	temp = NULL;
}

/*******************************************************************************
 * removeFront();
 * 	 Mutator; Removes element from front of deque
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
template<class Type>
void Deque<Type>::removeFront()
{
	// Declare variables
	DequeNode<Type> *temp; // PROC - temp pointer pointing to head

	// Point temp to head of list
	temp = head;

	// Points head to next element
	head = head->next;

	// Deallocates memory
	delete temp;

	// If list is empty
	if(head == NULL)
	{
		tail = NULL;
	}
	else
	{
		head->prev = NULL;
	}
}

/*******************************************************************************
 * removeBack();
 * 	 Mutator; Remove element from back
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
template<class Type>
void Deque<Type>::removeBack()
{
	// Declare variable
	DequeNode<Type> *temp; /// PROC - temp pointer pointing to tail

	// point temp to tail of deque
	temp = tail;

	// Point tail to next item
	tail = tail->prev;

	// Deallocate memory
	delete temp;

	// If list is empty
	if(temp == NULL)
	{
		head = NULL;
	}
	else
	{
		tail->next = NULL;
	}
}

/*******************************************************************************
 * isEmpty();
 * 	 Accessor; Checks if deque is empty
 * 	 Parameters: none
 * 	 Return: true (if empty) or false (if not empty)
 *******************************************************************************/
template<class Type>
bool Deque<Type>::isEmpty()const
{
	return(head == NULL);
}

/*******************************************************************************
 * viewFront();
 * 	 Accessor; Returns element at front of deque
 * 	 Parameters: none
 * 	 Return: head->info (item at top of deque)
 *******************************************************************************/
template<class Type>
Type Deque<Type>::viewFront()const
{
	return(head->info);
}

/*******************************************************************************
 * viewBack();
 * 	 Accessor; Returns element at back of deque
 * 	 Parameters: none
 * 	 Return: tail->info (item at back of deque)
 *******************************************************************************/
template<class Type>
Type Deque<Type>::viewBack()const
{
	return(tail->info);
}

/*******************************************************************************
 * displayDeque();
 * 	 Accessor; Displays entire deque
 * 	 Parameters: none
 * 	 Return: none
 * 	         -> displays elements of deque
 *******************************************************************************/
template<class Type>
void Deque<Type>::displayDeque()const
{
	// Declare variables
	DequeNode<Type> *temp; // PROC/OUT - temp pointer pointing to head of deque

	// Initialize variable
	temp = head;

	// While deque isn't empty
	while(temp != NULL)
	{
		// OUTPUT -- outputs element
		cout << temp->info << endl;

		// Points temp to next element
		temp = temp->next;
	}

	// De allocates temp
	delete temp;
	temp = NULL;
}

// PROTOTYPES

#endif /* DEQUECLASS_H_ */
