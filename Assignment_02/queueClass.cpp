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

template<class Type>
struct QueueNode
{
	Type info;             // Information (any type of input)
	QueueNode<Type> *next; // Pointer pointing to next element
};

/*******************************************************************************
 * Queue Class
 * 	 This class represents a Queue object. It manages two attributes: *head and
 * 	 *tail
 *******************************************************************************/
template<class Type>
class Queue
{
public:
	/******************************
	 ** CONSTRUCTOR & DESTRUCTOR **
	 ******************************/
	Queue();
	~Queue();

	/***************
	 ** MUTATORS **
	 ***************/
	void addQueue(Type newItem);
	void deQueue();

	/***************
	 ** ACCESSORS **
	 ***************/
	bool isEmpty()const;
	Type peek()const;
	void displayQueue()const;
private:
	QueueNode<Type> *head; // Pointer pointing to front of the Queue
	QueueNode<Type> *tail; // Pointer pointing to back of the Queue
};

/*******************************************************************************
 * Queue();
 * 	 Constructor; Initializes attributes
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
template<class Type>
Queue<Type>::Queue()
{
	head = NULL;
	tail = NULL;
}

/*******************************************************************************
 * ~Queue();
 * 	 Destructor; Deallocates the memory (destroys Queue)
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
template<class Type>
Queue<Type>::~Queue()
{
	QueueNode<Type> *temp;

	while(head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}

	tail = NULL;
}

/*******************************************************************************
 * addQueue(Type newItem);
 * 	 Mutator; Adds a new element to the back of the queue
 * 	 Parameters: newItem (Type) // IN - new item being added
 * 	 Return: none
 *******************************************************************************/
template<class Type>
void Queue<Type>::addQueue(Type newItem)
{
	// Declare variable
	QueueNode<Type> *newNode; // PROC - temporary pointer pointing to new item

	// Initialize variable
	newNode = new QueueNode<Type>;

	// INPUT -- inputting new item
	newNode->info = newItem;

	// PROC -- putting element in back
	newNode->next = NULL;

	// If queue empty
	if(head == NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = tail->next;
	}

	newNode = NULL;
}

/*******************************************************************************
 * removeFront();
 * 	 Mutator; Removes element from front of queue
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
template<class Type>
void Queue<Type>::deQueue()
{
	// Declare variables
	QueueNode<Type> *temp; // PROC - temp pointer pointing to head

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
}

/*******************************************************************************
 * isEmpty();
 * 	 Accessor; Checks if queue is empty
 * 	 Parameters: none
 * 	 Return: true (if empty) or false (if not empty)
 *******************************************************************************/
template<class Type>
bool Queue<Type>::isEmpty()const
{
	return(head == NULL);
}

/*******************************************************************************
 * peek();
 * 	 Accessor; Returns element at front of queue
 * 	 Parameters: none
 * 	 Return: head->info (item at top of queue)
 *******************************************************************************/
template<class Type>
Type Queue<Type>::peek()const
{
	return(head->info);
}

/*******************************************************************************
 * displayQueue();
 * 	 Accessor; Displays entire queue
 * 	 Parameters: none
 * 	 Return: none
 * 	         -> displays elements of queue
 *******************************************************************************/
template<class Type>
void Queue<Type>::displayQueue()const
{
	// Declare variables
	QueueNode<Type> *temp; // PROC/OUT - temp pointer pointing to head of deque

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
