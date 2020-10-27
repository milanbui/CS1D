/*******************************************************************************
 * AUTHOR		: Milan Bui
 * #
 * ASSIGNMENT #3: Extendable Arrays
 * CLASS		: CS 1D
 * SECTION		: MW: 2:30p - 4:50p
 * DUE DATE		: 11 February 2019
 * SCORE        : 10/10
 ******************************************************************************/
#include "vector.h"
#include "printHeader.h"

/*******************************************************************************
 * INTEGER VECTOR USING EXTENDABLE, CIRCULAR ARRAYS
 * _____________________________________________________________________________
 *
 * This program will create a vector using an extendable array that works in a
 * circular manner without using the <vector> STL. It will test all the methods:
 * at(), insert(), set(), erase(), size(), and empty(). It will add eight
 * numbers (14, 5, 4, 1, 22, 33, 44, 88), delete 14, delete 1, insert 9 in the
 * front, insert 7 after 33, insert 44 at the end, and set the end to 88. It
 * will also find whether or not the vector is empty, how many integers are in
 * the vector, and find the front and the rear. It will output the vector after
 * every change with the index and the value, the size, the front and rear, and
 * whether or not it is empty.
 * _____________________________________________________________________________
 * INPUT:
 *	    intVect - object of the vector with the integers
 *
 * OUTPUT:
 *	    intVect - object of the vector with the integers
 *
 ******************************************************************************/
int main()
{
	// Declaring variables
	int i;         // CALC        - loop control variable
	int index;     // CALC        - loop control variable and found index
	Vector intVect;// IN/PROC/OUT - object of the vector with the integers

	// OUTPUT -- outputs the class header and the program description
	cout << printHeader("Extendable Arrays", 3);
	cout << "This program will:" << endl;
	cout << "1. Create a vector using an expandable array that works in a "
			"\n   circular manner" << endl;
	cout << "2. Test all the methods: at(), insert(), set(), erase(), size(),  "
			"\n   and empty()" << endl;
	cout << "3. Add eight numbers, delete 14, delete 1, insert 9 at the front,"
			"\n   insert 7 after 33, insert 44 at the end, set the end to 88,"
			"\n   and obtain the front and rear" << endl;
	cout << "4. Display the vector after every change with the index and the "
			"\n   value, display the front and the rear, whether or not it is"
			"\n   is empty, and how many integers are in the vector"
		 << endl << endl;

	// PROC/OUT -- outputs whether or not vector is empty
	cout << (intVect.empty()?"INTEGER VECTOR IS EMPTY":
			"INTEGER VECTOR IS NOT EMPTY") << endl;
	cout << endl;

	// INPUT -- inputs the numbers into the vector
	cout << "INSERTING NUMBERS" << endl;
	intVect.insert(intVect.getRear(), 14);

	intVect.insert(intVect.getRear()+1, 5);

	intVect.insert(intVect.getRear()+1, 4);

	intVect.insert(intVect.getRear()+1, 1);

	intVect.insert(intVect.getRear()+1, 22);

	intVect.insert((intVect.getRear()+1), 33);

	intVect.insert(intVect.getRear()+1, 44);

	intVect.insert(intVect.getRear()+1, 88);

	// OUTPUT -- outputs the vector
	intVect.display();
	cout << endl << endl;


	cout << "DELETING 14" << endl;

	// PROC -- finds index of number want to delete
	for(i = 0; i < intVect.size(); i++)
	{
		if(intVect.at(i) == 14)
		{
			index = i;
		}
	}

	// PROC -- deletes number
	intVect.erase(index);

	// OUTPUT -- outputs the vector
	intVect.display();
	cout << endl << endl;

	cout << "DELETING 1" << endl;

	// PROC -- finds index of number want to delete
	for(i = 0; i < intVect.size(); i++)
	{
		if(intVect.at(i) == 1)
		{
			index = i;
		}
	}

	// PROC -- deletes number
	intVect.erase(index);

	// OUTPUT -- outputs the vector
	intVect.display();
	cout << endl << endl;


	cout << "INSERTING 9 IN FRONT" << endl;

	// INPUT -- inputs 9 in front
	intVect.insert((intVect.getFront()- 1), 9);

	// OUTPUT -- outputs the vector
	intVect.display();
	cout << endl << endl;


	cout << "INSERTING 7 AFTER 33" << endl;

	// PROC -- finds index of where to place number
	for(i = 0; i < intVect.size(); i++)
	{
		if(intVect.at(i) == 33)
		{
			index = i;
		}
	}

	// INPUT -- inputs 7 at that index
	intVect.insert((index+1), 7);

	// OUTPUT -- outputs the vector
	intVect.display();
	cout << endl << endl;


	cout << "INSERTING 44 IN REAR" << endl;

	// INPUT -- input 44 in the rear
	intVect.insert((intVect.getRear() + 1), 44);

	// OUTPUT -- outputs the vector
	intVect.display();
	cout << endl << endl;


	cout << "SETTING 88 IN REAR" << endl;

	// INPUT -- setting 88 in rear (replacing number in rear w/ 88)
	intVect.set(intVect.getRear(), 88);

	// OUTPUT -- outputs the vector
	intVect.display();
	cout << endl << endl;

	// OUTPUT -- output the front and rear index and values
	cout << "FRONT: " << intVect.getFront() << " - "
		 << intVect.at(intVect.getFront()) << endl;
	cout << "REAR : " << intVect.getRear() << " - "
		 << intVect.at(intVect.getRear()) << endl;
	cout << endl;

	// PROC/OUT -- outputs whether or not vector is empty
	cout << (intVect.empty()?"INTEGER VECTOR IS EMPTY":
			"INTEGER VECTOR IS NOT EMPTY") << endl;
	cout << endl;

	// OUTPUT -- outputs how many integers are in the list
	cout << "There are " << intVect.size() << " integers in the vector" << endl;

	return 0;
}

