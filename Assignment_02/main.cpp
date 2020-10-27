/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #2: Stacks, Queues, and Deques
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 4 February 2019
 * SCORE        : 10/10
 ******************************************************************************/
#include <stack>
#include <string>
#include "stackClass.h"
#include "queueClass.h"
#include "dequeClass.h"
#include "function.h"
#include "printHeader.h"

/*******************************************************************************
 * MANIPULATING STACKS, QUEUES, AND DEQUES AND CHECKING PARENTHESES
 * _____________________________________________________________________________
 *
 * This program will create stacks, queues, and deques of names and of doubles.
 * It will create stacks using both the STL <stack> and using a linked list.
 * It will create queues and deques using linked lists as well. It will then
 * display the stacks, queues, and deques before manipulating them. The name
 * Eric will be deleted from the stacks, queues, and deques(from the front) and
 * the number 8.445 will be removed as well (from the back in the deques). It
 * will then display the stacks, queues, and deques after doing so. Finally,
 * the program well check several mathematical statements to see if their
 * parentheses match.
 * _____________________________________________________________________________
 * INPUT:
 *	    stringStack1 - stack of strings using <stack> STL
 *	    doubleStack1 - stack of doubles using <stack> STL
 *	    stringStack2 - stack of strings using linked list
 *	    doubleStack2 - stack of doubles using linked list
 *	    stringQueue  - queue of strings using linked list
 *	    doubleQueue  - queue of doubles using linked list
 *	    stringDeque  - deque of strings using linked list
 *	    doubleDeque  - deque of doubles using linked list
 *	    statement    - mathematical statement being checked
 *
 * OUTPUT:
 *	    stringStack1 - stack of strings using <stack> STL
 *	    tempStack1   - temp stack of strings to be output
 *	    doubleStack1 - stack of doubles using <stack> STL
 *	    tempStack2   - temp stack of numbers to be output
 *	    stringStack2 - stack of strings using linked list
 *	    doubleStack2 - stack of doubles using linked list
 *	    stringQueue  - queue of strings using linked list
 *	    doubleQueue  - queue of doubles using linked list
 *	    stringDeque  - deque of strings using linked list
 *	    doubleDeque  - deque of doubles using linked list
 *	    statement    - mathematical statement being checked
 *
 ******************************************************************************/

int main()
{
	// Declaring variables
	stack<string> stringStack1; // IN/OUT - stack of strings using <stack> STL
	stack<string> tempStack1;   // OUT    - temp stack of strings to be output
	stack<double> doubleStack1; // IN/OUT - stack of doubles using <stack> STL
	stack<double> tempStack2;   // OUT    - temp stack of doubles to be output

	Stack<string> stringStack2; // IN/OUT - stack of strings using linked list
	Stack<double> doubleStack2; // IN/OUT - stack of doubles using linked list

	Queue<string> stringQueue;  // IN/OUT - queue of strings using linked list
	Queue<double> doubleQueue;  // IN/OUT - queue of doubles using linked list

	Deque<string> stringDeque;  // IN/OUT - deque of strings using linked list
	Deque<double> doubleDeque;  // IN/OUT - deque of doubles using linked list

	bool matching;              // PROC   - whether or not the parentheses match
	string statement;           // IN/OUT - mathematical statement being checked

	// OUTPUT -- outputs header and description of program
	cout << printHeader("Stacks, Queues, and Deques", 2);
	cout << "This program will:" << endl;
	cout << "1. Create a stack of strings and a stack of doubles using the STL <stack>"
			"\n   and output the stacks" << endl;
	cout << "2. Remove Eric and 8.445 from their respective stacks and display the "
			"\n   stack after the change" << endl;
	cout << "3. Do the same but with a stack using a linked list, a queue using a linked"
			"\n   list, and a deque using a doubly linked list.(It will remove Eric from"
			"\n   the front and 8.445 from the back of the deques)" << endl;
	cout << "4. Check to see if the parentheses of several mathematical statements match"
		 << endl << endl;


	// PART A -------------------------------------------------------------------------

	cout << "PART A" << endl;
	cout << "-------" << endl;

	// IN -- adds a name to the stack
	stringStack1.push("Jennifer");
	stringStack1.push("JoAnn");
	stringStack1.push("Eric");
	stringStack1.push("Bill");
	stringStack1.push("Mark");
	stringStack1.push("Alan");
	stringStack1.push("Don");

	tempStack1 = stringStack1;


	// OUTPUT -- outputs entire stack
	while(!tempStack1.empty())
	{
		cout << tempStack1.top() << endl;
		tempStack1.pop();
	}


	cout << endl;


	// IN -- adds a number to the stack
	doubleStack1.push(44.44);
	doubleStack1.push(888.77);
	doubleStack1.push(88.88);
	doubleStack1.push(456.123);
	doubleStack1.push(8.445);
	doubleStack1.push(983.88);

	tempStack2 = doubleStack1;


	// OUTPUT -- outputs entire stack
	while(!tempStack2.empty())
	{
		cout << tempStack2.top() << endl;
		tempStack2.pop();
	}

	cout << endl;


	// PART B -------------------------------------------------------------------------

	cout << "PART B" << endl;
	cout << "-------" << endl;

	// PROC -- deletes from top of list until it gets to Eric and deletes Eric as well
	while(stringStack1.top()!= "Eric")
	{
		stringStack1.pop();
	}
	stringStack1.pop();

	// OUTPUT -- outputs entire stack
	while(!stringStack1.empty())
	{
		cout << stringStack1.top() << endl;
		stringStack1.pop();
	}

	cout << endl;

	// PROC -- deletes from top of list until it gets to 8.445 and deletes 8.445 as well
	while(doubleStack1.top()!= 8.445)
	{
		doubleStack1.pop();
	}
	doubleStack1.pop();

	// OUTPUT -- outputs entire stack
	while(!doubleStack1.empty())
	{
		cout << doubleStack1.top() << endl;
		doubleStack1.pop();
	}

	cout << endl;


	// PART C -------------------------------------------------------------------------

	cout << "PART C" << endl;
	cout << "-------" << endl;

	// INPUT -- adds these names to the stack
	stringStack2.push("Jennifer");
	stringStack2.push("JoAnn");
	stringStack2.push("Eric");
	stringStack2.push("Bill");
	stringStack2.push("Mark");
	stringStack2.push("Alan");
	stringStack2.push("Don");

	// OUTPUT -- outputs the stack
	stringStack2.displayStack();

	cout << endl;

	// INPUT -- adds these numbers to the stack
	doubleStack2.push(44.44);
	doubleStack2.push(888.77);
	doubleStack2.push(88.88);
	doubleStack2.push(456.123);
	doubleStack2.push(8.445);
	doubleStack2.push(983.88);

	// OUTPUT -- displays stack
	doubleStack2.displayStack();

	cout << endl;


	// PART D -------------------------------------------------------------------------

	cout << "PART D" << endl;
	cout << "-------" << endl;

	// PROC -- deletes from top of stack until it get to Eric and deletes Eric
	while(stringStack2.peek() != "Eric")
	{
		stringStack2.pop();
	}
	stringStack2.pop();

	// OUTPUT -- outputs stack
	while(!stringStack2.isEmpty())
	{
		cout << stringStack2.peek() << endl;
		stringStack2.pop();
	}

	cout << endl;

	// PROC -- deletes from top of stack until it get to 8.445 and deletes 8.445
	while(doubleStack2.peek() != 8.445)
	{
		doubleStack2.pop();
	}
	doubleStack2.pop();

	// OUTPUT -- outputs stack
	while(!doubleStack2.isEmpty())
	{
		cout << doubleStack2.peek() << endl;
		doubleStack2.pop();
	}

	cout << endl;


	// PART E -------------------------------------------------------------------------

	cout << "PART E" << endl;
	cout << "-------" << endl;

	// INPUT -- adds names to queue
	stringQueue.addQueue("Jennifer");
	stringQueue.addQueue("JoAnn");
	stringQueue.addQueue("Eric");
	stringQueue.addQueue("Bill");
	stringQueue.addQueue("Mark");
	stringQueue.addQueue("Alan");
	stringQueue.addQueue("Don");

	// OUTPUT -- outputs queue
	stringQueue.displayQueue();

	cout << endl;

	// INPUT -- adds numbers to queue
	doubleQueue.addQueue(44.44);
	doubleQueue.addQueue(888.77);
	doubleQueue.addQueue(88.88);
	doubleQueue.addQueue(456.123);
	doubleQueue.addQueue(8.445);
	doubleQueue.addQueue(983.88);

	// OUTPUT -- displays queue
	doubleQueue.displayQueue();

	cout << endl;


	// PART F -------------------------------------------------------------------------

	cout << "PART F" << endl;
	cout << "-------" << endl;

	// PROC -- deletes from top of queue until it get to Eric and deletes Eric
	while(stringQueue.peek() != "Eric")
	{
		stringQueue.deQueue();
	}
	stringQueue.deQueue();

	// OUTPUT -- outputs entire queue
	while(!stringQueue.isEmpty())
	{
		cout << stringQueue.peek() << endl;
		stringQueue.deQueue();
	}

	cout << endl;

	// PROC -- deletes from top of queue until it get to 8.445 and deletes 8.445
	while(doubleQueue.peek() != 8.445)
	{
		doubleQueue.deQueue();
	}
	doubleQueue.deQueue();


	// OUTPUT -- outputs entire queue
	while(!doubleQueue.isEmpty())
	{
		cout << doubleQueue.peek() << endl;
		doubleQueue.deQueue();
	}

	cout << endl;


	// PART G -------------------------------------------------------------------------

	cout << "PART G" << endl;
	cout << "-------" << endl;

	// INPUT -- adds names to deque by adding to front
	stringDeque.insertFront("Jennifer");
	stringDeque.insertFront("JoAnn");
	stringDeque.insertFront("Eric");
	stringDeque.insertFront("Bill");
	stringDeque.insertFront("Mark");
	stringDeque.insertFront("Alan");
	stringDeque.insertFront("Don");

	// OUTPUT -- outputs entire deque
	stringDeque.displayDeque();

	cout << endl;

	// INPUT -- adds numbers to deque by adding to front
	doubleDeque.insertFront(44.44);
	doubleDeque.insertFront(888.77);
	doubleDeque.insertFront(88.88);
	doubleDeque.insertFront(456.123);
	doubleDeque.insertFront(8.445);
	doubleDeque.insertFront(983.88);

	// OUTPUT -- outputs entire deque
	doubleDeque.displayDeque();

	cout << endl;


	// PART H -------------------------------------------------------------------------

	cout << "PART H" << endl;
	cout << "-------" << endl;

	// PROC -- deletes from top of queue until it get to Eric and deletes Eric
	while(stringDeque.viewFront() != "Eric")
	{
		stringDeque.removeFront();
	}
	stringDeque.removeFront();

	// OUTPUT -- outputs entire deque
	while(!stringDeque.isEmpty())
	{
		cout << stringDeque.viewFront() << endl;
		stringDeque.removeFront();
	}

	cout << endl;

	// PROC -- deletes from top of queue until it get to 8.445 and deletes 8.445
	while(doubleDeque.viewBack() != 8.445)
	{
		doubleDeque.removeBack();
	}
	doubleDeque.removeBack();

	// OUTPUT -- outputs entire deque
	while(!doubleDeque.isEmpty())
	{
		cout << doubleDeque.viewFront() << endl;
		doubleDeque.removeFront();
	}

	cout << endl;


	// PART I -------------------------------------------------------------------------

	cout << "PART I" << endl;
	cout << "-------" << endl;

	for(int i = 0; i < 7; i++)
	{
		// INPUT -- prompts for input of statement from user
		cout << "Statement: ";
		getline(cin,statement);

		// PROC -- checks to see if the parentheses match
		matching = parenMatch(statement);

		// OUTPUT -- outputs results
		if(matching)
		{
			cout << "All of the grouping symbols in " << statement << " match." << endl;
		}
		else
		{
			cout << "The grouping symbols in " << statement << " do not match." << endl;
		}

		cout << endl;
	}

	return 0;
}


