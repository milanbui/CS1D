/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #2: Stacks, Queues, and Deques
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 4 February 2019
 ******************************************************************************/
#include <iostream>
using namespace std;

template <class Type>
struct Node
{
	Type info;             // Information (any type of input)
	Node<Type> *next; // Pointer pointing to next element
};

/*******************************************************************************
 * Stack Class
 * 	 This class represents a Stack object. It manages one attribute: *head
 *******************************************************************************/
template <class Type>
class Stack
{
public:
	/******************************
	 ** CONSTRUCTOR & DESTRUCTOR **
	 ******************************/
	Stack();
	~Stack();

	/***************
	 ** MUTATORS **
	 ***************/
	void push(Type newItem);
	void pop();

	/***************
	 ** ACCESSORS **
	 ***************/
	bool isEmpty()const;
	Type peek()const;
	void displayStack()const;


private:
	Node<Type> *head; // Pointer pointing to top of the Stack
};

/*******************************************************************************
 * Stack();
 * 	 Constructor; Initializes attributes
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
template <class Type>
Stack<Type>::Stack()
{
	head = NULL;
}

/*******************************************************************************
 * ~Stack();
 * 	 Destructor; Deallocates the memory (destroys Stack)
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
template <class Type>
Stack<Type>::~Stack()
{
	Node<Type> *temp;

	temp = head;

	while(temp != NULL)
	{
		head = head->next;
		delete temp;

		temp = head;
	}

}

/*******************************************************************************
 * push(Type newItem);
 * 	 Mutator; Adds a new element to the front of Stack
 * 	 Parameters: newItem (Type) // IN - new item being added
 * 	 Return: none
 *******************************************************************************/
template <class Type>
void Stack<Type>::push(Type newItem)
{
	// Declare variables
	Node<Type> *temp; // PROC - temporary pointer pointing to new item

	// Initialize variable
	temp = NULL;
	temp = new Node<Type>;

	// INPUT -- inputting new item
	temp->info = newItem;

	// PROC -- putting element in front
	temp->next = head;
	head = temp;

	temp = NULL;
}

/*******************************************************************************
 * pop();
 * 	 Mutator; Removes element from top of stack
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
template <class Type>
void Stack<Type>::pop()
{
	// Declare variables
	Node<Type> *temp; // PROC - temp pointer pointing to head

	// Initialize variable
	temp = NULL;

	// points temp to head
	temp = head;

	// Points head to next elements
	head = head->next;

	// De allocates memory
	delete temp;
	temp = NULL;
}

/*******************************************************************************
 * isEmpty();
 * 	 Accessor; Checks if stack is empty
 * 	 Parameters: none
 * 	 Return: true (if empty) or false (if not empty)
 *******************************************************************************/
template <class Type>
bool Stack<Type>::isEmpty()const
{
	return(head == NULL);
}

/*******************************************************************************
 * peek();
 * 	 Accessor; Returns element at top of Stack
 * 	 Parameters: none
 * 	 Return: head->info (item at top of queue)
 *******************************************************************************/
template <class Type>
Type Stack<Type>::peek()const
{
	return(head->info);
}

/*******************************************************************************
 * displayStack();
 * 	 Accessor; Displays entire Stack
 * 	 Parameters: none
 * 	 Return: none
 * 	         -> displays elements of Stack
 *******************************************************************************/
template <class Type>
void Stack<Type>::displayStack()const
{
	// Declare variables
	Node<Type> *temp; // PROC/OUT - temp pointer pointing to head of Stack

	// Point temp to head
	temp = head;

	// While list not empty
	while(temp != NULL)
	{
		// OUTPUT -- output element
		cout << temp->info << endl;

		// point temp to next element
		temp = temp->next;
	}

	// De allocate memory
	delete temp;
	temp = NULL;
}
