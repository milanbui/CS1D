/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #3: Extendable Arrays
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 11 February 2019
 ******************************************************************************/
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
Vector::Vector()
{
	front = 0;
	rear = 0;
	currSize = 0;
	arrSize = new int;
	*arrSize = 4;
	vector = new int[*arrSize];
}

/*******************************************************************************
 * ~Vector();
 * 	 Destructor; Deallocates the memory
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
Vector::~Vector()
{
	delete []vector;
	vector = NULL;

	delete arrSize;
	arrSize = NULL;
}

/*******************************************************************************
 * insert(int index, int num);
 * 	 Mutator; Adds a new element to the vector at index
 * 	 Parameters: index (int) // IN - index of where to put number
 * 	             num   (int) // IN - new number being added
 * 	 Return: none
 *******************************************************************************/
void Vector::insert(int index,// IN - index of where to put number
					int num)  // IN - new number being added
{
	// Declare variables
	int j;        // CALC - loop control variable
	int frontTemp;// CALC - temporary variable for front and vector index
	int* temp;    // CALC - temporary variable for vector

	// Initialize variables
	temp = NULL;

	// If vector is full
	if(currSize == *arrSize)
	{
		// Doubles size
		*arrSize = (*arrSize * 2);

		// Creates new vector
		temp = new int[*arrSize];

		// Sets front temp
		frontTemp = front;

		// Copies smaller vector to a bigger vector
		for(j = 0; j < *arrSize; j++)
		{
			temp[j] = vector[frontTemp++];

			if(frontTemp == (*arrSize/2))
			{
				frontTemp = 0;
			}

		}

		// Deallocates memory
		delete []vector;

		// Sets pointer to point to bigger vectors
		vector = temp;

		temp = NULL;
	}

	// If list is empty
	if(currSize == 0)
	{
		front = 0;
		rear = 0;

		vector[0] = num;
	}
	// If want to add to rear
	else if(index == (rear + 1))
	{
		// If rear is at last position
		if(rear == *arrSize-1)
		{
			rear = 0;
		}
		else
		{
			rear++;
		}

		vector[rear] = num;
	}
	// If want to add to front
	else if(index == (front - 1))
	{
		// If front is in very first position
		if(front == 0)
		{
			front = *arrSize - 1;
		}
		else
		{
			front--;
		}

		vector[front] = num;
	}
	else
	{
		// Moves data to make room to add data to middle at index
		for(j = currSize - 1; j >= index; j--)
		{
			if(j == *arrSize - 1)
			{
				vector[0] = vector[j];
			}
			else
			{
				vector[j+1] = vector[j];
			}
		}

		// If rear is in last position
		if(rear == *arrSize-1)
		{
			rear = 0;
		}
		else
		{
			rear++;
		}

		vector[index] = num;

	}

	// Increases number of elements in vector
	currSize++;

}

/*******************************************************************************
 * set(int index, int num);
 * 	 Mutator; Sets number (replaces number) at given index
 * 	 Parameters: index (int) // IN - index of where to put number
 * 	             num   (int) // IN - new number being added
 * 	 Return: none
 *******************************************************************************/
void Vector::set(int index,// IN - index of where to put number
				 int num)  // IN - new number being added
{
	vector[index] = num;
}

/*******************************************************************************
 * erase(int index);
 * 	 Mutator; erases number at given index
 * 	 Parameters: index (int) // IN - index of where to put number
 * 	 Return: none
 *******************************************************************************/
void Vector::erase(int index) // IN - index of where to put number
{
	// If list only has one element
	if(currSize == 1)
	{
		front = 0;
		rear = 0;
	}
	// If want to erase element at front
	else if(index == front)
	{
		// If front is in last position
		if(front == (*arrSize - 1))
		{
			front = 0;
		}
		else
		{
			front++;
		}


	}
	// If want to erase at rear
	else if(index == rear)
	{
		// If rear is in first position
		if(rear == 0)
		{
			rear = *arrSize - 1;
		}
		else
		{
			rear--;
		}
	}
	else
	{
		// Move data to delete data in middle at index
		for(int j = index; j < currSize; j++)
		{
			if(j == *arrSize - 1)
			{
				vector[j] = vector[0];
			}
			else
			{
				vector[j] = vector[j+1];
			}

		}

		// If rear is in first positions
		if(rear == 0)
		{
			rear = *arrSize - 1;
		}
		else
		{
			rear--;
		}
	}

	// Decrease number of elements in vector
	currSize--;

}

/*******************************************************************************
 * at(int index)const;
 * 	 Accessor; Returns number at the given index
 * 	 Parameters: index (int) // IN - index of where to put number
 * 	 Return: vector[index]
 *******************************************************************************/
int Vector::at(int index)const // IN - index of where to put number
{
	return(vector[index]);
}

/*******************************************************************************
 * size()const;
 * 	 Accessor; Returns number of elements in vector (the size)
 * 	 Parameters: none
 * 	 Return: currSize
 *******************************************************************************/
int Vector::size()const
{
	return currSize;
}

/*******************************************************************************
 * empty()const;
 * 	 Accessor; Returns whether or not vector is empty.
 * 	 Parameters: none
 * 	 Return: true/false
 *******************************************************************************/
bool Vector::empty()const
{
	if(currSize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*******************************************************************************
 * getFront()const;
 * 	 Accessor; Returns index of front.
 * 	 Parameters: none
 * 	 Return: true/false
 *******************************************************************************/
int Vector::getFront()const
{
	return front;
}

/*******************************************************************************
 * getRear()const;
 * 	 Accessor; Returns index of rear.
 * 	 Parameters: none
 * 	 Return: true/false
 *******************************************************************************/
int Vector::getRear()const
{
	return rear;
}

/*******************************************************************************
 * display()const;
 * 	 Accessor; Displays the elements in the vector and their index.
 * 	 Parameters: none
 * 	 Return: none
 *******************************************************************************/
void Vector::display()const
{
	// Declare variables
	int index;          // PROC/OUT - index in vector

	// Initialize index
	index = front;

	for(int i = 0; i < currSize; i++)
	{
		if(index == *arrSize)
		{
			index = 0;
		}

		cout << index << " - " << vector[index] << endl;

		index++;

	}
}
