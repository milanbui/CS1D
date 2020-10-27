/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #3: Extendable Arrays
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 11 February 2019
 ******************************************************************************/
#ifndef VECTOR_H_
#define VECTOR_H_


#include <iostream>
using namespace std;

/*******************************************************************************
 * Stack Class
 * 	 This class represents a Stack object. It manages one attribute: *head
 *******************************************************************************/
class Vector
{
public:
	/******************************
	 ** CONSTRUCTOR & DESTRUCTOR **
	 ******************************/
	Vector();
	~Vector();

	/***************
	 ** MUTATORS **
	 ***************/
	void insert(int index, int num);
	void set(int index, int num);
	void erase(int index);

	/***************
	 ** ACCESSORS **
	 ***************/
	int at(int index)const;
	int size()const;
	bool empty()const;
	int getFront()const;
	int getRear()const;
	void display()const;

private:
	int front;    // Front of vector
	int rear;     // Back of vector
	int currSize; // Size of vector (how many elements in vector)
	int* arrSize; // Size of array/vector (max size)
	int* vector;  // Points to vector
};

/*******************************************************************************
 * Vector();
 * 	 Constructor; Initializes attributes
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * ~Vector();
 * 	 Destructor; Deallocates the memory
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * insert(int index, int num);
 * 	 Mutator; Adds a new element to the vector at index
 * 	 Parameters: index (int) // IN - index of where to put number
 * 	             num   (int) // IN - new number being added
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * set(int index, int num);
 * 	 Mutator; Sets number (replaces number) at given index
 * 	 Parameters: index (int) // IN - index of where to put number
 * 	             num   (int) // IN - new number being added
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * erase(int index);
 * 	 Mutator; erases number at given index
 * 	 Parameters: index (int) // IN - index of where to put number
 * 	 Return: none
 *******************************************************************************/

/*******************************************************************************
 * at(int index)const;
 * 	 Accessor; Returns number at the given index
 * 	 Parameters: index (int) // IN - index of where to put number
 * 	 Return: vector[index]
 *******************************************************************************/

/*******************************************************************************
 * size()const;
 * 	 Accessor; Returns number of elements in vector (the size)
 * 	 Parameters: none
 * 	 Return: currSize
 *******************************************************************************/

/*******************************************************************************
 * empty()const;
 * 	 Accessor; Returns whether or not vector is empty.
 * 	 Parameters: none
 * 	 Return: true/false
 *******************************************************************************/

/*******************************************************************************
 * getFront()const;
 * 	 Accessor; Returns index of front.
 * 	 Parameters: none
 * 	 Return: true/false
 *******************************************************************************/

/*******************************************************************************
 * getRear()const;
 * 	 Accessor; Returns index of rear.
 * 	 Parameters: none
 * 	 Return: true/false
 *******************************************************************************/

/*******************************************************************************
 * display()const;
 * 	 Accessor; Displays the elements in the vector and their index.
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/



#endif /* VECTOR_H_ */
